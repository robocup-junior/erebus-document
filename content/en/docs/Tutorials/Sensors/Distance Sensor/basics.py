from controller import Robot, DistanceSensor # Step 1: Import DistanceSensor

robot = Robot()

distanceSensor = robot.getDevice("ps0") # Step 2: Retrieve the sensor, named "ps0", from the robot. Note that the sensor name may differ between robots

timestep = int(robot.getBasicTimeStep())

distanceSensor.enable(timestep) # Step 3: Enable the sensor, using the timestep as the update rate

while robot.step(timestep) != -1:
    
    distance = distanceSensor.getValue() # Step 4: Use the getValue() function to get the sensor reading
    print("Distance: " + str(distance)) # Print out the value of the sensor