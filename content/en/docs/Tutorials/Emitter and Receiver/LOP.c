if(receiver->getQueueLength() > 0) { // If receiver queue is not empty
    char *message = (char *)receiver->getData(); // Grab data as a string
    if (message[0] == 'L') { // 'L' means a lack of progress occurred
        cout << "Detected Lack of Progress!" << endl;
        receiver->nextPacket(); // Discard the current data packet
    }
}