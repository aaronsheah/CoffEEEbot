# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/human/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/human/catkin_ws/build

# Utility rule file for pocketsphinx_generate_messages_cpp.

# Include the progress variables for this target.
include pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/progress.make

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp: /home/human/catkin_ws/devel/include/pocketsphinx/question_msg.h

/home/human/catkin_ws/devel/include/pocketsphinx/question_msg.h: /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py
/home/human/catkin_ws/devel/include/pocketsphinx/question_msg.h: /home/human/catkin_ws/src/pocketsphinx/msg/question_msg.msg
/home/human/catkin_ws/devel/include/pocketsphinx/question_msg.h: /opt/ros/indigo/share/gencpp/cmake/../msg.h.template
	$(CMAKE_COMMAND) -E cmake_progress_report /home/human/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating C++ code from pocketsphinx/question_msg.msg"
	cd /home/human/catkin_ws/build/pocketsphinx && ../catkin_generated/env_cached.sh /usr/bin/python /opt/ros/indigo/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/human/catkin_ws/src/pocketsphinx/msg/question_msg.msg -Ipocketsphinx:/home/human/catkin_ws/src/pocketsphinx/msg -Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg -p pocketsphinx -o /home/human/catkin_ws/devel/include/pocketsphinx -e /opt/ros/indigo/share/gencpp/cmake/..

pocketsphinx_generate_messages_cpp: pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp
pocketsphinx_generate_messages_cpp: /home/human/catkin_ws/devel/include/pocketsphinx/question_msg.h
pocketsphinx_generate_messages_cpp: pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/build.make
.PHONY : pocketsphinx_generate_messages_cpp

# Rule to build all files generated by this target.
pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/build: pocketsphinx_generate_messages_cpp
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/build

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/clean:
	cd /home/human/catkin_ws/build/pocketsphinx && $(CMAKE_COMMAND) -P CMakeFiles/pocketsphinx_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/clean

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/depend:
	cd /home/human/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/human/catkin_ws/src /home/human/catkin_ws/src/pocketsphinx /home/human/catkin_ws/build /home/human/catkin_ws/build/pocketsphinx /home/human/catkin_ws/build/pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages_cpp.dir/depend

