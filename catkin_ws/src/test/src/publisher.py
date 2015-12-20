#!/usr/bin/python2.7

import rospy
from std_msgs.msg import String, Int32
#from test.msg import Trx

def talker():
    #pub = rospy.Publisher('trx_s12', Trx, queue_size=10)
    pub = rospy.Publisher('userID', String, queue_size=10)
    rospy.init_node('publisher', anonymous=True)
    rate = rospy.Rate(0.1) # 10hz
    while not rospy.is_shutdown():
        #pub_msg = Trx()
        #pub_msg.userID = '0'
        #pub_msg.drink = 2
        #pub_msg.keep = 0
        #pub_msg.name = 'Test'
        pub_msg = '1'
        rospy.loginfo(pub_msg)
        pub.publish(pub_msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

