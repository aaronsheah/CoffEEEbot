; Auto-generated. Do not edit!


(cl:in-package state_machine-msg)


;//! \htmlinclude q.msg.html

(cl:defclass <q> (roslisp-msg-protocol:ros-message)
  ((dialogue
    :reader dialogue
    :initarg :dialogue
    :type cl:string
    :initform "")
   (ans
    :reader ans
    :initarg :ans
    :type cl:integer
    :initform 0)
   (stock
    :reader stock
    :initarg :stock
    :type cl:integer
    :initform 0))
)

(cl:defclass q (<q>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <q>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'q)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name state_machine-msg:<q> is deprecated: use state_machine-msg:q instead.")))

(cl:ensure-generic-function 'dialogue-val :lambda-list '(m))
(cl:defmethod dialogue-val ((m <q>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader state_machine-msg:dialogue-val is deprecated.  Use state_machine-msg:dialogue instead.")
  (dialogue m))

(cl:ensure-generic-function 'ans-val :lambda-list '(m))
(cl:defmethod ans-val ((m <q>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader state_machine-msg:ans-val is deprecated.  Use state_machine-msg:ans instead.")
  (ans m))

(cl:ensure-generic-function 'stock-val :lambda-list '(m))
(cl:defmethod stock-val ((m <q>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader state_machine-msg:stock-val is deprecated.  Use state_machine-msg:stock instead.")
  (stock m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <q>) ostream)
  "Serializes a message object of type '<q>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dialogue))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dialogue))
  (cl:let* ((signed (cl:slot-value msg 'ans)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'stock)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <q>) istream)
  "Deserializes a message object of type '<q>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dialogue) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dialogue) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ans) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stock) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<q>)))
  "Returns string type for a message object of type '<q>"
  "state_machine/q")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'q)))
  "Returns string type for a message object of type 'q"
  "state_machine/q")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<q>)))
  "Returns md5sum for a message object of type '<q>"
  "585ea6598299f8e066244f262bd13943")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'q)))
  "Returns md5sum for a message object of type 'q"
  "585ea6598299f8e066244f262bd13943")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<q>)))
  "Returns full string definition for message of type '<q>"
  (cl:format cl:nil "string dialogue~%int32 ans~%int32 stock~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'q)))
  "Returns full string definition for message of type 'q"
  (cl:format cl:nil "string dialogue~%int32 ans~%int32 stock~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <q>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'dialogue))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <q>))
  "Converts a ROS message object to a list"
  (cl:list 'q
    (cl:cons ':dialogue (dialogue msg))
    (cl:cons ':ans (ans msg))
    (cl:cons ':stock (stock msg))
))
