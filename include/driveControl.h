//basic moving mechanism
#include<autoFunctions.h>
void Drive(){
  while(true){ 
    double leftPos = Controller1.Axis4.position();
    double rightPos = Controller1.Axis2.position(); 
    
    //Move
    move(leftPos,rightPos);
  }
}
