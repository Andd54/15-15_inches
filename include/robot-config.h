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
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );