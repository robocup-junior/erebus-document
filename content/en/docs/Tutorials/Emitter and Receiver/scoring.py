from controller import Robot, Receiver, Emitter
import struct # Use the struct module in order to pack the message sent to the Main Supervisor

...
    
victimType = bytes('H', "utf-8") # The victim type being sent is the letter 'H' for harmed victim

position = gps.getValues() # Get the current gps position of the robot
x = position[0] * 100 # Get the xy coordinates, multiplying by 100 to convert from meters to cm 
y = position[2] * 100 # We will use these coordinates as an estimate for the victim's position

message = struct.pack("i i c", x, y, victimType) # Pack the message.
    
emitter.send(message) # Send out the message