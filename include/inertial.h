#include <basicFunctions.h>

double facing; 
double yaw_angle;
double x_accel;
double y_accel;
double x_velocity;
double y_velocity;
double x_position;
double y_position;


void inertial() {
  //we want position (theta), direction we're facing, and velocity(?)
  while(true)
  {
    facing = iner.heading(deg); //gets yaw heading 0-360
    yaw_angle = iner.rotation(deg); 
    x_accel = iner.acceleration(xaxis);
    y_accel = iner.acceleration(yaxis);
    double x_accel_inch = acceleration_convertor(x_accel);
    double y_accel_inch = acceleration_convertor(y_accel);
    x_velocity += x_accel_inch*(0.02);
    y_velocity += y_accel_inch*(0.02);
    x_position += x_velocity*(0.02);
    y_position += y_velocity*(0.02);
    vex::task::sleep(20);
  }

}
