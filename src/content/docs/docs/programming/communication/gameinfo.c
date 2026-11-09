#include <iostream>
#include <cstring>
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
  receiver->enable(timeStep);

  double lastAsked = 0;
  while (robot->step(timeStep) != -1) {
    // Ask for the game information once a second
    if (robot->getTime() - lastAsked > 1) {
      char message = 'G';
      emitter->send(&message, 1);
      lastAsked = robot->getTime();
    }

    while (receiver->getQueueLength() > 0) {
      const char *data = (const char *)receiver->getData();
      if (receiver->getDataSize() == 20 && data[0] == 'G') { // The game information is 20 bytes long
        float score, battery;
        int timeLeft, realTimeLeft;
        memcpy(&score, data + 4, 4);
        memcpy(&timeLeft, data + 8, 4);
        memcpy(&realTimeLeft, data + 12, 4);
        memcpy(&battery, data + 16, 4);
        cout << "Score: " << score << " Time left: " << timeLeft << " s Real time left: " << realTimeLeft << " s"
             << " Battery: " << battery << " %" << endl;
      }
      receiver->nextPacket();
    }
  }

  delete robot;
  return 0;
}
