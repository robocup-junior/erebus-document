char message[1] = { 'G' }; // message = 'G' for game information
emitter->send(message, sizeof(message)); // Send out the message array. Note that the 2nd parameter must be the size of the message

...

if(receiver->getQueueLength() > 0) { // If receiver queue is not empty
    char *receivedData = (char *)receiver->getData(); // Grab data as a string
    if (receiver->getDataSize() == 16 && receivedData[0] == 'G') { // The game information packet is 16 bytes long
        float score = 0.0;
        int time = 0, realTime = 0;
        memcpy(&score, receivedData + 4, 4);     // Score stored in bytes 4 to 7
        memcpy(&time, receivedData + 8, 4);      // Remaining time stored in bytes 8 to 11
        memcpy(&realTime, receivedData + 12, 4); // Remaining real-world time stored in bytes 12 to 15
        cout << "Game Score: " << score << " Remaining time: " << time << " Remaining real-world time: " << realTime << endl;
    }
    receiver->nextPacket(); // Discard the current data packet
}
