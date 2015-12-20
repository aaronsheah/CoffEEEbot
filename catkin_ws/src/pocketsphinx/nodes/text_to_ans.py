#!/usr/bin/env python

"""
voice_cmd_vel.py is a simple demo of speech recognition.
  You can control a mobile base using commands found
  in the corpus file.
"""

import roslib; roslib.load_manifest('pocketsphinx')
import rospy
import math

from geometry_msgs.msg import Twist
from std_msgs.msg import String
from std_msgs.msg import Int32
from pocketsphinx.msg import question_msg

global enable
global error
global repeat
enable = 0
error = 0
repeat = 0


class text_to_ans:	
	
	def __init__(self):
		rospy.on_shutdown(self.cleanup)
		#global enable = 0
		#print "enable init"
		#global error = 0
		#print "error init"
		global enable
		global error
		global repeat
		self.msg = -1
		self.msg1 = question_msg()
        # publish to cmd_vel, subscribe to speech output
		self.pub_ = rospy.Publisher('/answer', Int32, queue_size=10)
		self.pub1_ = rospy.Publisher('/question', question_msg, queue_size=10)
		rospy.Subscriber('recognizer/output', String, self.speechCb)
		rospy.Subscriber('/speech_recognizer_en', Int32, self.enableCb)
		#rospy.spin()
		r = rospy.Rate(1)
		while not rospy.is_shutdown():
			print "enable"
			print enable
			print "error"
			print error
			if enable == 1:
				print self.msg
				if self.msg <> -1:
					print "answer"
					print self.msg
					self.pub_.publish(self.msg)
					self.msg= -1
					enable = 0
					error = 0
					print "message sent"
					
				else:
					error += 1
					print "error"
			
			if error == 10:
				self.msg1.dialogue = "I did not catch that, can you please say that again?"
				self.msg1.ans = 0;
				self.msg1.stock = 0;
				self.pub1_.publish(self.msg1)
				error=0; 
				print "repeat"	
				repeat += 1

			if repeat ==2:
				self.msg1.dialogue = "I am sorry I do not quite understand. Maybe you can use the touch pad for the moment."
				self.msg1.ans = 0;
				self.msg1.stock = 0;
				self.pub1_.publish(self.msg1)
				error = 0; 
				repeat = 0;
				print "end repeat"
						
				
			r.sleep()


	def enableCb(self, msg):
		print "enable CB"
		rospy.loginfo(msg.data)
		global enable
		enable = msg.data
		print enable
			
	def speechCb(self, msg):
		rospy.loginfo(msg.data)
		if ((msg.data.find("yes") > -1) or (msg.data.find("yes, please") > -1) or (msg.data.find("sure") > -1) or (msg.data.find("of course") > -1) or (msg.data.find("why not") > -1) or (msg.data.find("definitely") > -1)):
			self.msg=0
			print "yes bunch"
		elif ((msg.data.find("cappuccino") > -1) or (msg.data.find("cappuccino please")> -1) or (msg.data.find("i want a cappuccino")> -1) or (msg.data.find("i would like a cappuccino")> -1) or (msg.data.find("i would like to have a cappuccino")> -1) or (msg.data.find("can i have a cappuccino") > -1)):    
			self.msg=0;
			print "got cappuccino"
  			 
		elif ((msg.data.find("no")> -1) or (msg.data.find("not now")> -1) or (msg.data.find("no thanks")> -1) or (msg.data.find("how about no")> -1) or (msg.data.find("i am alright, thank you")> -1) or (msg.data.find("i am ok thanks")> -1) or (msg.data.find("i am fine thanks")> -1)):
			self.msg=1
			print "no bunch"


  			
		elif ((msg.data.find("cafe au lait")> -1) or (msg.data.find("cafe au lait please")> -1) or (msg.data.find("i want a cafe au lait")> -1) or (msg.data.find("i would like a cafe au lait")> -1) or (msg.data.find("i would like to have a cafe au lait")> -1) or (msg.data.find("can i have a cafe au lait") > -1)):    
			self.msg=1
			print "got cafe au lait"
  				
		elif ((msg.data.find("caramel")> -1) or (msg.data.find("caramel macchiato")> -1) or (msg.data.find("caramel latte macchiato")> -1) or (msg.data.find("i want a caramel latte macchiato")> -1) or (msg.data.find("i would like a caramel latte macchiato")> -1) or (msg.data.find("i would like to have a caramel latte macchiato")> -1) or (msg.data.find("can i have a caramel latte macchiato") > -1)):    
			self.msg=2
			print "got caramel latte macchiato"
  				
		elif ((msg.data.find("tea latte")> -1) or (msg.data.find("tea latte please")> -1) or (msg.data.find("i want a tea latte")> -1) or (msg.data.find("i would like a tea latte")> -1) or (msg.data.find("i would like to have a tea latte")> -1) or (msg.data.find("can i have a tea latte") > -1)):    
			self.msg=3
			print "got tea latte"
  				 
  				 
		elif ((msg.data.find("lungo")> -1)or(msg.data.find("lungo decaf")> -1) or (msg.data.find("lungo decaf please")> -1) or (msg.data.find("lungo please")> -1) or (msg.data.find("i want a lungo decaf")> -1) or (msg.data.find("i want a lungo")> -1) or (msg.data.find("i would like a lungo decaf")> -1) or (msg.data.find("i would like a lungo")> -1) or (msg.data.find("i would like to have a lungo decaf")> -1) or (msg.data.find("can i have a lungo decaf") > -1)):    
			self.msg=4
			print "got lungo"
  		
		elif ((msg.data.find("introduction")> -1) or (msg.data.find("coffee introduction")> -1) or (msg.data.find("i would like coffee introduction")> -1)):    
			self.msg=5
			print "got introduction"

		elif ((msg.data.find("recommendation")> -1) or (msg.data.find("advice")> -1) or (msg.data.find("i want some advice")> -1) or (msg.data.find("i would like some advice")> -1) or (msg.data.find("recommend")> -1) or (msg.data.find("i would like some recommendation")> -1) or (msg.data.find("i would like some suggestion")> -1) or (msg.data.find("i want some advice")> -1) or (msg.data.find("i want some suggestion")> -1) or (msg.data.find("can you give me some advice")> -1) or (msg.data.find("can you recommend something for me") > -1)):    
			self.msg=8
			print "got recommendation"
		print self.msg
	def cleanup(self):
        # stop the robot!
		int1 = -1  				
		self.pub_.publish(int1)

if __name__=="__main__":
	rospy.init_node('text_to_ans')
	try:	
		text_to_ans()
	except rospy.ROSInterruptException:
		pass

