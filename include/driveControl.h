//basic moving mechanism
#include<autoFunctions.h>
void Drive(){
  while(true){ 
    double leftPos = Controller1.Axis3.position();
    double rightPos = Controller1.Axis2.position(); 

    intake(Controller1.ButtonR1.pressing()); //intake control

    if (Controller1.ButtonL1.pressing()) shoot();
    
    //Move
    move(leftPos,rightPos);
  }
}
