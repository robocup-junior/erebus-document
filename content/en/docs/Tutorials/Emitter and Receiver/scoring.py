from controller import Robot, Receiver, Emitter
import struct # Use the struct module in order to pack the message sent to the Main Supervisor

...
    
victimType = bytes('H', "utf-8") # The victim type being sent is the letter 'H' for harmed victim
message = struct.pack("i i c", 0, 0, victimType) # Pack the message. The estimated position of the victim is 0 cm, 0 cm.
    
emitter.send(message) # Send out the message