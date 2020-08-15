while robot.step(timeStep) != -1:
    speeds[0] = max_velocity
    speeds[1] = max_velocity

    # Check left and right sensors to avoid walls,
    for i in range(2):                             # Loop through the two sensors for each of the left and right
        #for sensors on the left, either
        if leftSensors[i].getValue() > 80:
            turn_right()                           # We see a wall on the left, so turn right away from the wall
        #for sensors on the right, either
        elif rightSensors[i].getValue() > 80:
            turn_left()

    #for both front sensors
    if frontSensors[0].getValue() > 80 and frontSensors[1].getValue() > 80:
        spin()

    wheel_left.setVelocity(speeds[0])              # Send the speed values we have choosen to the robot
    wheel_right.setVelocity(speeds[1])
