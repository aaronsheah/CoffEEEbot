"""autogenerated by genpy from cob_perception_msgs/ColorDepthImage.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg
import cob_perception_msgs.msg
import sensor_msgs.msg

class ColorDepthImage(genpy.Message):
  _md5sum = "03f1995e7c816d8ab016aa6ceb57208a"
  _type = "cob_perception_msgs/ColorDepthImage"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """Rect head_detection		# bounding box of detected head (coordinates in relation to whole image coordinate system)
sensor_msgs/Image color_image	# color image patch at bounding box head_detection (i.e. same size as head region, not only face region)
sensor_msgs/Image depth_image	# depth image patch at bounding box head_detection
Rect[] face_detections		# faces detected in color image inside the head's bounding box (coordinates in relation to head's bounding box)


================================================================================
MSG: cob_perception_msgs/Rect
int32 x
int32 y
int32 width
int32 height

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of cameara
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

"""
  __slots__ = ['head_detection','color_image','depth_image','face_detections']
  _slot_types = ['cob_perception_msgs/Rect','sensor_msgs/Image','sensor_msgs/Image','cob_perception_msgs/Rect[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       head_detection,color_image,depth_image,face_detections

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ColorDepthImage, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.head_detection is None:
        self.head_detection = cob_perception_msgs.msg.Rect()
      if self.color_image is None:
        self.color_image = sensor_msgs.msg.Image()
      if self.depth_image is None:
        self.depth_image = sensor_msgs.msg.Image()
      if self.face_detections is None:
        self.face_detections = []
    else:
      self.head_detection = cob_perception_msgs.msg.Rect()
      self.color_image = sensor_msgs.msg.Image()
      self.depth_image = sensor_msgs.msg.Image()
      self.face_detections = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_4i3I.pack(_x.head_detection.x, _x.head_detection.y, _x.head_detection.width, _x.head_detection.height, _x.color_image.header.seq, _x.color_image.header.stamp.secs, _x.color_image.header.stamp.nsecs))
      _x = self.color_image.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2I.pack(_x.color_image.height, _x.color_image.width))
      _x = self.color_image.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_BI.pack(_x.color_image.is_bigendian, _x.color_image.step))
      _x = self.color_image.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3I.pack(_x.depth_image.header.seq, _x.depth_image.header.stamp.secs, _x.depth_image.header.stamp.nsecs))
      _x = self.depth_image.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2I.pack(_x.depth_image.height, _x.depth_image.width))
      _x = self.depth_image.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_BI.pack(_x.depth_image.is_bigendian, _x.depth_image.step))
      _x = self.depth_image.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.face_detections)
      buff.write(_struct_I.pack(length))
      for val1 in self.face_detections:
        _x = val1
        buff.write(_struct_4i.pack(_x.x, _x.y, _x.width, _x.height))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.head_detection is None:
        self.head_detection = cob_perception_msgs.msg.Rect()
      if self.color_image is None:
        self.color_image = sensor_msgs.msg.Image()
      if self.depth_image is None:
        self.depth_image = sensor_msgs.msg.Image()
      if self.face_detections is None:
        self.face_detections = None
      end = 0
      _x = self
      start = end
      end += 28
      (_x.head_detection.x, _x.head_detection.y, _x.head_detection.width, _x.head_detection.height, _x.color_image.header.seq, _x.color_image.header.stamp.secs, _x.color_image.header.stamp.nsecs,) = _struct_4i3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.color_image.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.color_image.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.color_image.height, _x.color_image.width,) = _struct_2I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.color_image.encoding = str[start:end].decode('utf-8')
      else:
        self.color_image.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.color_image.is_bigendian, _x.color_image.step,) = _struct_BI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.color_image.data = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.depth_image.header.seq, _x.depth_image.header.stamp.secs, _x.depth_image.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.depth_image.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.depth_image.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.depth_image.height, _x.depth_image.width,) = _struct_2I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.depth_image.encoding = str[start:end].decode('utf-8')
      else:
        self.depth_image.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.depth_image.is_bigendian, _x.depth_image.step,) = _struct_BI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.depth_image.data = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.face_detections = []
      for i in range(0, length):
        val1 = cob_perception_msgs.msg.Rect()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y, _x.width, _x.height,) = _struct_4i.unpack(str[start:end])
        self.face_detections.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_4i3I.pack(_x.head_detection.x, _x.head_detection.y, _x.head_detection.width, _x.head_detection.height, _x.color_image.header.seq, _x.color_image.header.stamp.secs, _x.color_image.header.stamp.nsecs))
      _x = self.color_image.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2I.pack(_x.color_image.height, _x.color_image.width))
      _x = self.color_image.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_BI.pack(_x.color_image.is_bigendian, _x.color_image.step))
      _x = self.color_image.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3I.pack(_x.depth_image.header.seq, _x.depth_image.header.stamp.secs, _x.depth_image.header.stamp.nsecs))
      _x = self.depth_image.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2I.pack(_x.depth_image.height, _x.depth_image.width))
      _x = self.depth_image.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_BI.pack(_x.depth_image.is_bigendian, _x.depth_image.step))
      _x = self.depth_image.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.face_detections)
      buff.write(_struct_I.pack(length))
      for val1 in self.face_detections:
        _x = val1
        buff.write(_struct_4i.pack(_x.x, _x.y, _x.width, _x.height))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.head_detection is None:
        self.head_detection = cob_perception_msgs.msg.Rect()
      if self.color_image is None:
        self.color_image = sensor_msgs.msg.Image()
      if self.depth_image is None:
        self.depth_image = sensor_msgs.msg.Image()
      if self.face_detections is None:
        self.face_detections = None
      end = 0
      _x = self
      start = end
      end += 28
      (_x.head_detection.x, _x.head_detection.y, _x.head_detection.width, _x.head_detection.height, _x.color_image.header.seq, _x.color_image.header.stamp.secs, _x.color_image.header.stamp.nsecs,) = _struct_4i3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.color_image.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.color_image.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.color_image.height, _x.color_image.width,) = _struct_2I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.color_image.encoding = str[start:end].decode('utf-8')
      else:
        self.color_image.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.color_image.is_bigendian, _x.color_image.step,) = _struct_BI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.color_image.data = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.depth_image.header.seq, _x.depth_image.header.stamp.secs, _x.depth_image.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.depth_image.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.depth_image.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.depth_image.height, _x.depth_image.width,) = _struct_2I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.depth_image.encoding = str[start:end].decode('utf-8')
      else:
        self.depth_image.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.depth_image.is_bigendian, _x.depth_image.step,) = _struct_BI.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.depth_image.data = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.face_detections = []
      for i in range(0, length):
        val1 = cob_perception_msgs.msg.Rect()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y, _x.width, _x.height,) = _struct_4i.unpack(str[start:end])
        self.face_detections.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_4i3I = struct.Struct("<4i3I")
_struct_3I = struct.Struct("<3I")
_struct_4i = struct.Struct("<4i")
_struct_2I = struct.Struct("<2I")
_struct_BI = struct.Struct("<BI")
