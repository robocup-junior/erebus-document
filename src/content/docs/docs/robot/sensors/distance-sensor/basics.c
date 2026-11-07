#include <iostream>

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp> // Step 1: Include DistanceSensor

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  DistanceSensor* distanceSensor = robot->getDistanceSensor("ps0"); // Step 2: Retrieve the sensor, named "ps0", from the robot. Note that the sensor name may differ between robots.

  int timeStep = (int)robot->getBasicTimeStep();
  
  distanceSensor->enable(timeStep); // Step 3: Enable the sensor, using the timestep as the update rate

  while (robot->step(timeStep) != -1) {
  
    double distance = distanceSensor->getValue(); // Step 4: use the getValue() function to get the sensor reading
    cout << "Distance: " << distance << endl; // Print out the value of the sensor
  }

  delete robot;
  return 0;
}