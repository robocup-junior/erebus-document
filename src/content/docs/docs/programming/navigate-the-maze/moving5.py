def checkVic(img):
    height, width = cam.getHeight(), cam.getWidth()
    img = np.frombuffer(img, np.uint8).reshape((height, width, 4))  # Convert img to BGRA format (for OpenCV)
    img = cv.cvtColor(img, cv.COLOR_BGRA2GRAY) # Grayscale image
    img, thresh = cv.threshold(img, 200, 255, cv.THRESH_BINARY) # Threshold image (200-255 -> white; 0-200 -> black)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE) # Find all bright shapes
    for cnt in contours:
        x, y, w, h = cv.boundingRect(cnt)   # Find position and size of contour
        if x == 0 or y == 0 or x + w == width or y + h == height:
            continue    # Shapes touching the edge of the image are not tokens: they are usually the floor
        contArea = cv.contourArea(cnt)   # Area covered by the shape
        ratio = w / h    # Calculate width to height ratio of contour
        # if the contour area and width to height ratio are within certain ranges
        if contArea > 40 and ratio > 0.65 and ratio < 1.5:
            return True
    return False
