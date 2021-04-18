from controller import Robot, GPS
import math

robot = Robot()

gps = robot.getDevice("gps")

timestep = int(robot.getBasicTimeStep())

gps.enable(timestep)

robot.step(timestep) # Must step once to update sensor reading
startX = gps.getValues()[0] # Store initial robot position 
startZ = gps.getValues()[2]

while robot.step(timestep) != -1:

    x = gps.getValues()[0]
    z = gps.getValues()[2]
    
    dist = math.sqrt((x-startX)**2 + (z-startZ)**2); # Use the distance formula to calculate distance to starting position
    
    print("Distance from starting location: " + str(dist))
        
