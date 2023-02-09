#include <vex.h>
#include<variableDefinition.h>
void base_brake(){
  BaseRF.stop(brake);
  BaseLB.stop(brake);
  BaseLM.stop(brake);
  BaseRM.stop(brake);
  BaseRB.stop(brake);
  BaseLF.stop(brake);
}
/** 
 * [move function for basic movement] 
 */ 
 //define rotational angle:
 //Counter clockwise: positive
 //Clockwise: negative
void move(double driveLeft, double driveRight){
  double minPower = 7.0;
  if(fabs(driveLeft)<minPower){
    driveLeft = 0.0;
  }
  if(fabs(driveRight)<minPower){
    driveRight = 0.0;
  }
  BaseLB.spin(forward);
  BaseRB.spin(forward);
  BaseLF.spin(forward);
  BaseRF.spin(forward);
  BaseLM.spin(forward);
  BaseRM.spin(forward);
  Brain.Timer.reset();
  BaseLB.setVelocity(driveLeft,percent);
  BaseRB.setVelocity(driveRight,percent);
  BaseLF.setVelocity(driveLeft,percent);
  BaseRF.setVelocity(driveRight,percent);
  BaseLM.setVelocity(driveLeft,percent);
  BaseRM.setVelocity(driveRight,percent);
}
void drive_left_rpm(double wheel_v){
  BaseLB.setVelocity(wheel_v,rpm);
  BaseLF.setVelocity(wheel_v,rpm);
  BaseLM.setVelocity(wheel_v,rpm);
}
void drive_right_rpm(double wheel_v){
  BaseRM.setVelocity(wheel_v,rpm);
  BaseRF.setVelocity(wheel_v,rpm);
  BaseRB.setVelocity(wheel_v,rpm);
}
void chassis_rotate(double rot_velocity){
  double lin_v = rot_velocity*(chassis_wid/2)/360;
  double wheel_v = lin_v/(wheel_rad)*60;//rpm as unit
  drive_left_rpm(-wheel_v);
  drive_right_rpm(wheel_v);
}
void turnLeft(double rot_angle){
  iner.calibrate();
  double error;
  double lastError = 0;
  double integral = 0;
  double derivative;
  double power;

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