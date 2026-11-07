from controller import Robot, Camera
import cv2 # Include OpenCV library
import numpy as np # For python, include numpy as well

robot = Robot()

camera = robot.getDevice("camera_centre")

timestep = int(robot.getBasicTimeStep())

camera.enable(timestep)

while robot.step(timestep) != -1:
    
     # Convert the camera image into an openCV Mat. You must pass in the height
     # and width of the camera in pixels. Webots images are in BGRA format, with 4 bytes per pixel

    image = camera.getImage()
    image = np.frombuffer(image, np.uint8).reshape((camera.getHeight(), camera.getWidth(), 4))
    frame = cv2.cvtColor(image, cv2.COLOR_BGRA2BGR)
    
    cv2.imshow("frame", frame)
    
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # Grayscale
    cv2.imshow("grayScale", frame)
    
    _, thresh = cv2.threshold(frame, 80, 255, cv2.THRESH_BINARY) # Threshold
    cv2.imshow("thresh", thresh)
    
    cv2.waitKey(1) # Render imshows on screen