#include "basicFunctions.h"

void drive_distance(double distance, double time) { // take in distance to travel in inches and time in seconds
  double wheel_rotations = distance * M_1_PI / (2*wheel_rad);
  double wheel_v = wheel_rotations * 60 / time;
  drive_left_rpm(wheel_v);
  drive_right_rpm(wheel_v);
  wait(time,sec);
}