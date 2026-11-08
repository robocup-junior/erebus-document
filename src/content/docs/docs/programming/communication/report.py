from controller import Robot
import struct

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

emitter = robot.getDevice("emitter")  # Always on the robot. It does not need to be enabled.
gps = robot.getDevice("gps")
gps.enable(timeStep)
leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

def wait(seconds):
    start = robot.getTime()
    while robot.step(timeStep) != -1:
        if robot.getTime() - start >= seconds:
            break

def report(tokenType):
    # 1. Stop for more than 1 second
    leftWheel.setVelocity(0)
    rightWheel.setVelocity(0)
    wait(1.2)
    # 2. Send the position in centimeters, and the type as one letter
    x, _, z = gps.getValues()
    message = struct.pack("i i c", int(x * 100), int(z * 100), tokenType.encode())
    emitter.send(message)
    robot.step(timeStep)

report("H")  # Reports a harmed victim (Φ) where the robot is
print("Reported")
