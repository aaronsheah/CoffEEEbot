#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include "../../../devel/include/state_machine/question_msg.h"
#include "../../../devel/include/state_machine/Trx.h"
#include "../../../devel/include/state_machine/RecMsgStruc.h"
#include <iostream>
#include <string>
#include <sstream>

#include "state_machine_node.h"
#include "FSM2.h"

using namespace std;

string dialogue[30][10];

int main(int argc, char** argv){
    ros::init(argc, argv, "FSM");
    ros::NodeHandle n;

    init_dialogue(dialogue);
    FSM node(n);
    ROS_INFO("FSM started");
    ros::spin();
    return 0;
}
