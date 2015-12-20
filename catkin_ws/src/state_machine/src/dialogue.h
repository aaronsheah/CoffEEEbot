#ifndef dialogue_H
#define dialogue_H

//#include <iostream>
//#include <string>
//#include <cstdlib>

string dialogue[20][10];

//State 0 advertisement
string dialogue[0][0]="Coffee, anyone?";
string dialogue[0][1]="Anyone want a coffee?";
string dialogue[0][2]="Do you want a coffee?";
string dialogue[0][3]="Coffee here, coffee here.";
string dialogue[0][4]="Come and get a coffee";

//State 1 greeting
string dialogue[1][0]="Hello, I am CoffEEEbot. what would you like?";
string dialogue[1][1]="Hi, my name is CoffEEEbot, what drink do you want?";
string dialogue[1][2]="Nice to meet you. I am CoffEEEbot, what coffee would you like?";
string dialogue[1][3]="Hey, I'm CoffEEEbot, what would you like?";
string dialogue[1][4]="I am CoffEEEbot, what would you like?";

//State 2 coffee selection
string dialogue[2][0]="What would you like?";
string dialogue[2][1]="What drink do you want?";
string dialogue[2][2]="What would you like?";
string dialogue[2][3]="";
string dialogue[2][4]="";

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
dialogue[8][0]="Cappuccino is \n";
dialogue[8][1]="Cafe Au Lait is \n";
dialogue[8][2]="Caramel Latte Macchiato \n";
dialogue[8][3]="Tea Latte is \n";
dialogue[8][4]="Lungo Decaf is \n";

//State 9 privacy
dialogue[9][0]="Would you like to be remembered?";
dialogue[9][1]="Would you mind being remembered?";
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

//State 12 privacy
dialogue[12][0]="Thank you for coming. Have a good day.";
dialogue[12][1]="Hope to see you soon. Have a nice Christmas.";
dialogue[12][2]="It's nice to see you. I am looking forward to seeing you again.";
dialogue[12][3]="Thank you for coming.";
dialogue[12][4]="See you.";
#endif




