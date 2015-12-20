
(cl:in-package :asdf)

(defsystem "pocketsphinx-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "question_msg" :depends-on ("_package_question_msg"))
    (:file "_package_question_msg" :depends-on ("_package"))
  ))