#include <opencv2/opencv.hpp>
#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

using namespace webots;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Camera *camera = robot->getCamera("camera");
  camera->enable(timeStep);

  while (robot->step(timeStep) != -1) {
    // Webots images have 4 channels per pixel, in BGRA order
    cv::Mat image(camera->getHeight(), camera->getWidth(), CV_8UC4, (void *)camera->getImage());
    cv::Mat frame, gray, thresh;
    cv::cvtColor(image, frame, cv::COLOR_BGRA2BGR);
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, thresh, 200, 255, cv::THRESH_BINARY); // Bright parts in white

    cv::Mat big;
    cv::resize(frame, big, cv::Size(), 4, 4, cv::INTER_NEAREST);
    cv::imshow("camera", big);
    cv::resize(thresh, big, cv::Size(), 4, 4, cv::INTER_NEAREST);
    cv::imshow("threshold", big);
    cv::waitKey(1); // Shows the windows
  }

  delete robot;
  return 0;
}
