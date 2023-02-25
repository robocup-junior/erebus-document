message = struct.pack('c', 'G'.encode()) # message = 'G' for game information
emitter.send(message) # send message

...

if receiver.getQueueLength() > 0: # If receiver queue is not empty
    receivedData = receiver.getBytes()
    tup = struct.unpack('c f i', receivedData) # Parse data into char, float, int
    if tup[0].decode("utf-8") == 'G':
        print(f'Game Score: {tup[1]}  Remaining time: {tup[2]}')
        receiver.nextPacket() # Discard the current data packet