from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())
maxSpeed = 6.28  # The maximum speed of the wheels, in radians per second

leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

def drive(left, right, seconds):
    # Set the speed of each wheel, and keep it for some time
    leftWheel.setVelocity(left)
    rightWheel.setVelocity(right)
    start = robot.getTime()
    while robot.step(timeStep) != -1:
        if robot.getTime() - start >= seconds:
            break

drive(maxSpeed, maxSpeed, 1.0)    # Forward
drive(-maxSpeed, -maxSpeed, 1.0)  # Backward
drive(-2.0, 2.0, 1.0)             # Spin to the left
drive(0, 0, 0.1)                  # Stop
print("Done")
