#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Lidar.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Lidar *lidar = robot->getLidar("lidar");
  lidar->enable(timeStep);
  lidar->enablePointCloud(); // Computing the point cloud takes extra time

  while (robot->step(timeStep) != -1) {
    const LidarPoint *points = lidar->getPointCloud();
    const LidarPoint &point = points[0]; // Positions relative to the lidar, in meters
    cout << "x: " << point.x << " y: " << point.y << " z: " << point.z << " layer: " << point.layer_id << endl;
  }

  delete robot;
  return 0;
}
