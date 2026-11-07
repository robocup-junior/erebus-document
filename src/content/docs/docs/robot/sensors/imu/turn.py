from controller import Robot
import math

robot = Robot()
timestep = int(robot.getBasicTimeStep())

left = robot.getDevice("wheel1 motor")
right = robot.getDevice("wheel2 motor")
left.setPosition(float("inf"))
right.setPosition(float("inf"))

gyro = robot.getDevice("gyro")
gyro.enable(timestep)

def turnLeft(angle):
    turned = 0
    left.setVelocity(-2)
    right.setVelocity(2)
    while abs(turned) < angle and robot.step(timestep) != -1:
        turned += gyro.getValues()[1] * timestep / 1000 # Speed multiplied by the time, in seconds
    left.setVelocity(0)
    right.setVelocity(0)

turnLeft(math.pi / 2)
