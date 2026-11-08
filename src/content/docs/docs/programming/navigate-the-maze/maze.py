# region setup
from controller import Robot
import struct
import numpy as np
import cv2 as cv

robot = Robot()
timeStep = 32         # Milliseconds between steps
maxVelocity = 6.28    # The maximum speed of the wheels, in radians per second

leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))   # Let the wheels turn without limit
rightWheel.setPosition(float("inf"))

speeds = [maxVelocity, maxVelocity]   # [left wheel speed, right wheel speed]
reported = []                         # Positions where a token has already been reported
# endregion

# region sensors
leftDist = robot.getDevice("leftDist")
frontDist = robot.getDevice("frontDist")
rightDist = robot.getDevice("rightDist")
camera = robot.getDevice("camera")
colorSensor = robot.getDevice("color")
gps = robot.getDevice("gps")
emitter = robot.getDevice("emitter")  # The emitter does not need to be enabled

for sensor in [leftDist, frontDist, rightDist, camera, colorSensor, gps]:
    sensor.enable(timeStep)
# endregion

# region moves
def turnRight():
    speeds[0] = 0.6 * maxVelocity
    speeds[1] = -0.2 * maxVelocity

def turnLeft():
    speeds[0] = -0.2 * maxVelocity
    speeds[1] = 0.6 * maxVelocity

def spin():
    speeds[0] = 0.6 * maxVelocity
    speeds[1] = -0.6 * maxVelocity

def delay(ms):
    start = robot.getTime()
    while robot.step(timeStep) != -1:
        if (robot.getTime() - start) * 1000 > ms:
            break

def getBrightness():
    image = colorSensor.getImage()
    return colorSensor.imageGetGray(image, colorSensor.getWidth(), 0, 0)  # 0 (black) to 255 (white)
# endregion

# region detect
def seesToken(image):
    height, width = camera.getHeight(), camera.getWidth()
    image = np.frombuffer(image, np.uint8).reshape((height, width, 4))  # BGRA image for OpenCV
    gray = cv.cvtColor(image, cv.COLOR_BGRA2GRAY)
    _, bright = cv.threshold(gray, 200, 255, cv.THRESH_BINARY)          # Bright parts in white
    contours, _ = cv.findContours(bright, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        x, y, w, h = cv.boundingRect(contour)
        if x == 0 or y == 0 or x + w == width or y + h == height:
            continue  # Shapes touching the edge of the image are usually the floor
        if cv.contourArea(contour) > 40 and 0.65 < w / h < 1.5:
            return True  # A bright, roughly square shape on a wall
    return False
# endregion

# region report
def report(tokenType):
    leftWheel.setVelocity(0)  # Stop for more than 1 second
    rightWheel.setVelocity(0)
    delay(1300)
    x = int(gps.getValues()[0] * 100)  # Meters to centimeters
    z = int(gps.getValues()[2] * 100)
    emitter.send(struct.pack("i i c", x, z, tokenType.encode()))
    robot.step(timeStep)
    reported.append((x, z))

def alreadyReported():
    # Reporting the same token again is a misidentification
    x = gps.getValues()[0] * 100
    z = gps.getValues()[2] * 100
    return any(abs(x - rx) < 12 and abs(z - rz) < 12 for rx, rz in reported)  # Closer than 1 tile
# endregion

# region loop
while robot.step(timeStep) != -1:
    speeds[0] = maxVelocity
    speeds[1] = maxVelocity

    if leftDist.getValue() < 0.05:   # Wall on the left: turn right
        turnRight()
    if rightDist.getValue() < 0.05:  # Wall on the right: turn left
        turnLeft()
    if frontDist.getValue() < 0.05:  # Wall in front: spin
        spin()

    if getBrightness() < 80:         # Black floor: turn away from the hole
        spin()
        leftWheel.setVelocity(speeds[0])
        rightWheel.setVelocity(speeds[1])
        delay(600)

    # Close to a wall, and something on it: report it
    if frontDist.getValue() < 0.07 and not alreadyReported() and seesToken(camera.getImage()):
        report("H")  # The type cannot be told yet, so guess "H"

    leftWheel.setVelocity(speeds[0])
    rightWheel.setVelocity(speeds[1])
# endregion
