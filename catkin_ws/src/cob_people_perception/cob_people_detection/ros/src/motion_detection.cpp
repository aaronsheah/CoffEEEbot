
#ifdef __LINUX__
#include "cob_people_detection/face_detector_node.h"
#include "cob_vision_utils/GlobalDefines.h"
#else
#endif

// OpenCV
#include "opencv/cv.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

// Boost
#include <boost/shared_ptr.hpp>

// timer
#include <cob_people_detection/timer.h>

#include <ros/ros.h>
#include <stdio.h>


const int bufferSize = 1000;

class Joy2Vel{
private:
    ros::Subscriber headposition_;
public:
    Joy2Vel(ros::NodeHandle& n){
	headposition_ = n.subscribe("/cob_people_detection/head_detector/head_positions", 1, &Joy2Vel::callback_head, this);
    }

    void callback_head(const cob_perception_msgs::ColorDepthImageArray::ConstPtr& head_positions){
	int x, y;

	x = head_positions->head_detections[0].head_detection.x;
	y = head_positions->head_detections[0].head_detection.y;

	printf("x = %d\ny = %d\n", x, y);
    }

};

int main(int argc, char** argv){
    ros::init(argc, argv, "joy2vel");
    ros::NodeHandle n;

    Joy2Vel node(n);
    ROS_INFO("Node started");
    ros::spin();
    return 0;
}
