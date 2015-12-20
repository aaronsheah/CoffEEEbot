; Auto-generated. Do not edit!


(cl:in-package pocketsphinx-msg)


;//! \htmlinclude question_msg.msg.html

(cl:defclass <question_msg> (roslisp-msg-protocol:ros-message)
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

(cl:defclass question_msg (<question_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <question_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'question_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pocketsphinx-msg:<question_msg> is deprecated: use pocketsphinx-msg:question_msg instead.")))

(cl:ensure-generic-function 'dialogue-val :lambda-list '(m))
(cl:defmethod dialogue-val ((m <question_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pocketsphinx-msg:dialogue-val is deprecated.  Use pocketsphinx-msg:dialogue instead.")
  (dialogue m))

(cl:ensure-generic-function 'ans-val :lambda-list '(m))
(cl:defmethod ans-val ((m <question_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pocketsphinx-msg:ans-val is deprecated.  Use pocketsphinx-msg:ans instead.")
  (ans m))

(cl:ensure-generic-function 'stock-val :lambda-list '(m))
(cl:defmethod stock-val ((m <question_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pocketsphinx-msg:stock-val is deprecated.  Use pocketsphinx-msg:stock instead.")
  (stock m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <question_msg>) ostream)
  "Serializes a message object of type '<question_msg>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <question_msg>) istream)
  "Deserializes a message object of type '<question_msg>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<question_msg>)))
  "Returns string type for a message object of type '<question_msg>"
  "pocketsphinx/question_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'question_msg)))
  "Returns string type for a message object of type 'question_msg"
  "pocketsphinx/question_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<question_msg>)))
  "Returns md5sum for a message object of type '<question_msg>"
  "585ea6598299f8e066244f262bd13943")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'question_msg)))
  "Returns md5sum for a message object of type 'question_msg"
  "585ea6598299f8e066244f262bd13943")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<question_msg>)))
  "Returns full string definition for message of type '<question_msg>"
  (cl:format cl:nil "string dialogue~%int32 ans~%int32 stock~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'question_msg)))
  "Returns full string definition for message of type 'question_msg"
  (cl:format cl:nil "string dialogue~%int32 ans~%int32 stock~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <question_msg>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'dialogue))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <question_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'question_msg
    (cl:cons ':dialogue (dialogue msg))
    (cl:cons ':ans (ans msg))
    (cl:cons ':stock (stock msg))
))
