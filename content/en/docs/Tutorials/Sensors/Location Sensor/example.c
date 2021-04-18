#include <iostream>
#include <math.h>

#include <webots/Robot.hpp>
#include <webots/GPS.hpp> 

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  GPS* gps = robot->getGPS("gps");

  int timeStep = (int)robot->getBasicTimeStep();
  
  gps->enable(timeStep);

  robot->step(timeStep); // Must step once to update sensor reading
  double startX = gps->getValues()[0]; // Store initial robot position
  double startZ = gps->getValues()[2];

  while (robot->step(timeStep) != -1) {
  
    double x = gps->getValues()[0]; 
    double z = gps->getValues()[2]; 
    
    double dist = sqrt(pow(x-startX, 2) + pow(z-startZ, 2)); // Use the distance formula to calculate distance to starting position
    
    cout << "Distance from starting location: " << dist << endl;
  }

  delete robot;
  return 0;
}