bool checkVic(void *img) {
    Rect boundRect;
    float contArea, ratio;
    vector<vector<Point>> contours;
    Mat frame(cam->getHeight(), cam->getWidth(), CV_8UC4, img); // Create frame using camera image

    cvtColor(frame, frame, COLOR_BGRA2GRAY); // Grayscale image
    threshold(frame, frame, 200, 255, THRESH_BINARY); // Threshold image (200-255 -> white; 0-200 -> black)
    findContours(frame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // Find all bright shapes
    for (int i = 0; i < contours.size(); i++) {
        boundRect = boundingRect(contours[i]); // Find position and size of shape
        // Shapes touching the edge of the image are not tokens: they are usually the floor
        if (boundRect.x == 0 || boundRect.y == 0 ||
            boundRect.x + boundRect.width == frame.cols || boundRect.y + boundRect.height == frame.rows)
            continue;
        contArea = fabs(contourArea(Mat(contours[i]))); // Area covered by the shape
        ratio = (float)boundRect.width / boundRect.height; // Calculate width to height ratio
        //if the contour area and width to height ratio are within certain ranges
        if (contArea > 40 && ratio > 0.65 && ratio < 1.5)
            return true;
    }
    return false;
}