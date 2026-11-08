// region setup
#include <array>
#include <cmath>
#include <cstring>
#include <vector>
#include <opencv2/opencv.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <webots/Emitter.hpp>
#include <webots/GPS.hpp>

using namespace webots;
using namespace std;

Robot *robot = new Robot();
const int timeStep = 32;          // Milliseconds between steps
const double maxVelocity = 6.28;  // The maximum speed of the wheels, in radians per second

Motor *leftWheel = robot->getMotor("left wheel motor");
Motor *rightWheel = robot->getMotor("right wheel motor");

double speeds[2] = {maxVelocity, maxVelocity}; // {left wheel speed, right wheel speed}
vector<array<int, 2>> reported;                // Positions where a token has already been reported
// endregion

// region sensors
DistanceSensor *leftDist = robot->getDistanceSensor("leftDist");
DistanceSensor *frontDist = robot->getDistanceSensor("frontDist");
DistanceSensor *rightDist = robot->getDistanceSensor("rightDist");
Camera *camera = robot->getCamera("camera");
Camera *colorSensor = robot->getCamera("color");
GPS *gps = robot->getGPS("gps");
Emitter *emitter = robot->getEmitter("emitter"); // The emitter does not need to be enabled

void enableSensors() {
  leftDist->enable(timeStep);
  frontDist->enable(timeStep);
  rightDist->enable(timeStep);
  camera->enable(timeStep);
  colorSensor->enable(timeStep);
  gps->enable(timeStep);
}
// endregion

// region moves
void turnRight() {
  speeds[0] = 0.6 * maxVelocity;
  speeds[1] = -0.2 * maxVelocity;
}

void turnLeft() {
  speeds[0] = -0.2 * maxVelocity;
  speeds[1] = 0.6 * maxVelocity;
}

void spin() {
  speeds[0] = 0.6 * maxVelocity;
  speeds[1] = -0.6 * maxVelocity;
}

void delay(int ms) {
  double start = robot->getTime();
  while (robot->step(timeStep) != -1) {
    if ((robot->getTime() - start) * 1000 > ms)
      break;
  }
}

int getBrightness() {
  const unsigned char *image = colorSensor->getImage();
  return Camera::imageGetGray(image, colorSensor->getWidth(), 0, 0); // 0 (black) to 255 (white)
}
// endregion

// region detect
bool seesToken(const unsigned char *image) {
  int height = camera->getHeight(), width = camera->getWidth();
  cv::Mat frame(height, width, CV_8UC4, (void *)image); // BGRA image for OpenCV
  cv::Mat gray, bright;
  cv::cvtColor(frame, gray, cv::COLOR_BGRA2GRAY);
  cv::threshold(gray, bright, 200, 255, cv::THRESH_BINARY); // Bright parts in white
  vector<vector<cv::Point>> contours;
  cv::findContours(bright, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
  for (const auto &contour : contours) {
    cv::Rect box = cv::boundingRect(contour);
    if (box.x == 0 || box.y == 0 || box.x + box.width == width || box.y + box.height == height)
      continue; // Shapes touching the edge of the image are usually the floor
    double ratio = (double)box.width / box.height;
    if (cv::contourArea(contour) > 40 && ratio > 0.65 && ratio < 1.5)
      return true; // A bright, roughly square shape on a wall
  }
  return false;
}
// endregion

// region report
void report(char tokenType) {
  leftWheel->setVelocity(0); // Stop for more than 1 second
  rightWheel->setVelocity(0);
  delay(1300);
  int x = (int)(gps->getValues()[0] * 100); // Meters to centimeters
  int z = (int)(gps->getValues()[2] * 100);
  char message[9];
  memcpy(&message[0], &x, 4);
  memcpy(&message[4], &z, 4);
  message[8] = tokenType;
  emitter->send(message, 9);
  robot->step(timeStep);
  reported.push_back({x, z});
}

bool alreadyReported() {
  // Reporting the same token again is a misidentification
  double x = gps->getValues()[0] * 100, z = gps->getValues()[2] * 100;
  for (const auto &position : reported)
    if (fabs(x - position[0]) < 12 && fabs(z - position[1]) < 12) // Closer than 1 tile
      return true;
  return false;
}
// endregion

// region loop
int main() {
  enableSensors();
  leftWheel->setPosition(INFINITY); // Let the wheels turn without limit
  rightWheel->setPosition(INFINITY);

  while (robot->step(timeStep) != -1) {
    speeds[0] = maxVelocity;
    speeds[1] = maxVelocity;

    if (leftDist->getValue() < 0.05) // Wall on the left: turn right
      turnRight();
    if (rightDist->getValue() < 0.05) // Wall on the right: turn left
      turnLeft();
    if (frontDist->getValue() < 0.05) // Wall in front: spin
      spin();

    if (getBrightness() < 80) { // Black floor: turn away from the hole
      spin();
      leftWheel->setVelocity(speeds[0]);
      rightWheel->setVelocity(speeds[1]);
      delay(600);
    }

    // Close to a wall, and something on it: report it
    if (frontDist->getValue() < 0.07 && !alreadyReported() && seesToken(camera->getImage()))
      report('H'); // The type cannot be told yet, so guess 'H'

    leftWheel->setVelocity(speeds[0]);
    rightWheel->setVelocity(speeds[1]);
  }

  delete robot;
  return 0;
}
// endregion
