using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor BaseRF;
extern motor BaseRM;
extern motor BaseRB;
extern motor BaseLF;
extern motor BaseLM;
extern motor BaseLB;
extern inertial iner;
extern rotation rot_left;
extern rotation rot_right;
extern motor catapult_left;
extern motor catapult_right;
extern encoder catapult_left_encoder;
extern encoder catapult_right_encoder;
extern pneumatics catapower;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );