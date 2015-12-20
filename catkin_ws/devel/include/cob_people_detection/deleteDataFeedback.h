// Generated by gencpp from file cob_people_detection/deleteDataFeedback.msg
// DO NOT EDIT!


#ifndef COB_PEOPLE_DETECTION_MESSAGE_DELETEDATAFEEDBACK_H
#define COB_PEOPLE_DETECTION_MESSAGE_DELETEDATAFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cob_people_detection
{
template <class ContainerAllocator>
struct deleteDataFeedback_
{
  typedef deleteDataFeedback_<ContainerAllocator> Type;

  deleteDataFeedback_()
    {
    }
  deleteDataFeedback_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct deleteDataFeedback_

typedef ::cob_people_detection::deleteDataFeedback_<std::allocator<void> > deleteDataFeedback;

typedef boost::shared_ptr< ::cob_people_detection::deleteDataFeedback > deleteDataFeedbackPtr;
typedef boost::shared_ptr< ::cob_people_detection::deleteDataFeedback const> deleteDataFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cob_people_detection

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'stereo_msgs': ['/opt/ros/indigo/share/stereo_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'cob_perception_msgs': ['/home/human/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cob_people_detection': ['/home/human/catkin_ws/devel/share/cob_people_detection/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::cob_people_detection::deleteDataFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_people_detection/deleteDataFeedback";
  }

  static const char* value(const ::cob_people_detection::deleteDataFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# feedback message\n\
\n\
";
  }

  static const char* value(const ::cob_people_detection::deleteDataFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct deleteDataFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_people_detection::deleteDataFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::cob_people_detection::deleteDataFeedback_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // COB_PEOPLE_DETECTION_MESSAGE_DELETEDATAFEEDBACK_H
