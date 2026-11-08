#include <iostream>
#include <webots/Robot.hpp>
#include <webots/GPS.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  GPS *gps = robot->getGPS("gps");
  gps->enable(timeStep);

  while (robot->step(timeStep) != -1) {
    const double *position = gps->getValues(); // In meters. X and Z are horizontal, Y is vertical.
    cout << "x: " << position[0] << " z: " << position[2] << endl;
  }

  delete robot;
  return 0;
}
