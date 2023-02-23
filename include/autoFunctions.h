#include "basicFunctions.h"

void drive_distance(double distance, double time) { // take in distance to travel in inches and time in seconds
  double wheel_rotations = distance * M_1_PI / (2*wheel_rad);
  double wheel_v = wheel_rotations * 60 / time;
  drive_left_rpm(wheel_v);
  drive_right_rpm(wheel_v);
  wait(time,sec);
}

void turn(double rot_angle){
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

  while (fabs(error)>tolerence){
    error = rot_angle - iner.rotation(rotationUnits::deg);
    integral += error;
    derivative = error - lastError;
    power = kP * error + kI * integral + kD * derivative;
    power = power*50;
    //change in units
    //Add related moving mechanism to keep rotate
    
    
    lastError = error;
    
    vex::task::sleep(20);
  }
}

