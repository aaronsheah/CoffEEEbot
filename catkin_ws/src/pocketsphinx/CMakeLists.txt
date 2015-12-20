cmake_minimum_required(VERSION 2.8.3)
project(pocketsphinx)

find_package(catkin REQUIRED COMPONENTS
	std_msgs
	message_generation)

add_message_files(
	FILES
	question_msg.msg
)


generate_messages(
	DEPENDENCIES
	std_msgs
)

catkin_package(DEPENDS)

install(DIRECTORY demo
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(PROGRAMS nodes/recognizer.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(PROGRAMS nodes/voice_cmd_vel.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
