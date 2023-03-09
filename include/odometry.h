#include <vex.h>
#include <variableDefinition.h>

void odometry() {
  double prev_left = rot_left.position(deg);
  double prev_right = rot_right.position(deg);
  double prev_back = rot_back.position(deg);
  double theta = 0;
  double prev_theta = 0;
  double local_delta_x = 0;
  double local_delta_y = 0;
  double average_theta = 0;
  double absolute_x = 0;
  double absolute_y = 0;
  while(true) {
    double left = rot_left.position(deg);
    double right = rot_right.position(deg);
    double back = rot_back.position(deg);

    double delta_L = (left - prev_left)*wheel_rad*M_PI/18000;
    double delta_R = (right - prev_right)*wheel_rad*M_PI/18000;
    double delta_S = (back - prev_back)*wheel_rad*M_PI/18000;

    prev_left = left;
    prev_right = right;
    prev_back = back;
    prev_theta = theta;

    theta = (delta_L - delta_R) / chassis_wid;
    double delta_theta = theta - prev_theta;

    if(delta_theta == 0) {
      local_delta_x = delta_S;
      local_delta_y = delta_R;
    }
    else {
      local_delta_x = 2 * sin(delta_theta / 2) * (delta_S/delta_theta + chassis_wid/2);
      local_delta_y = 2 * sin(delta_theta / 2) * (delta_R/delta_theta + chassis_wid/2);
    }

    average_theta = prev_theta + delta_theta / 2;

    double r = sqrt(local_delta_x*local_delta_x + local_delta_y*local_delta_y);
    double phi = atan2(local_delta_y, local_delta_x);
    phi = phi - average_theta;
    double delta_x = r*cos(phi);
    double delta_y = r*sin(phi);

    absolute_x += delta_x;
    absolute_y += delta_y;
  }
}