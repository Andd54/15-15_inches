/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neil                                             */
/*    Created:      Sun Nov 06 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// BaseRF               motor         1               
// BaseRM               motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

//include the autonomous 
#include "vex.h"
#include<autonomous.h>
using namespace vex;
<<<<<<< HEAD
competition Competition;
void autonomous(void){
  //insert function in autonomous.h here
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
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  while(true){
    wait(100,msec);
  }
=======

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //fun update yay wow
  
>>>>>>> b30dd73b003f2725b6e2370e4118cc5d282bbb3d
}
