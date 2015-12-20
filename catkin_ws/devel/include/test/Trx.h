// Generated by gencpp from file test/Trx.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_TRX_H
#define TEST_MESSAGE_TRX_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test
{
template <class ContainerAllocator>
struct Trx_
{
  typedef Trx_<ContainerAllocator> Type;

  Trx_()
    : name()
    , userID()
    , isExist(0)
    , keep(0)
    , drink(0)  {
    }
  Trx_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , userID(_alloc)
    , isExist(0)
    , keep(0)
    , drink(0)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _userID_type;
  _userID_type userID;

   typedef int32_t _isExist_type;
  _isExist_type isExist;

   typedef int32_t _keep_type;
  _keep_type keep;

   typedef int32_t _drink_type;
  _drink_type drink;




  typedef boost::shared_ptr< ::test::Trx_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::Trx_<ContainerAllocator> const> ConstPtr;

}; // struct Trx_

typedef ::test::Trx_<std::allocator<void> > Trx;

typedef boost::shared_ptr< ::test::Trx > TrxPtr;
typedef boost::shared_ptr< ::test::Trx const> TrxConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::Trx_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::Trx_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'test': ['/home/human/catkin_ws/src/test/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test::Trx_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::Trx_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::Trx_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::Trx_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::Trx_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::Trx_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::Trx_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a2b29f64e52e4a0aea1b9be454c66754";
  }

  static const char* value(const ::test::Trx_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa2b29f64e52e4a0aULL;
  static const uint64_t static_value2 = 0xea1b9be454c66754ULL;
};

template<class ContainerAllocator>
struct DataType< ::test::Trx_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/Trx";
  }

  static const char* value(const ::test::Trx_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::Trx_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
string userID\n\
int32 isExist\n\
int32 keep\n\
int32 drink\n\
";
  }

  static const char* value(const ::test::Trx_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::Trx_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.userID);
      stream.next(m.isExist);
      stream.next(m.keep);
      stream.next(m.drink);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Trx_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::Trx_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::Trx_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "userID: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.userID);
    s << indent << "isExist: ";
    Printer<int32_t>::stream(s, indent + "  ", v.isExist);
    s << indent << "keep: ";
    Printer<int32_t>::stream(s, indent + "  ", v.keep);
    s << indent << "drink: ";
    Printer<int32_t>::stream(s, indent + "  ", v.drink);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_TRX_H