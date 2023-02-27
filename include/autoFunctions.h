#include "inertial.h"

void drive_distance(double distance, double speed) { // take in distance to travel in inches and time in seconds
  iner.calibrate();
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
    //record time
    error = distance - y_position; // get driven later
    integral += error;
    derivative = error - lastError;
    power = kP * error + kI * integral + kD * derivative;
    power = power*speed;

    drive_left_rpm(power);
    drive_right_rpm(power);

    lastError = error;
    vex::task::sleep(20);
    //get time
    //find difference
    //calculate driven through acceleration and time
  } while(fabs(error)>tolerence);
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

