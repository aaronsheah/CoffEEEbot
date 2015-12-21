#Introduction
CoffEEEbot is a robot built to test the hypothesis of whether a more interactive coffee machine would lead to more sales. This robot is built as part of the Human Centred Robotics course taught by Dr Yiannis at Imperial College London.
This README will show the setup and running process for the software components of the CoffEEEbot.
##Dialogue Management (steps to setup)
###Requirements 
####ROS Sound Drivers

	sudo apt-get install ros-indigo-sound-drivers

####CMU Speech

	sudo apt-get install festlex-cmu
	cd /usr/share/festival/voices/english/
	sudo wget -c http://www.speech.cs.cmu.edu/cmu_arctic/packed/cmu_us_slt_arctic-0.95-release.tar.bz2
	sudo tar jxf cmu_us_slt_arctic-0.95-release.tar.bz2
	sudo rm cmu_us_slt_arctic-0.95-release.tar.bz2
	sudo ln -s cmu_us_slt_arctic cmu_us_slt_arctic_clunits

###Run 
####State Machine

	roslaunch state_machine state_machine.launch

####Play text to voice
	
	roslaunch sound_play sound.launch
	
##Speech recognition
###Setup (PocketSphinx)

	sudo apt-get install gstreamer0.10-pocketsphinx
	Sphinxbase-5prealpha

Go to <http://cmusphinx.sourceforge.net/wiki/download>. Then Download sphinxbase-5prealpha.
	
	sudo tar jxf sphinxbase-5prealpha.tar.bz2
	sudo rm sphinxbase-5prealpha.tar.bz2

###Run
	roslaunch pocketsphinx speech.launch

##Recommendation
###Setup

	sudo apt-get install python-numpy
	sudo apt-get install python-pandas
	sudo apt-get install python-sklearn
	sudo apt-get install python-psycopg2

###Run

	rosrun recommender recommender_node.py

##Computer Vision

##iPad App
###Requirements
####rosbridge_suite

	sudo apt-get install ros-indigo-rosbridge_suite

####Xcode and iPad with iOS 9.2

###Run
On ROS hardware : 

	rosrun rosbridge_server rosbridge_websocket

To run the application, first open the Xcode project. Then run the code on a iPad with iOS 9.2 or above. Then on an ubuntu machine type into terminal to find the IP address:

	hostname -I

Input the IP address displayed in terminal onto the text field in the application on iPad

##Database
Set up database

	sudo apt-get install postgresql postgresql-contrib
	sudo -u postgres createuser --superuser human
	sudo -u postgres createdb coffeeebot_trx
	psql

Transaction Table

	CREATE TABLE trx (
	userID int NOT NULL,
	timestamp timestamp DEFAULT now(),
	drink text NOT NULL);

Drinks Table
	
	CREATE TABLE 
	drinks (
	drink text NOT NULL,
	sweetness int NOT NULL,
	caffeinated bool NOT NULL,
	milk bool NOT NULL,
	tea bool NOT NULL,
	strength int NOT NULL);

	INSERT INTO drinks VALUES 
	(‘Cappuccino’, 3, True, True, False, 3),
	(‘Cafe Au Lait’, 2, True, True, False, 5),
	(‘Caramel Latte Macrchiato’, 5, True, True, False, 4),
	(‘Tea Latte’, 4, True, True, True, 2),
	(‘Lungo Decaf’, 1, False, False, False, 1);

	// User Table
	CREATE TABLE users (
	userID int NOT NULL,
	name text NOT NULL);
