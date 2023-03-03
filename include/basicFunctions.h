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

void catapult_reset() {
  catapult_left_encoder.resetRotation();
  catapult_right_encoder.resetRotation();
}

void catapult_full_rotation() {
  if (!catapult_stop) {
    catapult_left.rotateTo(360*catapult_ratio, deg, 200, rpm);
    catapult_right.rotateTo(360*catapult_ratio, deg, 200, rpm);
  }
}

void shoot(bool power=false) {
  catapower.set(power); //comment this line out if no pneumatics
  catapult_full_rotation();
}

void intake() {
  intake_left.rotateFor(500, msec, 50, rpm);
  intake_right.rotateFor(500, msec, 50, rpm);
}

void intake(bool on) {
  if(on) {
    intake_left.setVelocity(50, rpm);
    intake_right.setVelocity(50, rpm);
  }
  else {
    intake_left.stop();
    intake_right.stop();
  }
}

double velocity_to_rpm(double vel) {
  return 60*vel/wheel_circumference;
}

double rpm_to_velocity(double rpm) {
  return wheel_circumference*rpm/60;
}

double acceleration_convertor(double Gs) {
  return Gs*386.2205;
}
