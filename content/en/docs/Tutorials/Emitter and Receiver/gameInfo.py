message = struct.pack('c', 'G'.encode()) # message = 'G' for game information
emitter.send(message) # Send message

...

if receiver.getQueueLength() > 0: # If receiver queue is not empty
    receivedData = receiver.getBytes()
    if len(receivedData) == 16: # The game information packet is 16 bytes long
        tup = struct.unpack('c f i i', receivedData) # Parse data into char, float, int, int
        if tup[0].decode("utf-8") == 'G':
            print(f'Game Score: {tup[1]}  Remaining time: {tup[2]}  Remaining real-world time: {tup[3]}')
    receiver.nextPacket() # Discard the current data packet
