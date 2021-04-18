from controller import Robot, DistanceSensor

robot = Robot()

distanceSensors = [] # Create list to store the distance sensors

timestep = int(robot.getBasicTimeStep())

# Use a for loop to retrieve and enable the distance sensors
for i in range(8):
    distanceSensors.append(robot.getDevice("ps" + str(i)))
    distanceSensors[i].enable(timestep)

while robot.step(timestep) != -1:

    # Print the values of the 8 distance sensors    
    for distanceSensor in distanceSensors:        
        distance = distanceSensor.getValue()
        print("Distance: " + str(distance))
        
