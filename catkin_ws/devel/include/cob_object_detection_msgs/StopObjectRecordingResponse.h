// Generated by gencpp from file cob_object_detection_msgs/StopObjectRecordingResponse.msg
// DO NOT EDIT!


#ifndef COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDINGRESPONSE_H
#define COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDINGRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cob_object_detection_msgs
{
template <class ContainerAllocator>
struct StopObjectRecordingResponse_
{
  typedef StopObjectRecordingResponse_<ContainerAllocator> Type;

  StopObjectRecordingResponse_()
    : recording_stopped(false)  {
    }
  StopObjectRecordingResponse_(const ContainerAllocator& _alloc)
    : recording_stopped(false)  {
    }



   typedef uint8_t _recording_stopped_type;
  _recording_stopped_type recording_stopped;




  typedef boost::shared_ptr< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> const> ConstPtr;

}; // struct StopObjectRecordingResponse_

typedef ::cob_object_detection_msgs::StopObjectRecordingResponse_<std::allocator<void> > StopObjectRecordingResponse;

typedef boost::shared_ptr< ::cob_object_detection_msgs::StopObjectRecordingResponse > StopObjectRecordingResponsePtr;
typedef boost::shared_ptr< ::cob_object_detection_msgs::StopObjectRecordingResponse const> StopObjectRecordingResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cob_object_detection_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cob_object_detection_msgs': ['/home/human/catkin_ws/devel/share/cob_object_detection_msgs/msg', '/home/human/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6c4ef6fc8891dd138a543e6ac4a818da";
  }

  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6c4ef6fc8891dd13ULL;
  static const uint64_t static_value2 = 0x8a543e6ac4a818daULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_object_detection_msgs/StopObjectRecordingResponse";
  }

  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
bool recording_stopped\n\
\n\
";
  }

  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.recording_stopped);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct StopObjectRecordingResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_object_detection_msgs::StopObjectRecordingResponse_<ContainerAllocator>& v)
  {
    s << indent << "recording_stopped: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.recording_stopped);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDINGRESPONSE_H