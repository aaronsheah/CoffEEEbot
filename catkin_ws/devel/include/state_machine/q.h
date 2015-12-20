// Generated by gencpp from file state_machine/q.msg
// DO NOT EDIT!


#ifndef STATE_MACHINE_MESSAGE_Q_H
#define STATE_MACHINE_MESSAGE_Q_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace state_machine
{
template <class ContainerAllocator>
struct q_
{
  typedef q_<ContainerAllocator> Type;

  q_()
    : dialogue()
    , ans(0)
    , stock(0)  {
    }
  q_(const ContainerAllocator& _alloc)
    : dialogue(_alloc)
    , ans(0)
    , stock(0)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dialogue_type;
  _dialogue_type dialogue;

   typedef int32_t _ans_type;
  _ans_type ans;

   typedef int32_t _stock_type;
  _stock_type stock;




  typedef boost::shared_ptr< ::state_machine::q_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::state_machine::q_<ContainerAllocator> const> ConstPtr;

}; // struct q_

typedef ::state_machine::q_<std::allocator<void> > q;

typedef boost::shared_ptr< ::state_machine::q > qPtr;
typedef boost::shared_ptr< ::state_machine::q const> qConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::state_machine::q_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::state_machine::q_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace state_machine

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'state_machine': ['/home/human/catkin_ws/src/state_machine/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::state_machine::q_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::state_machine::q_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::state_machine::q_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::state_machine::q_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::state_machine::q_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::state_machine::q_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::state_machine::q_<ContainerAllocator> >
{
  static const char* value()
  {
    return "585ea6598299f8e066244f262bd13943";
  }

  static const char* value(const ::state_machine::q_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x585ea6598299f8e0ULL;
  static const uint64_t static_value2 = 0x66244f262bd13943ULL;
};

template<class ContainerAllocator>
struct DataType< ::state_machine::q_<ContainerAllocator> >
{
  static const char* value()
  {
    return "state_machine/q";
  }

  static const char* value(const ::state_machine::q_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::state_machine::q_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string dialogue\n\
int32 ans\n\
int32 stock\n\
";
  }

  static const char* value(const ::state_machine::q_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::state_machine::q_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dialogue);
      stream.next(m.ans);
      stream.next(m.stock);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct q_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::state_machine::q_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::state_machine::q_<ContainerAllocator>& v)
  {
    s << indent << "dialogue: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dialogue);
    s << indent << "ans: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ans);
    s << indent << "stock: ";
    Printer<int32_t>::stream(s, indent + "  ", v.stock);
  }
};

} // namespace message_operations
} // namespace ros

#endif // STATE_MACHINE_MESSAGE_Q_H
