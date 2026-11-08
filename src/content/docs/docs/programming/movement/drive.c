#include <iostream>
#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

Robot *robot;
Motor *leftWheel, *rightWheel;
int timeStep;
const double maxSpeed = 6.28; // The maximum speed of the wheels, in radians per second

// Set the speed of each wheel, and keep it for some time
void drive(double left, double right, double seconds) {
  leftWheel->setVelocity(left);
  rightWheel->setVelocity(right);
  double start = robot->getTime();
  while (robot->step(timeStep) != -1) {
    if (robot->getTime() - start >= seconds)
      break;
  }
}

int main() {
  robot = new Robot();
  timeStep = (int)robot->getBasicTimeStep();

  leftWheel = robot->getMotor("left wheel motor");
  rightWheel = robot->getMotor("right wheel motor");
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);

  drive(maxSpeed, maxSpeed, 1.0);   // Forward
  drive(-maxSpeed, -maxSpeed, 1.0); // Backward
  drive(-2.0, 2.0, 1.0);            // Spin to the left
  drive(0, 0, 0.1);                 // Stop
  std::cout << "Done" << std::endl;

  delete robot;
  return 0;
}
