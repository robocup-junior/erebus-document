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