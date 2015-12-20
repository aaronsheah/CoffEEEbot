#ifndef FSM_H
#define FSM_H

const int bufferSize=1000;

class FSM{
private:
    ros::Publisher questionPub;
    ros::Publisher privacyPub;
    ros::Publisher finishPub;
    ros::Publisher enPub;
    ros::Subscriber nameSub;
    ros::Subscriber answerSub;
    ros::Subscriber recommenderSub;
    ros::Subscriber advertSub;
    ros::Subscriber startSub;
    ros::Subscriber idSub;

    coffee coffEEEbot[5];

    int currState;
    int oldState;

    int num_out_of_stock;
    int out_of_stock[5];

    int coffee_rec[5];
    string coffee_q[3];

    string name;
    string UserID;

    int existing;
    int asked;
    int coffeeChoice;
    int remember;
    int recommend;
    int enable;
    int counter;
    int ok;
public:
    FSM(ros::NodeHandle& n) :
        currState(0), oldState(0), num_out_of_stock(0), existing(0), asked(0),coffeeChoice(0),remember(0),recommend(0),enable(0),counter(0),ok(0)
    {
        coffEEEbot[0].type="Cappuccino";
        coffEEEbot[1].type="Cafe Au Lait";
        coffEEEbot[2].type="Caramel Latte Macchiato";
        coffEEEbot[3].type="Tea Latte";
        coffEEEbot[4].type="Lungo Decaf";

        coffEEEbot[0].stock=4;
        coffEEEbot[1].stock=8;
        coffEEEbot[2].stock=4;
        coffEEEbot[3].stock=4;
        coffEEEbot[4].stock=8;

	out_of_stock[0]=0;
	out_of_stock[1]=0;
	out_of_stock[2]=0;
	out_of_stock[3]=0;
	out_of_stock[4]=0;

	coffee_rec[0]=0;
	coffee_rec[1]=2;
	coffee_rec[2]=3;
	coffee_rec[3]=1;
	coffee_rec[4]=4;

	coffee_q[0]="Would you like something sweeter?";
	coffee_q[1]="Would you prefer a cup of tea?";
	coffee_q[2]="Would you like to have milk in your drink?";



        questionPub = n.advertise<state_machine::question_msg>("question", bufferSize);
        privacyPub= n.advertise<state_machine::Trx>("privacy", bufferSize);
        finishPub= n.advertise<std_msgs::Int32>("finish", bufferSize);
	enPub= n.advertise<std_msgs::Int32>("speech_recognizer_en", bufferSize);
        nameSub = n.subscribe("name", bufferSize, &FSM::nameCallback, this);
        answerSub = n.subscribe("answer", bufferSize, &FSM::answerCallback, this);
        recommenderSub = n.subscribe("recommender", bufferSize, &FSM::recomCallback, this);
        advertSub=n.subscribe("/userPresent", bufferSize, &FSM::advertCallback, this);
        startSub=n.subscribe("/existingCustomer", bufferSize, &FSM::startCallback, this);
	idSub=n.subscribe("/userID", bufferSize, &FSM::idCallback, this);
    }

    void idCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("userID: %s", msg->data.c_str());
    UserID=msg->data.c_str();
    }

    void nameCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("Customer name: %s", msg->data.c_str());
    name=msg->data.c_str();
    currState=2;
	if (ok==0){
	ok=1;
	}
	else{
    	fsm();
	}
    }

    void answerCallback(const std_msgs::Int32::ConstPtr& msg){
    std_msgs::Int32 en;
    en.data=0;
    enPub.publish(en);

    oldState=currState;
    if (currState==9){
        remember=msg->data;
    }
    state_change(msg->data);
    fsm();
    }
    void recomCallback(const state_machine::RecMsgStruc::ConstPtr& msg){
	ROS_INFO("recom recevied");	       
	ROS_INFO("current state %d",currState);
	ROS_INFO("enable %d",enable);	
    if(enable==1){
	if (currState==0||currState==1){	
	ROS_INFO("getting data");
    	oldState=currState;
    	name=msg->Name.c_str();
    	UserID=msg->userID.c_str();
    	//existing=msg->isExist;
    	coffee_rec[0]=(msg->FirstRec)-1;
    	coffee_rec[1]=(msg->SecondRec)-1;
    	coffee_rec[2]=(msg->ThirdRec)-1;
    	coffee_rec[3]=(msg->ForthRec)-1;
    	coffee_rec[4]=(msg->FifthRec)-1;
    	coffee_q[0]=msg->FirstQ;
    	coffee_q[1]=msg->SecondQ;
    	coffee_q[2]=msg->ThirdQ;

//	ROS_INFO("UserID 1. %s 2. %s", UserID,msg->userID.c_str()); 
        
	if(existing==1){
            currState=19;
        	fsm();
        }
        if(existing==0){
	    currState=2;	
    		if(ok==0){
		ok=1;	
		}
		else
        	fsm();
        }
        
        }
    }
    }

    void advertCallback(const std_msgs::Int32::ConstPtr& msg){
        ROS_INFO("advert Current state %d %d",currState,msg->data);
	if(msg->data==1){
		counter++;
		if(counter==10){        
			if(currState==0){
        		fsm();
			}
			counter=0;
		}
        }
    }
    void startCallback(const std_msgs::Int32::ConstPtr& msg){
    if(currState==0){
        existing=msg->data;
        //if (existing==0){
        //    currState=1;
        //}
	enable=1;
	ROS_INFO("enable %d",enable);
    }
    }
    void state_change(int);
    void fsm();
    void state0();
    void state1();
    void state2();
    void state3();
    void state4();
    void state5();
    void state6();
    void state7();
    void state8();
    void state9();
    void state10();
    void state11();
    void state12();
    void state13();
    void state14();
    void state15();
    void state16();
    void state17();
    void state19();
    void state20();
    void state21();
    void state22();
    void state23();
    void state24();

};

void FSM:: state_change(int input){

    int next=currState;
	ROS_INFO("in state change, current %d",next);
    if(currState==2||currState==11||currState==17){
	//ROS_INFO("statement1");
        if(0<=input && input<=6){
            next=input+3;
        }
        else if(input==8){
            next=13;
        }
        else
            ROS_INFO("INVALID INPUT");
    }

    else if(3<=currState&&currState<=7){
    //ROS_INFO("statement2");
        if(input==0){
            next=10;
        }
        else if(input==1){
            next=11;
        }
        else
            ROS_INFO("INVALID INPUT");
    }

    else if(currState==8){
        if(0<=input && input<=4){
            next=input+20;
        }
        else if (input==8){
        next=13;
        }

        else
            ROS_INFO("INVALID INPUT");
    }


    else if(currState==10){
	//ROS_INFO("statement3");
	next=9;
	ROS_INFO("FINISH PURCHASE %d",next);
    }

    else if(currState==9){
	//ROS_INFO("statement3");
	next=12;
	ROS_INFO("FINISH PURCHASE %d",next);
    }

    else if(currState==12){
    //ROS_INFO("statement4");
        next=0;
    }
    else if(currState==0){
    //ROS_INFO("statement4");
        next=1;
    }
    else if(currState==13){
    //ROS_INFO("statement2");
        if(input==0){
            next=coffee_rec[recommend]+3;
        }
        else if(input==1){
            next=14;
        }

        else
            ROS_INFO("INVALID INPUT");
    }
    else if(currState==14){
    //ROS_INFO("statement2");
        if(input==0){
            next=13;
            recommend=1;
        }
        else if(input==1){
            next=15;
        }

        else
            ROS_INFO("INVALID INPUT");
    }


    else if(currState==15){
    //ROS_INFO("statement2");
        if(input==0){
            next=13;
            recommend=2;
        }
        else if(input==1){
            next=16;
        }
        else
            ROS_INFO("INVALID INPUT");
    }


    else if(currState==16){
    //ROS_INFO("statement2");
        if(input==0){
            next=13;
            recommend=3;
        }
        else if(input==1){
            next=13;
            recommend=4;
        }
        else
            ROS_INFO("INVALID INPUT");
    }

    else if(currState==19){
        int random=rand()%4;
	if(input==0)
	    next=next=coffee_rec[recommend]+3;
	else if (input==1){
        if(random==1||random==2||random==3){
            //continue recommending
            next=14;
        }
        if(random==0){
            //what do you like
            next=17;
        }
	}
    else
        ROS_INFO("INVALID Current state");
    }

    else if(20<=currState&&currState<=24){
    //ROS_INFO("statement2");
        if(input==0){
            next=13;
        }
        else if(input==1){
            next=2;
        }
        else
            ROS_INFO("INVALID INPUT");
    }
    else{
        ROS_INFO("INVALID Next state");
        next=currState;
    }

    ROS_INFO("State Transitioning from %d to %d",currState,next);

    oldState=currState;
    currState=next;
return ;
}

void FSM::fsm(){
    ROS_INFO("Current state: %d\n",currState);

    switch(currState){
        case 0:
            state0();
            break;
        case 1:
            state1();
            break;
        case 2:
            state2();
            break;
        case 3:
            state3();
            break;
        case 4:
            state4();
            break;
        case 5:
            state5();
            break;
        case 6:
            state6();
            break;
        case 7:
            state7();
            break;
        case 8:
            state8();
            break;
        case 9:
            state9();
            break;
        case 10:
            state10();
            break;
        case 11:
            state11();
            break;
        case 12:
            state12();
	    break;
        case 13:
            state13();
            break;
        case 14:
            state14();
            break;
        case 15:
            state15();
            break;
        case 16:
            state16();
	    break;
        case 17:
            state17();
	    break;
        case 19:
            state19();
	    break;
        case 20:
            state20();
	    break;

        case 21:
            state21();
	    break;
        case 22:
            state22();
            break;
        case 23:
            state23();
            break;
        case 24:
            state24();
            break;
    }

    return;
}
void FSM::state0(){
    //say hello
    //record response
    //send name to data base

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 0);
    //ss<<"Just say something";
    msg.dialogue =ss.str();
    msg.ans=0;
    msg.stock=22222;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);
    //ros::Duration(5).sleep();
    return;
}

void FSM::state1(){
    //say hello
    //record response
    //send name to data base

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 0);
    msg.dialogue =ss.str();
    msg.ans=0;
    msg.stock=22222;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    return;
}

void FSM::state2(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;
    if (asked==0){
    ss<<name<<", "<<choose_dialogue(dialogue, 2);
    }
    else{
    ss<<choose_dialogue(dialogue, 2);
    }
    msg.dialogue =ss.str();
    msg.ans=1;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    


    return;
}

void FSM::state3(){
    //coffee selection
    //what do you want?

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 3);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);
    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state4(){
    //coffee selection
    //what do you want?
    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 4);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);
    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state5(){
    //coffee selection
    //what do you want?
    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 5);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);
    
    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}


void FSM::state6(){
    //coffee selection
    //what do you want?
    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 6);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state7(){
    //coffee selection
    //what do you want?
    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 7);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}


void FSM::state8(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 8);
    msg.dialogue =ss.str();
    msg.ans=1;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state9(){
    //privacy
    //remembered?

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 9);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);
    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}



void FSM::state10(){
    //tutorial
    ROS_INFO("old state %d",oldState);
    coffEEEbot[oldState-3].stock--;
    coffeeChoice=oldState-3;
    state_machine::question_msg msg;

    std::stringstream ss;
    ss<<choose_dialogue(dialogue, 10);
    msg.dialogue =ss.str();
    msg.ans=3;
    msg.stock=coffeeChoice;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);
    questionPub.publish(msg);

    return;
}

void FSM::state11(){
    //error state
    //sorry, what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 11);
    msg.dialogue =ss.str();
    msg.ans=1;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state12(){
    //tutorial

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 12);
    msg.dialogue =ss.str();
    msg.ans=4;
    msg.stock=0;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    std::stringstream ss1;
    std::stringstream ss2;
    state_machine::Trx msg1;
    ss1<<UserID;
    msg1.userID=ss1.str();
    ss2<<name;
    msg1.name=ss2.str();

    //ROS_INFO("userID %s\n name %s\n",ss1.str(),ss2.str());

    msg1.isExist=existing;
    msg1.drink=coffeeChoice;
    msg1.keep=remember;
    privacyPub.publish(msg1);

    ROS_INFO("name:%s\n userID:%s\n drink:%d\n keep:%d\n exist:%d\n", msg1.name.c_str(),msg1.userID.c_str(),msg1.drink,msg1.keep,msg1.isExist); 

    std_msgs::Int32 msg2;
    msg2.data=0;
    finishPub.publish(msg2);

    currState=0;
    oldState=0;
    existing=0;
    asked=0;
    recommend=0;
    remember=0;
    enable=0;
    coffeeChoice=0;
    for(int i=0;i<5;i++){
        ROS_INFO("%s %d", coffEEEbot[i].type.c_str(), coffEEEbot[i].stock);
    }
    ros::Duration(5).sleep();
    return;
}
void FSM::state13(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;
    int a=rand()%5;
    if(a==0||a==1){
    ss<<choose_dialogue(dialogue, 13)<<" "<<coffEEEbot[coffee_rec[recommend]].type<<"?";
    }
    if(a==2||a==3){
    ss<<coffEEEbot[coffee_rec[recommend]].type<<" "<<choose_dialogue(dialogue, 15)<<"?";
    }
    if(a==4){
    ss<<"Is "<<coffEEEbot[coffee_rec[recommend]].type<<" "<<choose_dialogue(dialogue, 14)<<"?";
    }

    ROS_INFO("recommend: %d coffee:%d",recommend, coffee_rec[recommend]);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state14(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<coffee_q[0];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state15(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<coffee_q[1];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state16(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<coffee_q[2];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}


void FSM::state17(){
    //coffee selection
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 17);
    msg.dialogue =ss.str();
    msg.ans=1;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(3).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state19(){
    //returning customer coffee selection
    //what do you want?
    int stock=0;
    ROS_INFO("in state 19");
    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<choose_dialogue(dialogue, 18)<<" "<<name<<"."<<" "<<coffEEEbot[coffee_rec[recommend]].type<<" "<<choose_dialogue(dialogue, 19);
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(5).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);

    return;
}

void FSM::state20(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<dialogue[8][5];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(6).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state21(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<dialogue[8][6];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(6).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state22(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<dialogue[8][7];
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(6).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state23(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<dialogue[8][8];
  
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(6).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}

void FSM::state24(){
    //coffee introduction
    //what do you want?
    int stock=0;

    num_out_of_stock=check_stock(coffEEEbot, out_of_stock);

    stock=gen_stock_code(out_of_stock);

    state_machine::question_msg msg;

    std::stringstream ss;

    ss<<dialogue[8][9];
    
    msg.dialogue =ss.str();
    msg.ans=2;
    msg.stock=stock;

    ROS_INFO("dialogue:%s\n type:%d\n stock:\n%d",msg.dialogue.c_str(),msg.ans,msg.stock);

    questionPub.publish(msg);

    ros::Duration(6).sleep();
    std_msgs::Int32 en;
    en.data=1;
    enPub.publish(en);
    return;
}
#endif // FSM_H
