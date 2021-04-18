#include <iostream>
#include <string> // Use the C++ string library for string manipulation

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  DistanceSensor* distanceSensors[8]; // Create an array containing 8 distance sensors

  int timeStep = (int)robot->getBasicTimeStep();
  
  for(int i = 0; i < 8; i++) {
  
    // Retrieve an enable the distance sensors named ps0, ps1, ps2, etc...
    distanceSensors[i] = robot->getDistanceSensor("ps" + to_string(i));
    distanceSensors[i]->enable(timeStep);  
  }

  while (robot->step(timeStep) != -1) {

    // Print the values of the 8 distance sensors
    for(int i = 0; i < 8; i++) {
      
      double distance = distanceSensors[i]->getValue();
      cout << "Distance " << i << ": " << distance << endl;
    }
  }

  delete robot;
  return 0;
}