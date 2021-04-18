#include <iostream>

#include <webots/Robot.hpp>
#include <webots/Lidar.hpp>

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  Lidar* lidar = robot->getLidar("lidar"); 

  int timeStep = (int)robot->getBasicTimeStep();
  
  lidar->enable(timeStep); 
  lidar->enablePointCloud(); // Enable the point cloud computation
  
  while (robot->step(timeStep) != -1) {
    
    const LidarPoint* lidarPoints = lidar->getPointCloud(); // Get the point cloud

    // Print out the x, y, z, and layer information for the first point in the point cloud 
    cout << "x: " << lidarPoints[0].x << " y: " << lidarPoints[0].y << " z: " << lidarPoints[0].z << " layer: " << lidarPoints[0].layer_id << endl;
  }
    
  delete robot;
  return 0;
}