#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Lidar.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Lidar *lidar = robot->getLidar("lidar");
  lidar->enable(timeStep);
  int n = lidar->getHorizontalResolution(); // Number of points in each layer
  cout << "Points per layer: " << n << " Layers: " << lidar->getNumberOfLayers() << endl;

  while (robot->step(timeStep) != -1) {
    const float *distances = lidar->getLayerRangeImage(0); // One layer, in meters, clockwise from the front
    cout << "front: " << distances[0] << " right: " << distances[n / 4] << " back: " << distances[n / 2]
         << " left: " << distances[3 * n / 4] << endl;
  }

  delete robot;
  return 0;
}
