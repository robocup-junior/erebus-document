from controller import Robot
from controller import Motor
from controller import PositionSensor

robot = Robot() # Create robot object
timeStep = 32   # timeStep = number of milliseconds between world updates

leftMotor = robot.getDevice("left wheel motor")    # Motor initialization
rightMotor = robot.getDevice("right wheel motor")
leftMotor.setPosition(float('inf'))
rightMotor.setPosition(float('inf'))

leftEncoder = leftMotor.getPositionSensor()    # Encoder initialization
rightEncoder = rightMotor.getPositionSensor()
leftEncoder.enable(timeStep)
rightEncoder.enable(timeStep)

leftMotor.setVelocity(5.0)
rightMotor.setVelocity(5.0)

while robot.step(timeStep) != -1:
    if leftEncoder.getValue() > 20.0:   # If left motor has spun more than 20 radians
        break

leftMotor.setVelocity(0.0)
rightMotor.setVelocity(0.0)