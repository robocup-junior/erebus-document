#include <iostream>

#include <webots/Robot.hpp>
#include <webots/Lidar.hpp> // Step 1: Include Lidar

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  Lidar* lidar = robot->getLidar("lidar"); // Step 2: Retrieve the sensor, named "lidar", from the robot. Note that the sensor name may differ between robots.

  int timeStep = (int)robot->getBasicTimeStep();
  
  lidar->enable(timeStep); // Step 3: Enable the sensor, using the timestep as the update rate
  
  while (robot->step(timeStep) != -1) {
    
    const float *rangeImage = lidar->getRangeImage(); // Step 4: Retrieve the range image
    for(int i = 0; i < 10; i++) {
    
      // Print the first 10 values of the range image.
      // The range image stores the distances from left to right, from first to last layer
      cout << rangeImage[i] << " ";
    }
    
    cout << endl << endl;
  }
    
  delete robot;
  return 0;
}