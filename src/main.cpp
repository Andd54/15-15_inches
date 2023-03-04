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
void autonomous(void){
  trial();
}
void usercontrol(void){
  while(1){
    Drive();
  }
}
int main() {
  vexcodeInit();
  // Initializing Robot Configuration. DO NOT REMOVE!
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  
}
