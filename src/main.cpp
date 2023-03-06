/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       IRobotics VEXU team                                       */
/*    Created:      Sun Nov 06 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [15 inches]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

//include the autonomous 
#include "vex.h"
#include<autonomous.h>
using namespace vex;
competition Competition;
void auton(void){
  //_autonomous();
  for(int i=0; i<2; i++) {
    drive_left_rpm(100);
    drive_right_rpm(100);
    wait(60000*tile_width*2/(100*wheel_circumference), msec);
    drive_left_rpm(-100);
    drive_right_rpm(-100);
    wait(60000*tile_width*2/(100*wheel_circumference), msec);
    move(0, 0);
  }

  // chassis_rotate(100);
  // wait(1000, msec);
  // move(0, 0);
  // expansion.spinTo(90, deg, 200, rpm);  
  // expansion.resetPosition(); 
  // wait(1000, msec);
  // expansion.stop();
  // expansion2.spinTo(90, deg, 200, rpm);
  // expansion2.resetPosition();
}
void usercontrol(void){
  while(1){
    Drive();
    wait(20,msec);
  }
}
int main() {
  vexcodeInit();
  // Initializing Robot Configuration. DO NOT REMOVE!
  Competition.autonomous(auton);
  Competition.drivercontrol(usercontrol);
  
  while(true){
    wait(100,msec);
  }
}
