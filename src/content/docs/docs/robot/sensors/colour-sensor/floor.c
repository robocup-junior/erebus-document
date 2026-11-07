#include <string>

std::string floorType(int r, int g, int b) {
  int brightness = (r + g + b) / 3;
  if (brightness < 80)
    return "hole";
  if (r > 220 && g > 200 && b < 190)
    return "swamp";
  if (b > 220 && g < 130)
    return r > 150 ? "purple passage" : "blue passage";
  if (r > 220 && g < 130 && b < 130)
    return "red passage";
  if (g > 220 && r < 100 && b < 100)
    return "green passage";
  return "floor";
}
