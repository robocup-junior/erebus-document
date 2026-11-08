#include <iostream>
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  // Get the devices of the starter robot by name
  Motor *leftWheel = robot->getMotor("left wheel motor");
  Motor *rightWheel = robot->getMotor("right wheel motor");
  DistanceSensor *frontDist = robot->getDistanceSensor("frontDist");

  // Sensors must be enabled before use
  frontDist->enable(timeStep);

  // Let the wheels turn without limit, and start driving forward
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);
  leftWheel->setVelocity(3.0);
  rightWheel->setVelocity(3.0);

  // The main loop: each step, the simulation advances by timeStep milliseconds
  while (robot->step(timeStep) != -1) {
    double distance = frontDist->getValue();
    cout << "Distance to the wall in front: " << distance << " m" << endl;

    if (distance < 0.05) { // Closer than 5 cm: stop
      leftWheel->setVelocity(0);
      rightWheel->setVelocity(0);
      cout << "Wall reached!" << endl;
      break;
    }
  }

  delete robot;
  return 0;
}
