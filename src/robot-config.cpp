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
inertial iner = inertial(PORT20);
//above is the motors for chassis
rotation rot_right = rotation(PORT5, true);
rotation rot_left = rotation(PORT4, false);
// rotation sensors for left and right wheels
motor catapult_right = motor(PORT12, ratio18_1, true);
motor catapult_left = motor(PORT11, ratio18_1, false);
// motor for catapult
encoder catapult_left_encoder = encoder(Brain.ThreeWirePort.A);
encoder catapult_right_encoder = encoder(Brain.ThreeWirePort.B);
// encoder for catapult motors
pneumatics catapower = pneumatics(Brain.ThreeWirePort.C);
// VEXcode generated functions
motor intake_right = motor(PORT13, ratio18_1, false);
motor intake_left = motor(PORT14, ratio18_1, false);
// define variable for remote controller enable/disable

limit catapult_stop = limit(Brain.ThreeWirePort.D);
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}