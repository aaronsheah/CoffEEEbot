; Auto-generated. Do not edit!


(cl:in-package recommender-msg)


;//! \htmlinclude Trx.msg.html

(cl:defclass <Trx> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (userID
    :reader userID
    :initarg :userID
    :type cl:string
    :initform "")
   (isExist
    :reader isExist
    :initarg :isExist
    :type cl:integer
    :initform 0)
   (keep
    :reader keep
    :initarg :keep
    :type cl:integer
    :initform 0)
   (drink
    :reader drink
    :initarg :drink
    :type cl:integer
    :initform 0))
)

(cl:defclass Trx (<Trx>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Trx>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Trx)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name recommender-msg:<Trx> is deprecated: use recommender-msg:Trx instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <Trx>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recommender-msg:name-val is deprecated.  Use recommender-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'userID-val :lambda-list '(m))
(cl:defmethod userID-val ((m <Trx>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recommender-msg:userID-val is deprecated.  Use recommender-msg:userID instead.")
  (userID m))

(cl:ensure-generic-function 'isExist-val :lambda-list '(m))
(cl:defmethod isExist-val ((m <Trx>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recommender-msg:isExist-val is deprecated.  Use recommender-msg:isExist instead.")
  (isExist m))

(cl:ensure-generic-function 'keep-val :lambda-list '(m))
(cl:defmethod keep-val ((m <Trx>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recommender-msg:keep-val is deprecated.  Use recommender-msg:keep instead.")
  (keep m))

(cl:ensure-generic-function 'drink-val :lambda-list '(m))
(cl:defmethod drink-val ((m <Trx>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recommender-msg:drink-val is deprecated.  Use recommender-msg:drink instead.")
  (drink m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Trx>) ostream)
  "Serializes a message object of type '<Trx>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'userID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'userID))
  (cl:let* ((signed (cl:slot-value msg 'isExist)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'keep)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'drink)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Trx>) istream)
  "Deserializes a message object of type '<Trx>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'userID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'userID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'isExist) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'keep) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'drink) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Trx>)))
  "Returns string type for a message object of type '<Trx>"
  "recommender/Trx")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Trx)))
  "Returns string type for a message object of type 'Trx"
  "recommender/Trx")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Trx>)))
  "Returns md5sum for a message object of type '<Trx>"
  "a2b29f64e52e4a0aea1b9be454c66754")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Trx)))
  "Returns md5sum for a message object of type 'Trx"
  "a2b29f64e52e4a0aea1b9be454c66754")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Trx>)))
  "Returns full string definition for message of type '<Trx>"
  (cl:format cl:nil "string name~%string userID~%int32 isExist~%int32 keep~%int32 drink~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Trx)))
  "Returns full string definition for message of type 'Trx"
  (cl:format cl:nil "string name~%string userID~%int32 isExist~%int32 keep~%int32 drink~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Trx>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     4 (cl:length (cl:slot-value msg 'userID))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Trx>))
  "Converts a ROS message object to a list"
  (cl:list 'Trx
    (cl:cons ':name (name msg))
    (cl:cons ':userID (userID msg))
    (cl:cons ':isExist (isExist msg))
    (cl:cons ':keep (keep msg))
    (cl:cons ':drink (drink msg))
))
