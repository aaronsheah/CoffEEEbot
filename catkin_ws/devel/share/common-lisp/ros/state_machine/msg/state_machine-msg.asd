
(cl:in-package :asdf)

(defsystem "state_machine-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Trx" :depends-on ("_package_Trx"))
    (:file "_package_Trx" :depends-on ("_package"))
    (:file "RecMsgStruc" :depends-on ("_package_RecMsgStruc"))
    (:file "_package_RecMsgStruc" :depends-on ("_package"))
    (:file "question_msg" :depends-on ("_package_question_msg"))
    (:file "_package_question_msg" :depends-on ("_package"))
    (:file "q" :depends-on ("_package_q"))
    (:file "_package_q" :depends-on ("_package"))
  ))