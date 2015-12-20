cmake_minimum_required(VERSION 2.8.3)
project(test)

find_package(catkin REQUIRED COMPONENTS
	std_msgs
	message_generation)

catkin_python_setup()

add_message_files(
	FILES
	RecMsgStruc.msg
	Trx.msg
)


generate_messages(
	DEPENDENCIES
	std_msgs
)


catkin_package(
	CATKIN_DEPENDS message_runtime
)
