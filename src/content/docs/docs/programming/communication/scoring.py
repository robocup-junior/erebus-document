from controller import Robot, Receiver, Emitter
import struct # Use the struct module in order to pack the message sent to the Main Supervisor

...
    
victimType = bytes('H', "utf-8") # 'H' reports a harmed victim (the symbol on the wall is Φ)

position = gps.getValues() # Get the current gps position of the robot
x = int(position[0] * 100) # Get the x and z coordinates, multiplying by 100 to convert from meters to cm 
z = int(position[2] * 100) # We will use these coordinates as an estimate for the victim's position

message = struct.pack("i i c", x, z, victimType) # Pack the message.
    
emitter.send(message) # Send out the message