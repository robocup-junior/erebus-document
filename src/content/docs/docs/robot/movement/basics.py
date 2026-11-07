from controller import Motor
...

wheel_left = robot.getDevice("wheel1 motor")     #Step 1
wheel_right = robot.getDevice("wheel2 motor")

wheel_left.setPosition(float('inf'))    #Step 2
wheel_right.setPosition(float('inf'))

wheel_left.setVelocity(5.0)     #Step 3
wheel_right.setVelocity(5.0)