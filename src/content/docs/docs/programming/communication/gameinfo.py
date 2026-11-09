from controller import Robot
import struct

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

emitter = robot.getDevice("emitter")
receiver = robot.getDevice("receiver")
receiver.enable(timeStep)

lastAsked = 0
while robot.step(timeStep) != -1:
    # Ask for the game information once a second
    if robot.getTime() - lastAsked > 1:
        emitter.send(struct.pack("c", b"G"))
        lastAsked = robot.getTime()

    while receiver.getQueueLength() > 0:
        data = receiver.getBytes()
        if len(data) == 20:  # The game information is 20 bytes long
            _, score, timeLeft, realTimeLeft, battery = struct.unpack("c f i i f", data)
            print("Score:", round(score, 2), "Time left:", timeLeft, "s", "Real time left:", realTimeLeft, "s",
                  "Battery:", round(battery, 1), "%")
        receiver.nextPacket()
