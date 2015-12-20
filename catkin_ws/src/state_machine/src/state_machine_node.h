#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

#include <sstream>

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern string dialogue[30][10];

void init_dialogue(string dialogue[30][10]){
//State 0 advertisement
dialogue[0][0]="Coffee, anyone?";
dialogue[0][1]="Anyone want a coffee?";
dialogue[0][2]="Do you want a coffee?";
dialogue[0][3]="Coffee here, coffee here.";
dialogue[0][4]="Come and get a coffee";

//State 1 greeting
dialogue[1][0]="Hello, I am CoffEEEbot. What's your name?";
dialogue[1][1]="Hi, my name is CoffEEEbot, and you?";
dialogue[1][2]="Nice to meet you. I am CoffEEEbot, what's your name?";
dialogue[1][3]="Hey, I'm CoffEEEbot, what's your name?";
dialogue[1][4]="I am CoffEEEbot, what 's your name?";

dialogue[18][0]="Nice to see you again,";
dialogue[18][1]="Have not seen you for a bit,";
dialogue[18][2]="Thanks for coming back,";
dialogue[18][3]="Nice to see you again,";
dialogue[18][4]="Nice to see you again,";

dialogue[19][0]="again for you?";
dialogue[19][1]="as usual?";
dialogue[19][2]="again for you?";
dialogue[19][3]="as usual?";
dialogue[19][4]="again for you?";


//State 2 coffee selection
dialogue[2][0]="what would you like?";
dialogue[2][1]="what drink do you want?";
dialogue[2][2]="what would you like?";
dialogue[2][3]="what would you like?";
dialogue[2][4]="what drink do you want?";

dialogue[17][0]="What would you like this time?";
dialogue[17][1]="What drink do you want this time?";
dialogue[17][2]="What would you like this time?";
dialogue[17][3]="What would you like this time?";
dialogue[17][4]="What drink do you want this time?";

//State 3 confirm coffee
dialogue[3][0]="You want a Cappuccino, right?";
dialogue[3][1]="You've ordered a Cappuccino, right";
dialogue[3][2]="Cappuccino for you, right?";
dialogue[3][3]="Cappuccino, right?";
dialogue[3][4]="You'd like a Cappuccino, right?";

//State 4 confirm coffee
dialogue[4][0]="You want a Cafe Au Lait, right?";
dialogue[4][1]="You've ordered a Cafe Au Lait, right";
dialogue[4][2]="Cafe Au Lait for you, right?";
dialogue[4][3]="Cafe Au Lait, right?";
dialogue[4][4]="You'd like a Cafe Au Lait, right?";

//State 5 confirm coffee
dialogue[5][0]="You want a Caramel Latte Macchiato, right?";
dialogue[5][1]="You've ordered a Caramel Latte Macchiato, right";
dialogue[5][2]="Caramel Latte Macchiato for you, right?";
dialogue[5][3]="Caramel Latte Macchiato, right?";
dialogue[5][4]="You'd like a Caramel Latte Macchiato, right?";

//State 6 confirm coffee
dialogue[6][0]="You want a Tea Latte, right?";
dialogue[6][1]="You've ordered a Tea Latte, right";
dialogue[6][2]="Tea Latte for you, right?";
dialogue[6][3]="Tea Latte, right?";
dialogue[6][4]="You'd like a Tea Latte, right?";

//State 7 confirm coffee
dialogue[7][0]="You want a Lungo Decaf, right?";
dialogue[7][1]="You've ordered a Lungo Decaf, right";
dialogue[7][2]="Lungo Decaf for you, right?";
dialogue[7][3]="Lungo Decaf, right?";
dialogue[7][4]="You'd like a Lungo Decaf, right?";

//State 8 introduction
dialogue[8][5]="Cappuccino is a shot of expresso combined with foam and textured milk. Do you want some recommendation?";
dialogue[8][6]="Cafe Au Lait is coffee with milk. Do you want some recommendation?";
dialogue[8][7]="Caramel Latte Macchiato is a combination of coffee, caramel and milk. Do you want some recommendation?";
dialogue[8][8]="Tea Latte is tradition tea with milk. Do you want some recommendation?";
dialogue[8][9]="Lungo Decaf is a shot of decaffinated expresso with more hot water. Do you want some recommendation?";

dialogue[8][0]="Which coffee would you like to know more about?";
dialogue[8][1]="Which coffee do you want to know?";
dialogue[8][2]="Which coffee do you want to know?";
dialogue[8][3]="Which coffee would you like to know more about?";
dialogue[8][4]="Which coffee would you like to know more about?";

//State 9 privacy
dialogue[9][0]="Would you like to be remembered?";
dialogue[9][1]="Would you want to be remembered?";
dialogue[9][2]="Do you want to be remembered?";
dialogue[9][3]="Is it ok for me to remember you?";
dialogue[9][4]="Would you like me to remember you?";

//State 10 dispenser
dialogue[10][0]="Your capsule is ready. Please follow the instruction to make yourself a wonderful coffee. Watch out for hot water";
dialogue[10][1]="Please collect your capsule. Follow the guide to make your own coffee. Watch out for hot water";
dialogue[10][2]="Your capsule is available now. Please following the instruction to make your coffee. Be careful of the hot water";
dialogue[10][3]="Your capsule is ready.Follow the guide to make your own coffee. Enjoy!";
dialogue[10][4]="Please collect your capsule. Please refer to the guide to make your coffee. Enjoy your coffee.";

//State 11 error (wrong choice)
dialogue[11][0]="Oh,I am really sorry, would you mind repeating your choice?";
dialogue[11][1]="Sorry for the mistake. Could you repeat your choice?";
dialogue[11][2]="Sorry for the wrong order. What coffee would you like?";
dialogue[11][3]="Oh, sorry. What drink were you ordering?";
dialogue[11][4]="Apologies for the mistake. Would you repeat your choice?";

//State 12 farewell
dialogue[12][0]="Thank you for coming. Have a good day.";
dialogue[12][1]="Hope to see you soon. Have a nice Christmas.";
dialogue[12][2]="It's nice to see you. I am looking forward to seeing you again.";
dialogue[12][3]="Thank you for coming.";
dialogue[12][4]="See you.";

//State 13 Recommend
dialogue[13][0]="Would you like to try ";
dialogue[13][1]="How about";
dialogue[13][2]="Do you like";
dialogue[13][3]="Would you like";
dialogue[13][4]="How do you think for";

dialogue[14][0]="good for you?";
dialogue[14][1]="alright for you?";
dialogue[14][2]="good for you?";
dialogue[14][3]="alright for you?";
dialogue[14][4]="good for you?";

dialogue[15][0]="seems to be a popular choice then. Would you like it?";
dialogue[15][1]="seems to suit you. Do you want to give it a go?";
dialogue[15][2]="seems to be a popular choice then. Would you like it?";
dialogue[15][3]="seems to suit you. Do you want to give it a go?";
dialogue[15][4]="seems to be a good choice. Do you want it?";

// ask for recommendation
dialogue[29][0]="Would you like some advice?";
dialogue[29][1]="Do you need some help choosing?";
dialogue[29][2]="Would you like some recommendation?";
dialogue[29][3]="Do you want some advice?";
dialogue[29][4]="Need some help choosing?";


return;
}


string choose_dialogue(string dialogue[][10], int a){
int b;
b= rand()%5;
return dialogue[a][b];
}
struct coffee{
    string type;
    int stock;
};
int check_stock(coffee* coffEEEbot, int out_of_stock_array[]){
    int num_out_of_stock=0;
    for(int i=0;i<5;i++){
        if (coffEEEbot[i].stock==0){
            out_of_stock_array[i]=1;
            num_out_of_stock++;
        }
        else
            out_of_stock_array[i]=0;
    }
    return num_out_of_stock;
}
/*
stock_code:
2: In Stock
1: Out of Stock
*/
int gen_stock_code(int out_of_stock_array[]){
    int stock_code=0;
    int temp[5]={1,1,1,1,1};
    for(int i=0;i<5;i++){
        if (out_of_stock_array[i]==0){
            temp[i]=2;
        }
    }
    stock_code=temp[0]*10000+temp[1]*1000+temp[2]*100+temp[3]*10+temp[4]*1;

    return stock_code;
}

