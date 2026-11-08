from controller import Robot
import struct

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

emitter = robot.getDevice("emitter")
receiver = robot.getDevice("receiver")
receiver.enable(timeStep)  # The receiver must be enabled

askedAt = None
while robot.step(timeStep) != -1:
    # Call a lack of progress once, after 2 seconds
    if askedAt is None and robot.getTime() > 2:
        emitter.send(struct.pack("c", b"L"))
        askedAt = robot.getTime()

    # Listen for messages from the game
    while receiver.getQueueLength() > 0:
        data = receiver.getBytes()
        if len(data) == 1 and data == b"L":
            print("Lack of progress! The robot is back at the last checkpoint.")
        receiver.nextPacket()
