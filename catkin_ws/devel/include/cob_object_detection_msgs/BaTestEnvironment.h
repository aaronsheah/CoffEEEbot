// Generated by gencpp from file cob_object_detection_msgs/BaTestEnvironment.msg
// DO NOT EDIT!


#ifndef COB_OBJECT_DETECTION_MSGS_MESSAGE_BATESTENVIRONMENT_H
#define COB_OBJECT_DETECTION_MSGS_MESSAGE_BATESTENVIRONMENT_H

#include <ros/service_traits.h>


#include <cob_object_detection_msgs/BaTestEnvironmentRequest.h>
#include <cob_object_detection_msgs/BaTestEnvironmentResponse.h>


namespace cob_object_detection_msgs
{

struct BaTestEnvironment
{

typedef BaTestEnvironmentRequest Request;
typedef BaTestEnvironmentResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct BaTestEnvironment
} // namespace cob_object_detection_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cob_object_detection_msgs::BaTestEnvironment > {
  static const char* value()
  {
    return "e3abe6b136e84d507dcba74e019ba61e";
  }

  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironment&) { return value(); }
};

template<>
struct DataType< ::cob_object_detection_msgs::BaTestEnvironment > {
  static const char* value()
  {
    return "cob_object_detection_msgs/BaTestEnvironment";
  }

  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironment&) { return value(); }
};


// service_traits::MD5Sum< ::cob_object_detection_msgs::BaTestEnvironmentRequest> should match 
// service_traits::MD5Sum< ::cob_object_detection_msgs::BaTestEnvironment > 
template<>
struct MD5Sum< ::cob_object_detection_msgs::BaTestEnvironmentRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cob_object_detection_msgs::BaTestEnvironment >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironmentRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_object_detection_msgs::BaTestEnvironmentRequest> should match 
// service_traits::DataType< ::cob_object_detection_msgs::BaTestEnvironment > 
template<>
struct DataType< ::cob_object_detection_msgs::BaTestEnvironmentRequest>
{
  static const char* value()
  {
    return DataType< ::cob_object_detection_msgs::BaTestEnvironment >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironmentRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cob_object_detection_msgs::BaTestEnvironmentResponse> should match 
// service_traits::MD5Sum< ::cob_object_detection_msgs::BaTestEnvironment > 
template<>
struct MD5Sum< ::cob_object_detection_msgs::BaTestEnvironmentResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cob_object_detection_msgs::BaTestEnvironment >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironmentResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_object_detection_msgs::BaTestEnvironmentResponse> should match 
// service_traits::DataType< ::cob_object_detection_msgs::BaTestEnvironment > 
template<>
struct DataType< ::cob_object_detection_msgs::BaTestEnvironmentResponse>
{
  static const char* value()
  {
    return DataType< ::cob_object_detection_msgs::BaTestEnvironment >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::BaTestEnvironmentResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COB_OBJECT_DETECTION_MSGS_MESSAGE_BATESTENVIRONMENT_H
