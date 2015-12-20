// Generated by gencpp from file test/RecMsgStruc.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_RECMSGSTRUC_H
#define TEST_MESSAGE_RECMSGSTRUC_H


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
struct RecMsgStruc_
{
  typedef RecMsgStruc_<ContainerAllocator> Type;

  RecMsgStruc_()
    : Name()
    , userID()
    , isExist(0)
    , FirstRec(0)
    , FirstQ()
    , SecondRec(0)
    , SecondQ()
    , ThirdRec(0)
    , ThirdQ()
    , ForthRec(0)
    , FifthRec(0)  {
    }
  RecMsgStruc_(const ContainerAllocator& _alloc)
    : Name(_alloc)
    , userID(_alloc)
    , isExist(0)
    , FirstRec(0)
    , FirstQ(_alloc)
    , SecondRec(0)
    , SecondQ(_alloc)
    , ThirdRec(0)
    , ThirdQ(_alloc)
    , ForthRec(0)
    , FifthRec(0)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _Name_type;
  _Name_type Name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _userID_type;
  _userID_type userID;

   typedef int32_t _isExist_type;
  _isExist_type isExist;

   typedef int32_t _FirstRec_type;
  _FirstRec_type FirstRec;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _FirstQ_type;
  _FirstQ_type FirstQ;

   typedef int32_t _SecondRec_type;
  _SecondRec_type SecondRec;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _SecondQ_type;
  _SecondQ_type SecondQ;

   typedef int32_t _ThirdRec_type;
  _ThirdRec_type ThirdRec;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _ThirdQ_type;
  _ThirdQ_type ThirdQ;

   typedef int32_t _ForthRec_type;
  _ForthRec_type ForthRec;

   typedef int32_t _FifthRec_type;
  _FifthRec_type FifthRec;




  typedef boost::shared_ptr< ::test::RecMsgStruc_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::RecMsgStruc_<ContainerAllocator> const> ConstPtr;

}; // struct RecMsgStruc_

typedef ::test::RecMsgStruc_<std::allocator<void> > RecMsgStruc;

typedef boost::shared_ptr< ::test::RecMsgStruc > RecMsgStrucPtr;
typedef boost::shared_ptr< ::test::RecMsgStruc const> RecMsgStrucConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::RecMsgStruc_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::RecMsgStruc_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::test::RecMsgStruc_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::RecMsgStruc_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::RecMsgStruc_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::RecMsgStruc_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::RecMsgStruc_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::RecMsgStruc_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::RecMsgStruc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fb202545eccded8b9b08c3c358605781";
  }

  static const char* value(const ::test::RecMsgStruc_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfb202545eccded8bULL;
  static const uint64_t static_value2 = 0x9b08c3c358605781ULL;
};

template<class ContainerAllocator>
struct DataType< ::test::RecMsgStruc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/RecMsgStruc";
  }

  static const char* value(const ::test::RecMsgStruc_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::RecMsgStruc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string Name\n\
string userID\n\
int32 isExist\n\
int32 FirstRec\n\
string FirstQ\n\
int32 SecondRec\n\
string SecondQ\n\
int32 ThirdRec\n\
string ThirdQ\n\
int32 ForthRec\n\
int32 FifthRec\n\
";
  }

  static const char* value(const ::test::RecMsgStruc_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::RecMsgStruc_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Name);
      stream.next(m.userID);
      stream.next(m.isExist);
      stream.next(m.FirstRec);
      stream.next(m.FirstQ);
      stream.next(m.SecondRec);
      stream.next(m.SecondQ);
      stream.next(m.ThirdRec);
      stream.next(m.ThirdQ);
      stream.next(m.ForthRec);
      stream.next(m.FifthRec);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct RecMsgStruc_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::RecMsgStruc_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::RecMsgStruc_<ContainerAllocator>& v)
  {
    s << indent << "Name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.Name);
    s << indent << "userID: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.userID);
    s << indent << "isExist: ";
    Printer<int32_t>::stream(s, indent + "  ", v.isExist);
    s << indent << "FirstRec: ";
    Printer<int32_t>::stream(s, indent + "  ", v.FirstRec);
    s << indent << "FirstQ: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.FirstQ);
    s << indent << "SecondRec: ";
    Printer<int32_t>::stream(s, indent + "  ", v.SecondRec);
    s << indent << "SecondQ: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.SecondQ);
    s << indent << "ThirdRec: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ThirdRec);
    s << indent << "ThirdQ: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.ThirdQ);
    s << indent << "ForthRec: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ForthRec);
    s << indent << "FifthRec: ";
    Printer<int32_t>::stream(s, indent + "  ", v.FifthRec);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_RECMSGSTRUC_H
