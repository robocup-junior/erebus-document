def checkVic(img):
    img = np.frombuffer(img, np.uint8).reshape((cam.getHeight(), cam.getWidth(), 4))  # Convert img to RGBA format (for OpenCV)
    img = cv.cvtColor(img, cv.COLOR_BGR2GRAY) # Grayscale image
    img, thresh = cv.threshold(img, 80, 255, cv.THRESH_BINARY_INV) # Inverse threshold image (0-80 -> white; 80-255 -> black)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE) # Find all shapes within thresholded image
    for cnt in contours:
        x, y, w, h = cv.boundingRect(cnt)   # Find width and height of contour
        contArea = cv.contourArea(cnt)   # Area covered by the shape
        ratio = w / h    # Calculate width to height ratio of contour
        # if the contour area and width to height ratio are within certain ranges
        if contArea > 300 and contArea < 1000 and ratio > 0.65 and ratio < 0.95:
            return True
    return False