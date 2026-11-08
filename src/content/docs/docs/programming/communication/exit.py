from controller import Robot
import struct

robot = Robot()
timeStep = int(robot.getBasicTimeStep())
emitter = robot.getDevice("emitter")

robot.step(timeStep)
print("Ending the game")
# Ends the game. Send it on the starting tile, after identifying a token, to get the exit bonus.
# The game stops your program right after this message.
emitter.send(struct.pack("c", b"E"))
robot.step(timeStep)
