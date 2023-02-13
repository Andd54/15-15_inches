#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor BaseRF = motor(PORT1, ratio18_1, true);
motor BaseRM = motor(PORT2, ratio18_1, true);
motor BaseRB = motor(PORT3, ratio18_1, true);
motor BaseLF = motor(PORT4, ratio18_1, false);
motor BaseLM = motor(PORT5, ratio18_1, false);
motor BaseLB = motor(PORT6, ratio18_1, false);
// 'L' stands for left, 'R' stands for right; 'F' stands for front, 'M' stands for middle' 'B' stands for back
inertial iner = inertial(PORT10);
//above is the motors for chassis
rotation rot_left = rotation(PORT4);
rotation rot_right = rotation(PORT5);
// rotation sensors for left and right wheels
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}