#include <iostream>
#include <string>
#include <vector>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  vector<string> names = {"leftDist", "frontDist", "rightDist"};
  vector<DistanceSensor *> sensors;
  for (const string &name : names) {
    sensors.push_back(robot->getDistanceSensor(name));
    sensors.back()->enable(timeStep);
  }

  const double WALL = 0.07; // Closer than 7 cm counts as a wall next to the robot

  while (robot->step(timeStep) != -1) {
    cout << "Walls:";
    for (size_t i = 0; i < sensors.size(); i++)
      if (sensors[i]->getValue() < WALL)
        cout << " " << names[i];
    cout << endl;
  }

  delete robot;
  return 0;
}
