#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Emitter.hpp>
#include <webots/Receiver.hpp>

using namespace webots;
using namespace std;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  Emitter *emitter = robot->getEmitter("emitter");
  Receiver *receiver = robot->getReceiver("receiver");
  receiver->enable(timeStep); // The receiver must be enabled

  bool asked = false;
  while (robot->step(timeStep) != -1) {
    // Call a lack of progress once, after 2 seconds
    if (!asked && robot->getTime() > 2) {
      char message = 'L';
      emitter->send(&message, 1);
      asked = true;
    }

    // Listen for messages from the game
    while (receiver->getQueueLength() > 0) {
      const char *data = (const char *)receiver->getData();
      if (receiver->getDataSize() == 1 && data[0] == 'L')
        cout << "Lack of progress! The robot is back at the last checkpoint." << endl;
      receiver->nextPacket();
    }
  }

  delete robot;
  return 0;
}
