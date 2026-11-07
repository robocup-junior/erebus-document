from controller import PositionSensor
...

leftEncoder = wheel_left.getPositionSensor()    #Step 1
rightEncoder = wheel_right.getPositionSensor()

leftEncoder.enable(timeStep)    #Step 2
rightEncoder.enable(timeStep)

print("Left motor has spun " + str(leftEncoder.getValue()) + " radians")    #Step 3
print("Right motor has spun " + str(rightEncoder.getValue()) + " radians")