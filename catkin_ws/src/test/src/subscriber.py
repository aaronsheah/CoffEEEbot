#!/usr/bin/python2.7

import rospy
from std_msgs.msg import String, Int8
from recommender.msg import RecMsgStruc
import psycopg2 as pg2
import pandas as pd
import numpy as np
import datetime

def printToScreen(data):
	print 'User = ', data.Name
	print 'userID = ', data.userID
	print 'isExist = ', data.isExist
	print data.FirstRec
	print data.FirstQ, ' ', data.SecondRec
	print data.SecondQ, ' ', data.ThirdRec
	print data.ThirdQ, ' ', data.ForthRec
	print data.FifthRec
	print ' '
	
	
def listener():
	rospy.init_node('subscriber', anonymous=True)

	rospy.Subscriber('recommender', RecMsgStruc, printToScreen)

	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	listener()
