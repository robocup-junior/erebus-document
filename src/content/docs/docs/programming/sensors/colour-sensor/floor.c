#include <iostream>
#include <cmath>
#include <string>
#include <webots/Robot.hpp>
#include <webots/Camera.hpp>
#include <webots/Motor.hpp>

using namespace webots;
using namespace std;

// Tune these ranges for your own robot and worlds
string floorType(int r, int g, int b) {
  int brightness = (r + g + b) / 3;
  if (brightness < 80)
    return "hole";
  if (r > 200 && g > 170 && b < 150)
    return "swamp";
  if (r < 60 && g > 200 && b > 200)
    return "contact tile";
  if (b > 220 && g < 130)
    return r > 150 ? "purple passage" : "blue passage";
  if (r > 220 && g < 130 && b < 130)
    return "red passage";
  if (g > 220 && r < 100 && b < 100)
    return "green passage";
  return "floor";
}

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Camera *colorSensor = robot->getCamera("color");
  colorSensor->enable(timeStep);
  Motor *leftWheel = robot->getMotor("left wheel motor");
  Motor *rightWheel = robot->getMotor("right wheel motor");
  leftWheel->setPosition(INFINITY);
  rightWheel->setPosition(INFINITY);

  leftWheel->setVelocity(3.0);
  rightWheel->setVelocity(3.0);
  string last;

  while (robot->step(timeStep) != -1) {
    const unsigned char *image = colorSensor->getImage();
    string floor = floorType(Camera::imageGetRed(image, 1, 0, 0), Camera::imageGetGreen(image, 1, 0, 0),
                             Camera::imageGetBlue(image, 1, 0, 0));
    if (floor != last) {
      cout << "Floor: " << floor << endl;
      last = floor;
    }
    if (floor == "hole") { // Stop before falling in
      leftWheel->setVelocity(0);
      rightWheel->setVelocity(0);
      break;
    }
  }

  delete robot;
  return 0;
}
