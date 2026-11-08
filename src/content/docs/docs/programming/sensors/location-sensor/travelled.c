#include <iostream>
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/GPS.hpp>
#include <webots/Motor.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  GPS *gps = robot->getGPS("gps");
  gps->enable(timeStep);
  Motor *leftWheel = robot->getMotor("left wheel motor");
  Motor *rightWheel = robot->getMotor("right wheel motor");
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);

  robot->step(timeStep); // Step once, so that the GPS has a value
  double startX = gps->getValues()[0], startZ = gps->getValues()[2];

  leftWheel->setVelocity(3.0);
  rightWheel->setVelocity(3.0);

  while (robot->step(timeStep) != -1) {
    double x = gps->getValues()[0], z = gps->getValues()[2];
    double distance = sqrt(pow(x - startX, 2) + pow(z - startZ, 2));
    cout << "Distance from the start: " << distance << " m" << endl;
    if (distance > 0.06) { // Half a tile
      leftWheel->setVelocity(0);
      rightWheel->setVelocity(0);
      break;
    }
  }

  delete robot;
  return 0;
}
