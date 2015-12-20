; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude RecMsgStruc.msg.html

(cl:defclass <RecMsgStruc> (roslisp-msg-protocol:ros-message)
  ((Name
    :reader Name
    :initarg :Name
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
   (FirstRec
    :reader FirstRec
    :initarg :FirstRec
    :type cl:integer
    :initform 0)
   (FirstQ
    :reader FirstQ
    :initarg :FirstQ
    :type cl:string
    :initform "")
   (SecondRec
    :reader SecondRec
    :initarg :SecondRec
    :type cl:integer
    :initform 0)
   (SecondQ
    :reader SecondQ
    :initarg :SecondQ
    :type cl:string
    :initform "")
   (ThirdRec
    :reader ThirdRec
    :initarg :ThirdRec
    :type cl:integer
    :initform 0)
   (ThirdQ
    :reader ThirdQ
    :initarg :ThirdQ
    :type cl:string
    :initform "")
   (ForthRec
    :reader ForthRec
    :initarg :ForthRec
    :type cl:integer
    :initform 0)
   (FifthRec
    :reader FifthRec
    :initarg :FifthRec
    :type cl:integer
    :initform 0))
)

(cl:defclass RecMsgStruc (<RecMsgStruc>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RecMsgStruc>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RecMsgStruc)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<RecMsgStruc> is deprecated: use test-msg:RecMsgStruc instead.")))

(cl:ensure-generic-function 'Name-val :lambda-list '(m))
(cl:defmethod Name-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:Name-val is deprecated.  Use test-msg:Name instead.")
  (Name m))

(cl:ensure-generic-function 'userID-val :lambda-list '(m))
(cl:defmethod userID-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:userID-val is deprecated.  Use test-msg:userID instead.")
  (userID m))

(cl:ensure-generic-function 'isExist-val :lambda-list '(m))
(cl:defmethod isExist-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:isExist-val is deprecated.  Use test-msg:isExist instead.")
  (isExist m))

(cl:ensure-generic-function 'FirstRec-val :lambda-list '(m))
(cl:defmethod FirstRec-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:FirstRec-val is deprecated.  Use test-msg:FirstRec instead.")
  (FirstRec m))

(cl:ensure-generic-function 'FirstQ-val :lambda-list '(m))
(cl:defmethod FirstQ-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:FirstQ-val is deprecated.  Use test-msg:FirstQ instead.")
  (FirstQ m))

(cl:ensure-generic-function 'SecondRec-val :lambda-list '(m))
(cl:defmethod SecondRec-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:SecondRec-val is deprecated.  Use test-msg:SecondRec instead.")
  (SecondRec m))

(cl:ensure-generic-function 'SecondQ-val :lambda-list '(m))
(cl:defmethod SecondQ-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:SecondQ-val is deprecated.  Use test-msg:SecondQ instead.")
  (SecondQ m))

(cl:ensure-generic-function 'ThirdRec-val :lambda-list '(m))
(cl:defmethod ThirdRec-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:ThirdRec-val is deprecated.  Use test-msg:ThirdRec instead.")
  (ThirdRec m))

(cl:ensure-generic-function 'ThirdQ-val :lambda-list '(m))
(cl:defmethod ThirdQ-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:ThirdQ-val is deprecated.  Use test-msg:ThirdQ instead.")
  (ThirdQ m))

(cl:ensure-generic-function 'ForthRec-val :lambda-list '(m))
(cl:defmethod ForthRec-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:ForthRec-val is deprecated.  Use test-msg:ForthRec instead.")
  (ForthRec m))

(cl:ensure-generic-function 'FifthRec-val :lambda-list '(m))
(cl:defmethod FifthRec-val ((m <RecMsgStruc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:FifthRec-val is deprecated.  Use test-msg:FifthRec instead.")
  (FifthRec m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RecMsgStruc>) ostream)
  "Serializes a message object of type '<RecMsgStruc>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'Name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'Name))
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
  (cl:let* ((signed (cl:slot-value msg 'FirstRec)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'FirstQ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'FirstQ))
  (cl:let* ((signed (cl:slot-value msg 'SecondRec)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'SecondQ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'SecondQ))
  (cl:let* ((signed (cl:slot-value msg 'ThirdRec)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'ThirdQ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'ThirdQ))
  (cl:let* ((signed (cl:slot-value msg 'ForthRec)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'FifthRec)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RecMsgStruc>) istream)
  "Deserializes a message object of type '<RecMsgStruc>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'Name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
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
      (cl:setf (cl:slot-value msg 'FirstRec) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'FirstQ) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'FirstQ) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'SecondRec) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'SecondQ) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'SecondQ) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ThirdRec) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ThirdQ) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'ThirdQ) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ForthRec) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'FifthRec) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RecMsgStruc>)))
  "Returns string type for a message object of type '<RecMsgStruc>"
  "test/RecMsgStruc")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RecMsgStruc)))
  "Returns string type for a message object of type 'RecMsgStruc"
  "test/RecMsgStruc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RecMsgStruc>)))
  "Returns md5sum for a message object of type '<RecMsgStruc>"
  "fb202545eccded8b9b08c3c358605781")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RecMsgStruc)))
  "Returns md5sum for a message object of type 'RecMsgStruc"
  "fb202545eccded8b9b08c3c358605781")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RecMsgStruc>)))
  "Returns full string definition for message of type '<RecMsgStruc>"
  (cl:format cl:nil "string Name~%string userID~%int32 isExist~%int32 FirstRec~%string FirstQ~%int32 SecondRec~%string SecondQ~%int32 ThirdRec~%string ThirdQ~%int32 ForthRec~%int32 FifthRec~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RecMsgStruc)))
  "Returns full string definition for message of type 'RecMsgStruc"
  (cl:format cl:nil "string Name~%string userID~%int32 isExist~%int32 FirstRec~%string FirstQ~%int32 SecondRec~%string SecondQ~%int32 ThirdRec~%string ThirdQ~%int32 ForthRec~%int32 FifthRec~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RecMsgStruc>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'Name))
     4 (cl:length (cl:slot-value msg 'userID))
     4
     4
     4 (cl:length (cl:slot-value msg 'FirstQ))
     4
     4 (cl:length (cl:slot-value msg 'SecondQ))
     4
     4 (cl:length (cl:slot-value msg 'ThirdQ))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RecMsgStruc>))
  "Converts a ROS message object to a list"
  (cl:list 'RecMsgStruc
    (cl:cons ':Name (Name msg))
    (cl:cons ':userID (userID msg))
    (cl:cons ':isExist (isExist msg))
    (cl:cons ':FirstRec (FirstRec msg))
    (cl:cons ':FirstQ (FirstQ msg))
    (cl:cons ':SecondRec (SecondRec msg))
    (cl:cons ':SecondQ (SecondQ msg))
    (cl:cons ':ThirdRec (ThirdRec msg))
    (cl:cons ':ThirdQ (ThirdQ msg))
    (cl:cons ':ForthRec (ForthRec msg))
    (cl:cons ':FifthRec (FifthRec msg))
))
