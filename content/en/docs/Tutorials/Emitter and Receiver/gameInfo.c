char message[1] = { 'G' }; // message = 'G' for game information
emitter->send(message, sizeof(message)); // Send out the message array. Note that the 2nd parameter must be the size of the message

...

if(receiver->getQueueLength() > 0) { // If receiver queue is not empty
    char *receivedData = (char *)receiver->getData(); // Grab data as a string
    float score = 0.0;
    int time = 0;
    if (receivedData[0] == 'G') {
        memcpy(&score, receivedData + 4, 4); // Score stored in bytes 4 to 7
        memcpy(&time, receivedData + 8, 4);  // Remaining time stored in bytes 8 to 11
        cout << "Game Score: " << score << " Remaining time: " << time << endl;
        receiver->nextPacket(); // Discard the current data packet
    }
}