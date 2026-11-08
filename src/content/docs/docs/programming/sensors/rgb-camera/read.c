#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Camera *camera = robot->getCamera("camera");
  camera->enable(timeStep);
  int width = camera->getWidth();
  int height = camera->getHeight();
  cout << "The camera has " << width << " x " << height << " pixels" << endl;

  while (robot->step(timeStep) != -1) {
    const unsigned char *image = camera->getImage();
    // The colour of the pixel in the center of the image
    int r = Camera::imageGetRed(image, width, width / 2, height / 2);
    int g = Camera::imageGetGreen(image, width, width / 2, height / 2);
    int b = Camera::imageGetBlue(image, width, width / 2, height / 2);
    cout << "Center: " << r << " " << g << " " << b << endl;
  }

  delete robot;
  return 0;
}
