"""autogenerated by genpy from recommender/RecMsgStruc.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class RecMsgStruc(genpy.Message):
  _md5sum = "fb202545eccded8b9b08c3c358605781"
  _type = "recommender/RecMsgStruc"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string Name
string userID
int32 isExist
int32 FirstRec
string FirstQ
int32 SecondRec
string SecondQ
int32 ThirdRec
string ThirdQ
int32 ForthRec
int32 FifthRec

"""
  __slots__ = ['Name','userID','isExist','FirstRec','FirstQ','SecondRec','SecondQ','ThirdRec','ThirdQ','ForthRec','FifthRec']
  _slot_types = ['string','string','int32','int32','string','int32','string','int32','string','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       Name,userID,isExist,FirstRec,FirstQ,SecondRec,SecondQ,ThirdRec,ThirdQ,ForthRec,FifthRec

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(RecMsgStruc, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.Name is None:
        self.Name = ''
      if self.userID is None:
        self.userID = ''
      if self.isExist is None:
        self.isExist = 0
      if self.FirstRec is None:
        self.FirstRec = 0
      if self.FirstQ is None:
        self.FirstQ = ''
      if self.SecondRec is None:
        self.SecondRec = 0
      if self.SecondQ is None:
        self.SecondQ = ''
      if self.ThirdRec is None:
        self.ThirdRec = 0
      if self.ThirdQ is None:
        self.ThirdQ = ''
      if self.ForthRec is None:
        self.ForthRec = 0
      if self.FifthRec is None:
        self.FifthRec = 0
    else:
      self.Name = ''
      self.userID = ''
      self.isExist = 0
      self.FirstRec = 0
      self.FirstQ = ''
      self.SecondRec = 0
      self.SecondQ = ''
      self.ThirdRec = 0
      self.ThirdQ = ''
      self.ForthRec = 0
      self.FifthRec = 0

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
      _x = self.Name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.userID
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2i.pack(_x.isExist, _x.FirstRec))
      _x = self.FirstQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.SecondRec))
      _x = self.SecondQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.ThirdRec))
      _x = self.ThirdQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2i.pack(_x.ForthRec, _x.FifthRec))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Name = str[start:end].decode('utf-8')
      else:
        self.Name = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.userID = str[start:end].decode('utf-8')
      else:
        self.userID = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.isExist, _x.FirstRec,) = _struct_2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.FirstQ = str[start:end].decode('utf-8')
      else:
        self.FirstQ = str[start:end]
      start = end
      end += 4
      (self.SecondRec,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.SecondQ = str[start:end].decode('utf-8')
      else:
        self.SecondQ = str[start:end]
      start = end
      end += 4
      (self.ThirdRec,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ThirdQ = str[start:end].decode('utf-8')
      else:
        self.ThirdQ = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.ForthRec, _x.FifthRec,) = _struct_2i.unpack(str[start:end])
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
      _x = self.Name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.userID
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2i.pack(_x.isExist, _x.FirstRec))
      _x = self.FirstQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.SecondRec))
      _x = self.SecondQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.ThirdRec))
      _x = self.ThirdQ
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2i.pack(_x.ForthRec, _x.FifthRec))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Name = str[start:end].decode('utf-8')
      else:
        self.Name = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.userID = str[start:end].decode('utf-8')
      else:
        self.userID = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.isExist, _x.FirstRec,) = _struct_2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.FirstQ = str[start:end].decode('utf-8')
      else:
        self.FirstQ = str[start:end]
      start = end
      end += 4
      (self.SecondRec,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.SecondQ = str[start:end].decode('utf-8')
      else:
        self.SecondQ = str[start:end]
      start = end
      end += 4
      (self.ThirdRec,) = _struct_i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ThirdQ = str[start:end].decode('utf-8')
      else:
        self.ThirdQ = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.ForthRec, _x.FifthRec,) = _struct_2i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
_struct_2i = struct.Struct("<2i")