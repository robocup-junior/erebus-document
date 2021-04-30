bool checkVic(void *img) {
    Rect boundRect;
    float contArea, ratio;
    vector<vector<Point>> contours;
    Mat frame(cam->getHeight(), cam->getWidth(), CV_8UC4, img); // Create frame using camera image

    cvtColor(frame, frame, COLOR_BGR2GRAY); // Grayscale image
    threshold(frame, frame, 80, 255, THRESH_BINARY_INV); // Inverse threshold image (0-80 -> white; 80-255 -> black)
    findContours(frame, contours, RETR_TREE, CHAIN_APPROX_SIMPLE); // Find all shapes within thresholded image
    for (int i = 0; i < contours.size(); i++) {
        boundRect = boundingRect(contours[i]); // Draw a rectnagle around shape for width to height ratio
        contArea = fabs(contourArea(Mat(contours[i]))); // Area covered by the shape
        ratio = (float)boundRect.width / boundRect.height; // Calculate width to height ratio
        //if the contour area and width to height ratio are within certain ranges
        if (contArea > 300 && contArea < 1000 && ratio > 0.65 && ratio < 0.95)
            return true;
    }
    return false;
}