def floorType(r, g, b):
    brightness = (r + g + b) / 3
    if brightness < 80:
        return "hole"
    if r > 220 and g > 200 and b < 190:
        return "swamp"
    if b > 220 and g < 130:
        return "purple passage" if r > 150 else "blue passage"
    if r > 220 and g < 130 and b < 130:
        return "red passage"
    if g > 220 and r < 100 and b < 100:
        return "green passage"
    return "floor"
