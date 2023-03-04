#include "inertial.h"

void drive_distance(double distance, double speed = 1) { // take in distance to travel in inches and time in seconds
  iner.calibrate();
  

  // Wait for calibration to finish
  while (iner.isCalibrating()) {
    wait(50, msec);
  }
  double error;
  double lastError = 0;
  double integral = 0;
  double derivative;
  double power;
  double kP = 0.5;
  double kI = 0.05;
  double kD = 0.2;
  double tolerence = 0.8;// tolerence for terminating the loop
  int leftpos = 0;
  int rightpos = 0;

  while(true) {
    //record time
    leftpos=BaseLM.position(degrees);
    rightpos=BaseRM.position(degrees);
    error = distance-(leftpos+rightpos/2); // get driven later
    integral += error;
    derivative = error - lastError;
    power = (kP * error) + (kI * integral) + (kD * derivative);
    power = power*speed;
    BaseLB.spin(forward,power,rpm);
    BaseLM.spin(forward,power,rpm);
    BaseLF.spin(forward,power,rpm);
    BaseRB.spin(forward,power,rpm);
    BaseRM.spin(forward,power,rpm);
    BaseRF.spin(forward,power,rpm);
    

    lastError = error;
    vex::task::sleep(20);
    //get time
    //find difference
    //calculate driven through acceleration and time
  } 
  base_brake();
}

void turn(double rot_angle, bool reset=true){
  if(reset) iner.calibrate();
  double error;
  double lastError = 0;
  double integral = 0;
  double derivative;
  double power;
  double kP = 0.8;
  double kI = 0.1;
  double kD = 0.1;

  double tolerence = 5;// tolerence for terminating the loop

  do {
    error = rot_angle - iner.rotation(rotationUnits::deg);
    integral += error;
    derivative = error - lastError;
    power = kP * error + kI * integral + kD * derivative;
    power = power*50;
    //change in units
    //Add related moving mechanism to keep rotate
    chassis_rotate(power);
    
    lastError = error;
    
    vex::task::sleep(20);
  } while (fabs(error)>tolerence);
  base_brake();
}

