#include<driveControl.h>
//shoot all the matchloads
double shooting_radius = 53;
<<<<<<< HEAD
double angles [] = {-71.0, 51, -86, -27.0, 61.0, -25.0, -35.0, 45, -90, 90.0, -90.0, 7.0, -71.0, 43, -86, -27.0, 61.0, -10, 10, -10, 10, -31,-76};
double drive_dis[]={39, -21, 22, 34, -12, 48, 16, -13, -24, 30, tile_width, -0.25*tile_width, 2*tile_width};
void auton(){
=======
double angles [] = {-71.0, 47.0, 43, -86, -27.0, 61.0, -25.0, -35.0, 45, -90, 90.0, -90.0, 7.0, -71.0, 47.0, 43, -86, -27.0, 61.0, -10, 10, -10, 10, -31,-76};

double drive_dis[]={39, -21, 22, 34, -12, 48, 16, -13, -24, 30, 3*tile_width};
void _autonomous(){
>>>>>>> 9e8ba3453feb334c7ddf6030caeac3ce324df748
  int drive_index = 0;
  int angle_index = 0;
  wait(2,seconds);
  shoot();
  wait(2,seconds);
  shoot();
  wait(2,seconds);
  shoot();
  intake(true);
  //end of first shooting at loading zone
  turn(angles[angle_index++]);//angle_index = 0
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 0
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 1
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 1
  wait(10,msec);
  intake(false);
  shoot();
  turn(angles[angle_index++]);//angle_index = 2
  wait(10,msec);
  intake(true);
  drive_distance(drive_dis[drive_index++]);//drive_index = 2
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 3
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 3
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 4
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 4
  intake(false);
  wait(10,msec);
  shoot();
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 5
  intake(true);
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 5
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 6
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 6
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 7
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 7
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 8
  wait(10,msec);
  intake(false);
  drive_distance(drive_dis[drive_index++]);//drive_index = 8
  wait(10,msec);
  spin();
  //spin the roller
  drive_distance(drive_dis[drive_index++]);//drive_index = 9
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 9
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 10
  wait(10,msec);
  spin();
  //spin the roller
  drive_distance(drive_dis[drive_index++]);//drive_index = 11
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 10
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 12
  
  turn(angles[angle_index++]);//angle_index = 11
  
  wait(2,seconds);
  shoot();
  wait(2,seconds);
  shoot();
  wait(2,seconds);
  shoot();
  
  intake(true);
  drive_distance(drive_dis[drive_index++]);//drive_index = 13
  turn(angles[angle_index++]);//angle_index = 12
  intake(false);
  drive_distance(drive_dis[drive_index++]);//drive_index = 14
  wait(10,msec);
  shoot();
  turn(angles[angle_index++]);//angle_index = 13
  intake(true);
  drive_distance(drive_dis[drive_index++]);//drive_index = 15
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 14
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 16
  wait(10,msec);
  turn(angles[angle_index++]);//angle_index = 15
  wait(10,msec);
  drive_distance(drive_dis[drive_index++]);//drive_index = 17
  wait(10,msec);
  shoot();

}

