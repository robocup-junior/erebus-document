#include <iostream>
#include <cmath>
#include <cstring>
#include <webots/Robot.hpp>
#include <webots/Emitter.hpp>
#include <webots/GPS.hpp>
#include <webots/Motor.hpp>

using namespace webots;

Robot *robot;
Emitter *emitter;
GPS *gps;
Motor *leftWheel, *rightWheel;
int timeStep;

void wait(double seconds) {
  double start = robot->getTime();
  while (robot->step(timeStep) != -1) {
    if (robot->getTime() - start >= seconds)
      break;
  }
}

void report(char tokenType) {
  // 1. Stop for more than 1 second
  leftWheel->setVelocity(0);
  rightWheel->setVelocity(0);
  wait(1.2);
  // 2. Send the position in centimeters, and the type as one letter
  int position[2] = {(int)(gps->getValues()[0] * 100), (int)(gps->getValues()[2] * 100)};
  char message[9];
  memcpy(message, position, sizeof(position));
  message[8] = tokenType;
  emitter->send(message, sizeof(message));
  robot->step(timeStep);
}

int main() {
  robot = new Robot();
  timeStep = (int)robot->getBasicTimeStep();

  emitter = robot->getEmitter("emitter"); // Always on the robot. It does not need to be enabled.
  gps = robot->getGPS("gps");
  gps->enable(timeStep);
  leftWheel = robot->getMotor("left wheel motor");
  rightWheel = robot->getMotor("right wheel motor");
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);

  report('H'); // Reports a harmed victim (sad face) where the robot is
  std::cout << "Reported" << std::endl;

  delete robot;
  return 0;
}
