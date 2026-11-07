message = struct.pack('c', 'L'.encode()) # message = 'L' to activate lack of progress
emitter.send(message) # Send message