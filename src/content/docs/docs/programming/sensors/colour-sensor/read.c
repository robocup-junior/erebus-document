#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Camera *colorSensor = robot->getCamera("color");
  colorSensor->enable(timeStep);

  while (robot->step(timeStep) != -1) {
    const unsigned char *image = colorSensor->getImage(); // A single pixel
    int r = Camera::imageGetRed(image, 1, 0, 0);
    int g = Camera::imageGetGreen(image, 1, 0, 0);
    int b = Camera::imageGetBlue(image, 1, 0, 0);
    cout << "r: " << r << " g: " << g << " b: " << b << endl;
  }

  delete robot;
  return 0;
}
