# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "recommender: 2 messages, 0 services")

set(MSG_I_FLAGS "-Irecommender:/home/human/catkin_ws/src/recommender/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(recommender_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg" NAME_WE)
add_custom_target(_recommender_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "recommender" "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg" ""
)

get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/Trx.msg" NAME_WE)
add_custom_target(_recommender_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "recommender" "/home/human/catkin_ws/src/recommender/msg/Trx.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(recommender
  "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recommender
)
_generate_msg_cpp(recommender
  "/home/human/catkin_ws/src/recommender/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recommender
)

### Generating Services

### Generating Module File
_generate_module_cpp(recommender
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recommender
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(recommender_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(recommender_generate_messages recommender_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(recommender_generate_messages_cpp _recommender_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/Trx.msg" NAME_WE)
add_dependencies(recommender_generate_messages_cpp _recommender_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recommender_gencpp)
add_dependencies(recommender_gencpp recommender_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recommender_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(recommender
  "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recommender
)
_generate_msg_lisp(recommender
  "/home/human/catkin_ws/src/recommender/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recommender
)

### Generating Services

### Generating Module File
_generate_module_lisp(recommender
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recommender
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(recommender_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(recommender_generate_messages recommender_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(recommender_generate_messages_lisp _recommender_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/Trx.msg" NAME_WE)
add_dependencies(recommender_generate_messages_lisp _recommender_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recommender_genlisp)
add_dependencies(recommender_genlisp recommender_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recommender_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(recommender
  "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender
)
_generate_msg_py(recommender
  "/home/human/catkin_ws/src/recommender/msg/Trx.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender
)

### Generating Services

### Generating Module File
_generate_module_py(recommender
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(recommender_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(recommender_generate_messages recommender_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/RecMsgStruc.msg" NAME_WE)
add_dependencies(recommender_generate_messages_py _recommender_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/human/catkin_ws/src/recommender/msg/Trx.msg" NAME_WE)
add_dependencies(recommender_generate_messages_py _recommender_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recommender_genpy)
add_dependencies(recommender_genpy recommender_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recommender_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recommender)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recommender
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(recommender_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recommender)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recommender
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(recommender_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recommender/.+/__init__.pyc?$"
  )
endif()
add_dependencies(recommender_generate_messages_py std_msgs_generate_messages_py)
