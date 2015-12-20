# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "state_machine: 4 messages, 0 services")

set(MSG_I_FLAGS "-Istate_machine:/home/human/catkin_ws/src/state_machine/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(state_machine_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg" NAME_WE)
add_custom_target(_state_machine_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "state_machine" "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg" ""
)

get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg" NAME_WE)
add_custom_target(_state_machine_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "state_machine" "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg" ""
)

get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/Trx.msg" NAME_WE)
add_custom_target(_state_machine_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "state_machine" "/home/human/catkin_ws/src/state_machine/msg/Trx.msg" ""
)

get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/q.msg" NAME_WE)
add_custom_target(_state_machine_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "state_machine" "/home/human/catkin_ws/src/state_machine/msg/q.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
)
_generate_msg_cpp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
)
_generate_msg_cpp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
)
_generate_msg_cpp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/q.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
)

### Generating Services

### Generating Module File
_generate_module_cpp(state_machine
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(state_machine_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_cpp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_cpp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/Trx.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_cpp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/q.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_cpp _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_gencpp)
add_dependencies(state_machine_gencpp state_machine_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
)
_generate_msg_lisp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
)
_generate_msg_lisp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
)
_generate_msg_lisp(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/q.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
)

### Generating Services

### Generating Module File
_generate_module_lisp(state_machine
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(state_machine_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_lisp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_lisp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/Trx.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_lisp _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/q.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_lisp _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_genlisp)
add_dependencies(state_machine_genlisp state_machine_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
)
_generate_msg_py(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
)
_generate_msg_py(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
)
_generate_msg_py(state_machine
  "/home/human/catkin_ws/src/state_machine/msg/q.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
)

### Generating Services

### Generating Module File
_generate_module_py(state_machine
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(state_machine_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(state_machine_generate_messages state_machine_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/question_msg.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_py _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_py _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/Trx.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_py _state_machine_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/state_machine/msg/q.msg" NAME_WE)
add_dependencies(state_machine_generate_messages_py _state_machine_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(state_machine_genpy)
add_dependencies(state_machine_genpy state_machine_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS state_machine_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/state_machine
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(state_machine_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/state_machine
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(state_machine_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/state_machine
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(state_machine_generate_messages_py std_msgs_generate_messages_py)
