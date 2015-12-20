// Generated by gencpp from file cob_object_detection_msgs/StopObjectRecording.msg
// DO NOT EDIT!


#ifndef COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDING_H
#define COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDING_H

#include <ros/service_traits.h>


#include <cob_object_detection_msgs/StopObjectRecordingRequest.h>
#include <cob_object_detection_msgs/StopObjectRecordingResponse.h>


namespace cob_object_detection_msgs
{

struct StopObjectRecording
{

typedef StopObjectRecordingRequest Request;
typedef StopObjectRecordingResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StopObjectRecording
} // namespace cob_object_detection_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cob_object_detection_msgs::StopObjectRecording > {
  static const char* value()
  {
    return "b115df286bf93d57db01286b71c91409";
  }

  static const char* value(const ::cob_object_detection_msgs::StopObjectRecording&) { return value(); }
};

template<>
struct DataType< ::cob_object_detection_msgs::StopObjectRecording > {
  static const char* value()
  {
    return "cob_object_detection_msgs/StopObjectRecording";
  }

  static const char* value(const ::cob_object_detection_msgs::StopObjectRecording&) { return value(); }
};


// service_traits::MD5Sum< ::cob_object_detection_msgs::StopObjectRecordingRequest> should match 
// service_traits::MD5Sum< ::cob_object_detection_msgs::StopObjectRecording > 
template<>
struct MD5Sum< ::cob_object_detection_msgs::StopObjectRecordingRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cob_object_detection_msgs::StopObjectRecording >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_object_detection_msgs::StopObjectRecordingRequest> should match 
// service_traits::DataType< ::cob_object_detection_msgs::StopObjectRecording > 
template<>
struct DataType< ::cob_object_detection_msgs::StopObjectRecordingRequest>
{
  static const char* value()
  {
    return DataType< ::cob_object_detection_msgs::StopObjectRecording >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cob_object_detection_msgs::StopObjectRecordingResponse> should match 
// service_traits::MD5Sum< ::cob_object_detection_msgs::StopObjectRecording > 
template<>
struct MD5Sum< ::cob_object_detection_msgs::StopObjectRecordingResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cob_object_detection_msgs::StopObjectRecording >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_object_detection_msgs::StopObjectRecordingResponse> should match 
// service_traits::DataType< ::cob_object_detection_msgs::StopObjectRecording > 
template<>
struct DataType< ::cob_object_detection_msgs::StopObjectRecordingResponse>
{
  static const char* value()
  {
    return DataType< ::cob_object_detection_msgs::StopObjectRecording >::value();
  }
  static const char* value(const ::cob_object_detection_msgs::StopObjectRecordingResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COB_OBJECT_DETECTION_MSGS_MESSAGE_STOPOBJECTRECORDING_H
