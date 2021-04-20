if(receiver->getQueueLength() > 0) { // Check if receiver queue size is not empty

    // Since the only message the robot controller will ever get will be lack of
    // progress notifications, we don't really care about the contents of the message
    cout << "Detected Lack of Progress!" << endl;
    receiver->nextPacket(); // Discard the current data packet
}