#include <iostream>

#include <webots/Robot.hpp>
#include <webots/GPS.hpp> // Step 1: Include GPS Header

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  GPS* gps = robot->getGPS("gps"); // Step 2: Retrieve the sensor, named "gps", from the robot. Note that the sensor name may differ between robots.

  int timeStep = (int)robot->getBasicTimeStep();
  
  gps->enable(timeStep); // Step 3: Enable the sensor, using the timestep as the update rate

  while (robot->step(timeStep) != -1) {
  
    double x = gps->getValues()[0]; // Step 4: use the getValues() function to get the sensor reading
    double y = gps->getValues()[1]; // Note that the gps returns an array of 3 values for x, y, z, position 
    double z = gps->getValues()[2]; 
    
    cout << "x: " << x << " y: " << y << " z: " << z << endl; // Print out the values of the sensor
  }

  delete robot;
  return 0;
}