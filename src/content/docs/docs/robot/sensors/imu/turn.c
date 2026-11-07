#include <cmath>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Gyro.hpp>

using namespace webots;

Robot *robot;
Motor *leftMotor, *rightMotor;
Gyro *gyro;
int timeStep;

void turnLeft(double angle) {
  double turned = 0;
  leftMotor->setVelocity(-2);
  rightMotor->setVelocity(2);
  while (fabs(turned) < angle && robot->step(timeStep) != -1)
    turned += gyro->getValues()[1] * timeStep / 1000.0; // Speed multiplied by the time, in seconds
  leftMotor->setVelocity(0);
  rightMotor->setVelocity(0);
}

int main() {
  robot = new Robot();
  timeStep = (int)robot->getBasicTimeStep();

  leftMotor = robot->getMotor("wheel1 motor");
  rightMotor = robot->getMotor("wheel2 motor");
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);

  gyro = robot->getGyro("gyro");
  gyro->enable(timeStep);

  turnLeft(M_PI / 2);

  delete robot;
  return 0;
}
