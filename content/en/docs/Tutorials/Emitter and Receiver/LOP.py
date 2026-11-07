if receiver.getQueueLength() > 0: # If receiver queue is not empty
    receivedData = receiver.getBytes()
    if len(receivedData) == 1: # The lack of progress packet is 1 byte long
        tup = struct.unpack('c', receivedData) # Parse data into character
        if tup[0].decode("utf-8") == 'L': # 'L' means lack of progress occurred
            print("Detected Lack of Progress!")
    receiver.nextPacket() # Discard the current data packet
