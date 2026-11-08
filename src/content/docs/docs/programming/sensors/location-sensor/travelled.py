from controller import Robot
import math

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

gps = robot.getDevice("gps")
gps.enable(timeStep)
leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

robot.step(timeStep)  # Step once, so that the GPS has a value
startX, _, startZ = gps.getValues()

leftWheel.setVelocity(3.0)
rightWheel.setVelocity(3.0)

while robot.step(timeStep) != -1:
    x, _, z = gps.getValues()
    distance = math.sqrt((x - startX) ** 2 + (z - startZ) ** 2)
    print("Distance from the start:", round(distance, 3), "m")
    if distance > 0.06:  # Half a tile
        leftWheel.setVelocity(0)
        rightWheel.setVelocity(0)
        break
