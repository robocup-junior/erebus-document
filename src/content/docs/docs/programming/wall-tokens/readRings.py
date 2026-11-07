import cv2 as cv
import numpy as np

# Colour of each part in BGR order, as seen by the camera
COLORS = {
    'K': (0, 0, 0),      # Black
    'R': (0, 0, 255),    # Red
    'Y': (0, 255, 255),  # Yellow
    'G': (0, 255, 0),    # Green
    'B': (255, 0, 0),    # Blue
}

def nearestColor(bgr):
    # Returns the name of the colour that is closest to a pixel
    distances = {name: np.linalg.norm(np.array(color) - bgr) for name, color in COLORS.items()}
    return min(distances, key=distances.get)

def readRings(image, centerX, centerY, radius):
    # image is a BGR image, as in the RGB Camera tutorial
    # Returns the 5 colours from the center outwards, for example ['Y', 'B', 'R', 'K', 'G']
    rings = []
    for position in [0, 0.3, 0.5, 0.7, 0.9]:
        x = int(round(centerX + position * radius))
        y = int(round(centerY))
        rings.append(nearestColor(image[y, x].astype(float)))
    return rings
