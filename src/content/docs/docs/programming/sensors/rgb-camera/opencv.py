from controller import Robot
import cv2
import numpy as np

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

camera = robot.getDevice("camera")
camera.enable(timeStep)

while robot.step(timeStep) != -1:
    # Webots images have 4 channels per pixel, in BGRA order
    image = np.frombuffer(camera.getImage(), np.uint8).reshape((camera.getHeight(), camera.getWidth(), 4))
    frame = cv2.cvtColor(image, cv2.COLOR_BGRA2BGR)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    _, thresh = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY)  # Bright parts in white

    cv2.imshow("camera", cv2.resize(frame, None, fx=4, fy=4, interpolation=cv2.INTER_NEAREST))
    cv2.imshow("threshold", cv2.resize(thresh, None, fx=4, fy=4, interpolation=cv2.INTER_NEAREST))
    cv2.waitKey(1)  # Shows the windows
