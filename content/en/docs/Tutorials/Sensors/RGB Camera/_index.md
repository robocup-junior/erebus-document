---
title: "RGB Camera"
linkTitle: "RGB Camera"
weight: 4
description: >
  Returns camera frames which can be used for color recognition and victim detection
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The camera sensor returns a 3D matrix/list, representing a 2D image of pixels, with each pixel comprised of RGBA color channels. Each channel can be in the range of 0 to 255, with (255,255,255) being white, and (0, 0, 0) being black. It is mainly used in the following ways:
- As a RGB color sensor to detect environment colors, like the color of the floor (In this case, it may be implemented as a 1px by 1px camera).
- As a regular camera, which returns frames that can be used with image processing libraries for victim or hazard map detection.

There are 4 basic steps to using this sensor:

1. Start by importing or including the appropriate class for the camera.
2. Retrieve the sensor by name from the robot.
3. Enable the sensor by passing in the update rate of the sensor. (Usually the timestep) 
4. Finally, retrieve values from the sensor.

{{< code-toggle file="basics">}}
{{</code-toggle>}}

<b>Note:</b> The dimensions of the frame, in pixels, can be found with the getWidth() and getHeight functions:

{{< code-toggle file="basics2">}}
{{</code-toggle>}}

## Example

This example demonstrates techniques to interface the camera frames from Erebus with third-party libraries to perform advanced image processing. The frame is fed into a data format usable by the OpenCV library, which then grayscales and displays the modified image.

{{< code-toggle file="example">}}
{{</code-toggle>}}