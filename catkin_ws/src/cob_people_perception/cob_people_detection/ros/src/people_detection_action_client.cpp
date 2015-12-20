/****************************************************************
 *
 * Copyright (c) 2010
 *
 * Fraunhofer Institute for Manufacturing Engineering
 * and Automation (IPA)
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Project name: care-o-bot
 * ROS stack name: cob_vision
 * ROS package name: cob_people_detection
 * Description:
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Author: Richard Bormann, email:richard.bormann@ipa.fhg.de
 * Supervised by:
 *
 * Date of creation: 03/2011
 * ToDo:
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Fraunhofer Institute for Manufacturing
 *       Engineering and Automation (IPA) nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

//##################
//#### includes ####

#include <stdio.h>
#include <string>
#include <sstream>

// ROS includes
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <p2os_msgs/MotorState.h>

// Actions
#include <actionlib/client/simple_action_client.h>
#include <cob_people_detection/addDataAction.h>
#include <cob_people_detection/updateDataAction.h>
#include <cob_people_detection/deleteDataAction.h>
#include <cob_people_detection/loadModelAction.h>
#include <cob_people_detection/getDetectionsAction.h>

// services
#include <cob_people_detection/captureImage.h>
#include <cob_people_detection/finishRecording.h>
#include <cob_people_detection/recognitionTrigger.h>
#include <std_srvs/Empty.h>
#include <p2os_msgs/GripperState.h>

// standard includes
#ifdef __LINUX__
#include <termios.h>

const int bufferSize=1000;
bool recognised=false;	
bool newUserAdded=false;
bool recording=false;
bool existingCustomer=true;
bool idPublished=false;
int userID=0;
int recognisedUserID = 0;
int publishedID=0;
std::string face_str = "Unknown";
std::string head_str = "UnknownHead";
std::string state = "Idle";
double curRot = 0;

// Robot movement parameters
const double translationalVel = 0.5;
const double rotationalVel = -2*M_PI/10; //rad/s

int getch();

int getch()
{
	static int ch = -1, fd = 0;
	struct termios neu, alt;
	fd = fileno(stdin);
	tcgetattr(fd, &alt);
	neu = alt;
	neu.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(fd, TCSANOW, &neu);
	ch = getchar();
	tcsetattr(fd, TCSANOW, &alt);
	return ch;
}
#endif

//####################
//#### node class ####

typedef actionlib::SimpleActionClient<cob_people_detection::addDataAction> AddDataClient;
typedef actionlib::SimpleActionClient<cob_people_detection::updateDataAction> UpdateDataClient;
typedef actionlib::SimpleActionClient<cob_people_detection::deleteDataAction> DeleteDataClient;
typedef actionlib::SimpleActionClient<cob_people_detection::loadModelAction> LoadModelClient;
typedef actionlib::SimpleActionClient<cob_people_detection::getDetectionsAction> GetDetectionsClient;

void addData(AddDataClient& add_data_client, ros::ServiceClient& capture_image_client, ros::ServiceClient& finish_recording_client)
{
	int imageNum=40;
	float delayTime=0.01;
	std::stringstream ss;
	userID++;
	cob_people_detection::addDataGoal goal;
	
	//std::cout << "Input the label of the captured person: ";
	ss<<userID;
	goal.label=ss.str();//id is determined automatically

	//std::cout << "Mode of data capture: 0=manual, 1=continuous: ";
	goal.capture_mode=1;//capture mode is default to be continuous

	if (goal.capture_mode == 1)
	{
		//std::cout << "How many images shall be captured automatically? ";
		goal.continuous_mode_images_to_capture=imageNum;

		//std::cout << "What is the desired delay time in seconds between two recordings? ";
		goal.continuous_mode_delay=delayTime;
	}

	// send goal to server
	add_data_client.sendGoal(goal);
	std::cout << "Recording job was sent to the server ..." << std::endl;

	// enable control in manual mode
	if (goal.capture_mode == 0)
	{
		// wait for server to provide the capture and finish service
		std::cout << "Waiting for the capture service to become available ..." << std::endl;
		capture_image_client.waitForExistence();
		finish_recording_client.waitForExistence();

		// capture
		std::cout << "Hit 'q' key to quit or 'c' key to capture an image.\n";
		cob_people_detection::captureImageRequest capture_image_request;
		cob_people_detection::captureImageResponse capture_image_response;
		char key;
		while ((key = getch()) != 'q')
		{
			if (key == 'c')
			{
				printf("Image capture initiated ... \n");
				if (capture_image_client.call(capture_image_request, capture_image_response) == true)
					printf("   image %d successfully captured.\n", capture_image_response.number_captured_images);
				else
					printf("   image capture not successful.\n");
			}
		}

		printf("Finishing recording ...\n");

		// tell server to finish recording
		cob_people_detection::finishRecording finish_recording;
		finish_recording_client.call(finish_recording);
	}

	add_data_client.waitForResult();

	if (add_data_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		printf("Data recording finished successfully.\n");
	else
		printf("Data recording did not finish successfully.\n");

	printf("Current State: %s   Message: %s\n", add_data_client.getState().toString().c_str(), add_data_client.getState().getText().c_str());
}

void updateData(UpdateDataClient& update_data_client)
{
	cob_people_detection::updateDataGoal goal;

	std::cout << "Choose a mode for data update: 1=by index (changes exactly one entry), 2=by label (changes all entries with that label): ";
	std::cin >> goal.update_mode;

	if (goal.update_mode == 1)
	{
		std::cout << "Enter the index of the database entry that shall be updated: ";
		std::cin >> goal.update_index;
	}
	else if (goal.update_mode == 2)
	{
		std::cout << "Enter the label of the database entries that shall be updated: ";
		std::cin >> goal.old_label;
	}
	else
	{
		std::cout << "Error: updateData: Wrong update_mode." << std::endl;
		return;
	}

	std::cout << "Enter the new label that shall be assigned to the chosen data: ";
	std::cin >> goal.new_label;

	// send goal to server
	update_data_client.sendGoal(goal);
	std::cout << "Update job was sent to the server ..." << std::endl;
	update_data_client.waitForResult();

	if (update_data_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		printf("Data update finished successfully.\n");
	else
		printf("Data update did not finish successfully.\n");

	printf("Current State: %s   Message: %s\n", update_data_client.getState().toString().c_str(), update_data_client.getState().getText().c_str());
}

void deleteData(DeleteDataClient& delete_data_client)
{
	cob_people_detection::deleteDataGoal goal;

	//std::cout << "Choose a mode for data deletion: 1=by index (deletes exactly one entry), 2=by label (deletes all entries with that label): ";
	goal.delete_mode = 2;

	if (goal.delete_mode == 1)
	{
		std::cout << "Enter the index of the database entry that shall be deleted: ";
		std::cin >> goal.delete_index;
	}
	else if (goal.delete_mode == 2)
	{
		//std::cout << "Enter the label of the database entries that shall be deleted: ";
		//std::cin>>goal.label;
		
		if(recognised){
			std::stringstream ss;
			ss<<publishedID;
			goal.label=ss.str();
		}
		else if(newUserAdded){
			std::stringstream ss;
			ss<<publishedID;
			goal.label=ss.str();
			userID--;		
		}
		
	}
	else
	{
		std::cout << "Error: deleteData: Wrong delete_mode." << std::endl;
		return;
	}

	// send goal to server
	delete_data_client.sendGoal(goal);
	std::cout << "Delete job was sent to the server ..." << std::endl;
	delete_data_client.waitForResult();

	if (delete_data_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		printf("Data deletion finished successfully.\n");
	else
		printf("Data deletion did not finish successfully.\n");

	printf("Current State: %s   Message: %s\n", delete_data_client.getState().toString().c_str(), delete_data_client.getState().getText().c_str());
}

void loadRecognitionModel(LoadModelClient& load_model_client)
{
	cob_people_detection::loadModelGoal goal;

	//std::cout << "Enter the labels that should occur in the recognition model. By sending an empty list, all available data will be used." << std::endl;
	while (true)
	{
		//std::cout << "Enter label (finish by entering 'q'): ";
		std::string label;
		label = "q";

		if (label.compare("q") == 0)
			break;
		else
			goal.labels.push_back(label);
	}

	// send goal to server
	load_model_client.sendGoal(goal);
	std::cout << "Recognition model is loaded by the server ..." << std::endl;
	std::cout << "\nA new recognition model is currently loaded or generated by the server. The following labels will be covered: " << std::endl;
	for (int i = 0; i < (int)goal.labels.size(); i++)
		std::cout << "   - " << goal.labels[i] << std::endl;

	load_model_client.waitForResult();

	if (load_model_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		printf("The new recognition model has been successfully loaded.\n");
	else
		printf("Loading a new recognition model was not successful.\n");

	printf("Current State: %s   Message: %s\n", load_model_client.getState().toString().c_str(), load_model_client.getState().getText().c_str());
}

void activateSensorMessageGateway(ros::ServiceClient& sensor_message_gateway_open_client, ros::ServiceClient& sensor_message_gateway_close_client)
{
	int open_close = 0;
	std::cout << "Type 1 to activate or 2 to deactivate the sensor message gateway: ";
	std::cin >> open_close;

	if (open_close == 1)
	{
		// activate
		cob_people_detection::recognitionTriggerRequest req;
		cob_people_detection::recognitionTriggerResponse res;
		std::cout << "At which target frame rate (Hz) shall the sensor message gateway operate: ";
		std::cin >> req.target_frame_rate;

		if (sensor_message_gateway_open_client.call(req, res) == true)
			printf("Gateway successfully opened.\n");
		else
			printf("Opening gateway was not successful.\n");
	}
	else if (open_close == 2)
	{
		// deactivate
		std_srvs::Empty rec;
		if (sensor_message_gateway_close_client.call(rec) == true)
			printf("Gateway successfully closed.\n");
		else
			printf("Closing gateway was not successful.\n");
	}
}

void getDetections(GetDetectionsClient& get_detections_client)
{
	cob_people_detection::getDetectionsGoal goal;

	std::cout << "Enter a maximum age of the detection message (in seconds): ";
	std::cin >> goal.maximum_message_age;

	std::cout << "Enter the maximum waiting time to receive the message (in seconds): ";
	std::cin >> goal.timeout;

	// send goal to server
	get_detections_client.sendGoal(goal);
	std::cout << "Waiting for the server to send the detections ..." << std::endl;
	get_detections_client.waitForResult();

	if (get_detections_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
	{
		cob_people_detection::getDetectionsResultConstPtr result = get_detections_client.getResult();
		std::cout << "Received a detection message with " << result->detections.detections.size() << " detections.\nThe labels are" << std::endl;
		for (int i = 0; i < (int)result->detections.detections.size(); i++)
			std::cout << "   - " << result->detections.detections[i].label << std::endl;
	}
	else
		std::cout << "No detections received.\n";

	printf("Current State: %s   Message: %s\n", get_detections_client.getState().toString().c_str(), get_detections_client.getState().getText().c_str());
}

class Updater{
	private:
	ros::Publisher HeadLabel_;
	ros::Publisher FaceLabel_;
	ros::Publisher userPresent_;
	ros::Publisher userRecognised_;
	ros::Publisher userRecording_;
	ros::Publisher motorPub_;
	ros::Publisher velPub_;
	ros::Subscriber returnCustomer_;
	ros::Subscriber deleteUserInfo_;
	ros::Subscriber headTracker_;
	ros::Subscriber waiting_;
	ros::Subscriber faceDetector_;
	ros::ServiceClient capture_image_client;
	ros::ServiceClient finish_recording_client;

	ros::Subscriber lifts_;
	ros::Publisher 	liftp_;

	public:
	Updater(ros::NodeHandle& nh){

		liftp_=nh.advertise<p2os_msgs::GripperState>("/gripper_control",bufferSize);
		lifts_=nh.subscribe("/lift",bufferSize,&Updater::lift,this);

		HeadLabel_=nh.advertise<std_msgs::String>("/userID",bufferSize);
		FaceLabel_=nh.advertise<std_msgs::String>("/faceLabel",bufferSize);
		userPresent_=nh.advertise<std_msgs::Int32>("/userPresent",bufferSize);
		userRecognised_=nh.advertise<std_msgs::Int32>("/userRecognised",bufferSize);
		userRecording_=nh.advertise<std_msgs::Int32>("/userRecording",bufferSize);
		motorPub_ = nh.advertise<p2os_msgs::MotorState>("/cmd_motor_state", bufferSize);
		velPub_ = nh.advertise<geometry_msgs::Twist>("/cmd_vel", bufferSize);
		headTracker_=nh.subscribe("/cob_people_detection/detection_tracker/face_position_array",bufferSize,&Updater::headTracker,this);
		faceDetector_=nh.subscribe("/cob_people_detection/face_recognizer/face_recognitions",bufferSize,&Updater::faceDetecter,this);
		returnCustomer_=nh.subscribe("/existingCustomer",bufferSize,&Updater::returnCustomer,this);
		waiting_=nh.subscribe("/idleState",bufferSize,&Updater::waiting,this);
		deleteUserInfo_=nh.subscribe("/deleteUserInfo",bufferSize,&Updater::deleteUserInfo,this);
		capture_image_client = nh.serviceClient<cob_people_detection::captureImage>("/cob_people_detection/face_capture/capture_image");
		finish_recording_client=nh.serviceClient<cob_people_detection::finishRecording>("/cob_people_detection/face_capture/finish_recording");	
	}

	void returnCustomer(std_msgs::Int32 returnC_){
		std::cout << "returnCustomer updated\n";
		std_msgs::Int32 msg;
		p2os_msgs::MotorState motor_state;
		motor_state.state = 0;
		motorPub_.publish(motor_state);
		std_msgs::String label_;
		idPublished=false;
		std::stringstream ss;
		AddDataClient	add_data_client("/cob_people_detection/face_capture/add_data_server", true);
		LoadModelClient load_model_client("/cob_people_detection/face_recognizer/load_model_server", true);
		std::cout<<"Recognised: "<<recognised;

		state = "Active";
		if(returnC_.data==0){
			
			//publish ID
			publishedID=userID+1;
			ss<<userID+1;
			ss>>label_.data;
			HeadLabel_.publish(label_);
			idPublished=true;

			existingCustomer=false;
			std::cout << "User not recognized! Adding to database\n";
			msg.data=1;
			userRecording_.publish(msg);
			recording=true;
			addData(add_data_client, capture_image_client, finish_recording_client);
			recording=false;
			newUserAdded=true;
			msg.data=0;
			userRecording_.publish(msg);
			loadRecognitionModel(load_model_client);
		}
		else{
			existingCustomer=true;	
		}
	}

	void deleteUserInfo(std_msgs::Int32 deleteUserInfo){
		std::cout << "DeleteUserInfo updated\n";
		DeleteDataClient delete_data_client("/cob_people_detection/face_capture/delete_data_server", true);
		LoadModelClient load_model_client("/cob_people_detection/face_recognizer/load_model_server", true);
		if(deleteUserInfo.data==1&&recognised&&!recording){
			std::cout<<"Start to delete user info";
			deleteData(delete_data_client);
			std::cout<<"User info deleted.";
			loadRecognitionModel(load_model_client);
		}	
	}
	
	void headTracker(cob_perception_msgs::DetectionArray msg){
		std_msgs::String label_;
		label_.data="UnknownHead";
		std::stringstream ss;
		std_msgs::Int32 recognised_;
		recognised_.data=0;
		if(msg.detections.size()>0){
			label_.data=msg.detections[0].label;
			head_str=msg.detections[0].label;
			if(head_str.compare("UnknownHead")){
				recognised_.data=1;
			}
		}
		if(state=="Idle"){
			if(existingCustomer){
				userRecognised_.publish(recognised_);	
			}
			else{
				recognised_.data=0;
				userRecognised_.publish(recognised_);
			}
			
		}
		if(existingCustomer){
			if(!idPublished&&label_.data!="UnknownHead"){
				ss<<label_.data;
				ss>>publishedID;
				HeadLabel_.publish(label_);
				idPublished=true;
			}
		}			
	}
	
	void faceDetecter(cob_perception_msgs::DetectionArray msg){
		std::string det = " ";
		if(msg.detections.size()>0)
			det = msg.detections[0].detector;
		std_msgs::Int32 present_;
		std_msgs::String label_;
		present_.data=0;
		
		if(state == "Idle"){
			if(msg.detections.size()>0){
				present_.data=1;
				if(det.compare("face")==0){
					face_str=msg.detections[0].label;
					if(face_str.compare("UnknownHead")!=0)
						recognised=true;
					label_.data=face_str;
					if(msg.detections[0].pose.pose.position.z < 0.8)
						FaceLabel_.publish(label_);
				}
				if(msg.detections[0].pose.pose.position.z < 1.8 && msg.detections[0].pose.pose.position.z > 0.6)
				{
					geometry_msgs::Twist motor_msg;
					p2os_msgs::MotorState motor_state;
					motor_state.state = 1;
					double z_angle = rotationalVel * msg.detections[0].pose.pose.position.x;
					if(z_angle > 0.05 || z_angle < -0.05)
					{
						motor_msg.angular.z = z_angle;
						curRot += z_angle;
						if(motor_msg.angular.z > 0.2)
							motor_msg.angular.z = 0.2;
						else if(motor_msg.angular.z < -0.2)
							motor_msg.angular.z = -0.2;
						if((curRot < 0.3) && (curRot > -0.3))
						{
							motorPub_.publish(motor_state);
							velPub_.publish(motor_msg);
						}
						else
							if(curRot >= 0.3)
								curRot = 0.3;
							else if(curRot <= -0.3)
								curRot = -0.3;
					}
				}
			}
			userPresent_.publish(present_);
		}
	}
	void waiting(std_msgs::Int32 idle){
		if(idle.data==1&&state=="Active"){
			recognised = false;
			face_str = "Unknown";
			head_str = "UnknownHead";
			state = "Idle";		
		}
	}
	void lift(std_msgs::Float32 msg){
		p2os_msgs::GripperState m;
		m.lift.state=4;
		m.lift.dir=1;
		m.lift.position=msg.data;
		liftp_.publish(m);	
	}
};


int main(int argc, char** argv)
{
	std::cin>>userID;
	ros::init(argc, argv, "cob_people_detection_client");

	ros::NodeHandle nh;

	AddDataClient add_data_client("/cob_people_detection/face_capture/add_data_server", true); // true -> don't need ros::spin()
	ros::ServiceClient capture_image_client = nh.serviceClient<cob_people_detection::captureImage>("/cob_people_detection/face_capture/capture_image");
	ros::ServiceClient finish_recording_client = nh.serviceClient<cob_people_detection::finishRecording>("/cob_people_detection/face_capture/finish_recording");
	UpdateDataClient update_data_client("/cob_people_detection/face_capture/update_data_server", true);
	DeleteDataClient delete_data_client("/cob_people_detection/face_capture/delete_data_server", true);
	LoadModelClient load_model_client("/cob_people_detection/face_recognizer/load_model_server", true);
	GetDetectionsClient get_detections_client("/cob_people_detection/coordinator/get_detections_server", true);
	ros::ServiceClient sensor_message_gateway_open_client = nh.serviceClient<cob_people_detection::recognitionTrigger>("/cob_people_detection/coordinator/start_recognition");
	ros::ServiceClient sensor_message_gateway_close_client = nh.serviceClient<std_srvs::Empty>("/cob_people_detection/coordinator/stop_recognition");

	if (!add_data_client.waitForServer(ros::Duration(2.0)))
	{
		std::cout << "No connection to server 'add_data_server'.\n";
		return 0;
	}
	if (!update_data_client.waitForServer(ros::Duration(2.0)))
	{
		std::cout << "No connection to server 'update_data_server'.\n";
		return 0;
	}
	if (!delete_data_client.waitForServer(ros::Duration(2.0)))
	{
		std::cout << "No connection to server 'delete_data_server'.\n";
		return 0;
	}
	if (!load_model_client.waitForServer(ros::Duration(2.0)))
	{
		std::cout << "No connection to server 'load_model_server'.\n";
		return 0;
	}
	if (!get_detections_client.waitForServer(ros::Duration(2.0)))
	{
		std::cout << "No connection to server 'get_detections_server'.\n";
		return 0;
	}

	std::cout << "Connected to servers.\n";
	Updater node(nh);
	std::cout << "Updater node created.\n";

	char key = 'q';
	do
	{
		std::cout
				<< "\n\nChoose an option:\n1 - capture face images\n2 - update database labels\n3 - delete database entries\n4 - load recognition model (necessary if new images/persons were added to the database)\n5 - activate/deactivate sensor message gateway\n6 - get detections\nq - Quit\n\n";
		key = getch();
		if (key == '1')
			addData(add_data_client, capture_image_client, finish_recording_client);//train(trainContinuousClient, trainCaptureSampleClient);
		else if (key == '2')
			updateData(update_data_client);//recognize(recognizeClient);
		else if (key == '3')
			deleteData(delete_data_client);//train_continuous(trainContinuousClient, trainCaptureSampleClient);
		else if (key == '4')
			loadRecognitionModel(load_model_client);//show(showClient, 0);
		else if (key == '5')
			activateSensorMessageGateway(sensor_message_gateway_open_client, sensor_message_gateway_close_client);//show(showClient, 1);
		else if (key == '6')
			getDetections(get_detections_client);
	} while (key != 'q');


	ros::spin();
	return 0;
}

