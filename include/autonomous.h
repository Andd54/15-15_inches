#include<driveControl.h>
//shoot all the matchloads
double shooting_radius = 53;
double angles [] = {-71.0,47.0,-95.0,-27.0,61.0,-25.0,-35.0,-90.0,90.0,-90.0};
double drive_dis[]={39, -21, 22, 34, -12, 48, 16, -13, -24, 30, 3*tile_width};
void autonomous(){
  int drive_index = 0;
  int angle_index = 0;
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  shoot();
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  shoot();
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  //spin the roller
  drive_distance(drive_dis[drive_index++]);
  turn(angles[angle_index++]);
  drive_distance(drive_dis[drive_index++]);
  //spin the roller


}

