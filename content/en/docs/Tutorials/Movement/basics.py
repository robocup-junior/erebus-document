from controller import Motor
...

leftMotor = robot.getDevice("wheel1 motor")     #Step 1
rightMotor = robot.getDevice("wheel2 motor")

leftMotor.setPosition(float('inf'))    #Step 2
rightMotor.setPosition(float('inf'))

leftMotor.setVelocity(5.0)     #Step 3
rightMotor.setVelocity(5.0)