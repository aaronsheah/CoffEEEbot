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

# Utility rule file for pocketsphinx_generate_messages.

# Include the progress variables for this target.
include pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/progress.make

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages:

pocketsphinx_generate_messages: pocketsphinx/CMakeFiles/pocketsphinx_generate_messages
pocketsphinx_generate_messages: pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/build.make
.PHONY : pocketsphinx_generate_messages

# Rule to build all files generated by this target.
pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/build: pocketsphinx_generate_messages
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/build

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/clean:
	cd /home/human/catkin_ws/build/pocketsphinx && $(CMAKE_COMMAND) -P CMakeFiles/pocketsphinx_generate_messages.dir/cmake_clean.cmake
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/clean

pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/depend:
	cd /home/human/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/human/catkin_ws/src /home/human/catkin_ws/src/pocketsphinx /home/human/catkin_ws/build /home/human/catkin_ws/build/pocketsphinx /home/human/catkin_ws/build/pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pocketsphinx/CMakeFiles/pocketsphinx_generate_messages.dir/depend

