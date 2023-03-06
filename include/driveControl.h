//basic moving mechanism
#include<autoFunctions.h>
void Drive(){
  while(true){ 
    double leftPos = -1*Controller1.Axis3.position();
    double rightPos = -1*Controller1.Axis2.position(); 

    // intake(Controller1.ButtonL1.pressing(), Controller1.ButtonL1.pressing()||Controller1.ButtonR1.pressing()); //intake control
    if (Controller1.ButtonL1.pressing()) {
      intake_left.spin(forward);
      intake_right.spin(forward);
      Brain.Timer.reset();
      intake_left.setVelocity(200, rpm);
      intake_right.setVelocity(200, rpm);
    }
    else {
      intake_left.stop();
      intake_right.stop();
    }

    if (Controller1.ButtonX.pressing()) {
      expansion.spinTo(90, deg, 200, rpm);  
      expansion.resetPosition();  
    }

    if (Controller1.ButtonA.pressing()) {
      expansion2.spinTo(90, deg, 200, rpm);
      expansion2.resetPosition();
    }
    
    //if (Controller1.ButtonR1.pressing()) shoot();
    
    //Move
    move(leftPos,rightPos);
  }
}
