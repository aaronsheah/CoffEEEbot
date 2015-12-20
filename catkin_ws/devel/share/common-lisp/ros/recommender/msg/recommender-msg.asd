
(cl:in-package :asdf)

(defsystem "recommender-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Trx" :depends-on ("_package_Trx"))
    (:file "_package_Trx" :depends-on ("_package"))
    (:file "RecMsgStruc" :depends-on ("_package_RecMsgStruc"))
    (:file "_package_RecMsgStruc" :depends-on ("_package"))
  ))