#include <iostream>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  DistanceSensor *frontDist = robot->getDistanceSensor("frontDist"); // Get the sensor by name
  frontDist->enable(timeStep);                                        // Enable it

  while (robot->step(timeStep) != -1)
    cout << "Front: " << frontDist->getValue() << " m" << endl;

  delete robot;
  return 0;
}
