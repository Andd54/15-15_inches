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
void rotate(){
//empty function that needs more #thinking
}
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
void turnLeft(double rot_angle){
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
    
    //Add related moving mechanism to keep rotate
    
    
    lastError = error;
    
    vex::task::sleep(20);
  }
}