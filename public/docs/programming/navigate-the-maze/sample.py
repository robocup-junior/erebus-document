from controller import Robot, Motor, DistanceSensor, Camera, Emitter, GPS
import struct
import numpy as np
import cv2 as cv

timeStep = 32            # Set the time step for the simulation
max_velocity = 6.28      # Set a maximum velocity time constant

robot = Robot()

wheel_left = robot.getDevice("left wheel motor")   # Create an object to control the left wheel
wheel_right = robot.getDevice("right wheel motor") # Create an object to control the right wheel

#[left wheel speed, right wheel speed]
speeds = [max_velocity,max_velocity]

reported = [] # Positions where the robot has already reported a token

#Create objects for all robot sensors
leftDist = robot.getDevice("leftDist")      # Get robot's left distance sensor
leftDist.enable(timeStep)     # Enable left distance sensor

frontDist = robot.getDevice("frontDist")
frontDist.enable(timeStep)

rightDist = robot.getDevice("rightDist")
rightDist.enable(timeStep)

cam = robot.getDevice("camera")
cam.enable(timeStep)

colorSensor = robot.getDevice("color")
colorSensor.enable(timeStep)

emitter = robot.getDevice("emitter")    # Emitter doesn't need enable

gps = robot.getDevice("gps")
gps.enable(timeStep)

wheel_left.setPosition(float("inf"))
wheel_right.setPosition(float("inf"))

def turn_right():
    #set left wheel speed
    speeds[0] = 0.6 * max_velocity
    #set right wheel speed
    speeds[1] = -0.2 * max_velocity

def turn_left():
    #set left wheel speed
    speeds[0] = -0.2 * max_velocity
    #set right wheel speed
    speeds[1] = 0.6 * max_velocity

def spin():
    #set left wheel speed
    speeds[0] = 0.6 * max_velocity
    #set right wheel speed
    speeds[1] = -0.6 * max_velocity

def delay(ms):
    initTime = robot.getTime()      # Store starting time (in seconds)
    while robot.step(timeStep) != -1:
        if (robot.getTime() - initTime) * 1000.0 > ms: # If time elapsed (converted into ms) is greater than value passed in
            break

def getColor():
    img = colorSensor.getImage()    # Grab color sensor camera's image view
    return colorSensor.imageGetGray(img, colorSensor.getWidth(), 0, 0)    # Return grayness of the only pixel (0-255)
    
def checkVic(img):
    height, width = cam.getHeight(), cam.getWidth()
    img = np.frombuffer(img, np.uint8).reshape((height, width, 4))  # Convert img to BGRA format (for OpenCV)
    img = cv.cvtColor(img, cv.COLOR_BGRA2GRAY) # Grayscale image
    img, thresh = cv.threshold(img, 200, 255, cv.THRESH_BINARY) # Threshold image (200-255 -> white; 0-200 -> black)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE) # Find all bright shapes
    for cnt in contours:
        x, y, w, h = cv.boundingRect(cnt)   # Find position and size of contour
        if x == 0 or y == 0 or x + w == width or y + h == height:
            continue    # Shapes touching the edge of the image are not tokens: they are usually the floor
        contArea = cv.contourArea(cnt)   # Area covered by the shape
        ratio = w / h    # Calculate width to height ratio of contour
        # if the contour area and width to height ratio are within certain ranges
        if contArea > 40 and ratio > 0.65 and ratio < 1.5:
            return True
    return False

def report(victimType):
    # Struct package to be sent to supervisor to report a wall token
    # First four bytes store robot's x coordinate
    # Second four bytes store robot's z coordinate
    # Last byte stores type of victim
    #     Letter victims: H, S, U
    #     Cognitive targets: F, P, C, O
    wheel_left.setVelocity(0)   # Stop for 1 second
    wheel_right.setVelocity(0)
    delay(1300)
    victimType = bytes(victimType, "utf-8")    # Convert victimType to character for struct.pack
    posX = int(gps.getValues()[0] * 100)    # Convert from m to cm
    posZ = int(gps.getValues()[2] * 100)
    message = struct.pack("i i c", posX, posZ, victimType)
    emitter.send(message)
    robot.step(timeStep)
    reported.append((posX, posZ))

def alreadyReported():
    # A token can only be scored once, and reporting it again is a misidentification
    posX = gps.getValues()[0] * 100
    posZ = gps.getValues()[2] * 100
    for x, z in reported:
        if abs(posX - x) < 12 and abs(posZ - z) < 12: # Closer than 1 tile (12 cm)
            return True
    return False
    
while robot.step(timeStep) != -1:
    speeds[0] = max_velocity
    speeds[1] = max_velocity

    # Check left and right sensor to avoid walls
    # for sensor on the left, either
    if leftDist.getValue() < 0.05:
        turn_right()      # We see a wall on the left, so turn right away from the wall

    if rightDist.getValue() < 0.05:		# for sensor on the right too
        turn_left()

    # for front sensor
    if frontDist.getValue() < 0.05:
        spin()

    # if on black, turn away
    if getColor() < 80:
        spin()
        wheel_left.setVelocity(speeds[0])
        wheel_right.setVelocity(speeds[1])
        delay(600)

    # if close to a wall in front and sees a victim, report it
    if frontDist.getValue() < 0.07 and not alreadyReported() and checkVic(cam.getImage()):
        report('H') # Cannot determine the type of the victim, so always guess 'H' for now

    wheel_left.setVelocity(speeds[0])              # Send the speed values we have choosen to the robot
    wheel_right.setVelocity(speeds[1])