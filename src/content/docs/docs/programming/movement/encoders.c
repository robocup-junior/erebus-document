#include <iostream>
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Motor *leftWheel = robot->getMotor("left wheel motor");
  Motor *rightWheel = robot->getMotor("right wheel motor");
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);

  // Each wheel has a position sensor, which counts how far it has turned
  PositionSensor *leftEncoder = leftWheel->getPositionSensor();
  PositionSensor *rightEncoder = rightWheel->getPositionSensor();
  leftEncoder->enable(timeStep);
  rightEncoder->enable(timeStep);

  robot->step(timeStep); // Step once, so that the sensors have a value
  double start = leftEncoder->getValue();

  leftWheel->setVelocity(5.0);
  rightWheel->setVelocity(5.0);

  while (robot->step(timeStep) != -1) {
    double turned = leftEncoder->getValue() - start;
    if (turned > 10.0) // Stop after 10 radians
      break;
  }

  leftWheel->setVelocity(0);
  rightWheel->setVelocity(0);
  cout << "Left wheel: " << leftEncoder->getValue() - start << " rad" << endl;

  delete robot;
  return 0;
}
