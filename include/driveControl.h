//basic moving mechanism
#include<autoFunctions.h>
int invert = -1;
void changeInvert(){
  invert = -invert;
}
void Drive(){
  
  while(true){ 
    if(Controller1.ButtonY.pressing()){
      drive_distance(tile_width);
    };
    double leftPos = invert*Controller1.Axis3.position();
    double rightPos = invert*Controller1.Axis2.position(); 

    intake(Controller1.ButtonR1.pressing()); //intake control
    if (Controller1.ButtonL1.pressing()) shoot();
    
    //Move
    move(leftPos,rightPos);

  }
}
