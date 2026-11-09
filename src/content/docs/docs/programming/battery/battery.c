#include <iostream>
#include <cmath>
#include <cstring>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <webots/Emitter.hpp>
#include <webots/Receiver.hpp>

using namespace webots;
using namespace std;

Robot *robot = new Robot();
const int timeStep = (int)robot->getBasicTimeStep();
const double maxVelocity = 6.28;
const double lowBattery = 50; // Below this level (in %), replace the battery on the next contact tile

Motor *leftWheel = robot->getMotor("left wheel motor");
Motor *rightWheel = robot->getMotor("right wheel motor");
DistanceSensor *leftDist = robot->getDistanceSensor("leftDist");
DistanceSensor *frontDist = robot->getDistanceSensor("frontDist");
DistanceSensor *rightDist = robot->getDistanceSensor("rightDist");
Camera *colorSensor = robot->getCamera("color");
Emitter *emitter = robot->getEmitter("emitter");
Receiver *receiver = robot->getReceiver("receiver");

// region battery
float battery = 100; // The last battery level received, in %
double lastAsked = -1;

// Asks for the game information once a second, and keeps the battery level up to date
void readBattery() {
  if (robot->getTime() - lastAsked >= 1) {
    char message = 'G';
    emitter->send(&message, 1);
    lastAsked = robot->getTime();
  }
  while (receiver->getQueueLength() > 0) {
    const char *data = (const char *)receiver->getData();
    if (receiver->getDataSize() == 20 && data[0] == 'G') // The game information
      memcpy(&battery, data + 16, 4);
    receiver->nextPacket();
  }
}
// endregion

// region contact
bool onContactTile() {
  const unsigned char *image = colorSensor->getImage();
  int r = colorSensor->imageGetRed(image, 1, 0, 0);
  int g = colorSensor->imageGetGreen(image, 1, 0, 0);
  int b = colorSensor->imageGetBlue(image, 1, 0, 0);
  return r < 60 && g > 200 && b > 200; // Cyan
}

// Keeps the same speeds for a number of milliseconds
void drive(double left, double right, double ms) {
  leftWheel->setVelocity(left);
  rightWheel->setVelocity(right);
  double start = robot->getTime();
  while (robot->step(timeStep) != -1 && (robot->getTime() - start) * 1000 < ms)
    readBattery();
}

void replaceBattery() {
  // The colour sensor is at the front: drive on, so that the centre of the robot is on the tile
  drive(0.5 * maxVelocity, 0.5 * maxVelocity, 1000);
  cout << "Replacing the battery at " << battery << " %" << endl;
  leftWheel->setVelocity(0);
  rightWheel->setVelocity(0);
  double start = robot->getTime();
  // Stay still until the battery is full, which takes 5 seconds
  while (robot->step(timeStep) != -1 && battery < 100 && robot->getTime() - start < 8)
    readBattery();
  cout << "Battery: " << battery << " %" << endl;
}
// endregion

// region loop
int main() {
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);
  leftDist->enable(timeStep);
  frontDist->enable(timeStep);
  rightDist->enable(timeStep);
  colorSensor->enable(timeStep);
  receiver->enable(timeStep);

  while (robot->step(timeStep) != -1) {
    readBattery();
    if (onContactTile() && battery < lowBattery)
      replaceBattery();

    double left = maxVelocity, right = maxVelocity;
    if (frontDist->getValue() < 0.05) { // Wall in front: spin
      left = 0.6 * maxVelocity;
      right = -0.6 * maxVelocity;
    } else if (leftDist->getValue() < 0.05) { // Wall on the left: turn right
      left = 0.6 * maxVelocity;
      right = -0.2 * maxVelocity;
    } else if (rightDist->getValue() < 0.05) { // Wall on the right: turn left
      left = -0.2 * maxVelocity;
      right = 0.6 * maxVelocity;
    }
    leftWheel->setVelocity(left);
    rightWheel->setVelocity(right);
  }

  delete robot;
  return 0;
}
// endregion
