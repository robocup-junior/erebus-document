---
title: "Location Sensor"
linkTitle: "Location Sensor"
weight: 3
description: >
  Retrieves the robot's position in the field
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The location sensor, also called the <b>GPS</b>, is used to retrieve the absolute x, y, and z position of the robot, useful for localizing the robot within the field. The units returned are in <b>meters.</b>

There are 4 basic steps to using this sensor:

1. Start by importing or including the appropriate class for the location sensor.
2. Retrieve the sensor by name from the robot.
3. Enable the sensor by passing in the update rate of the sensor. (Usually the timestep) 
4. Finally, retrieve values from the sensor.

<br>
<b>Note:</b> The horizontal plane of the sensor's coordinate system is defined by the X and Z axes. The Y axis is therefore the vertical axis:
<br><br>

{{< figure src="coordinate_systems_right_handed.png" class="center">}}

{{< code-toggle file="basics">}}
{{</code-toggle>}}

## Example

This sample gives an example application of the location sensor. It continuously prints the distance, calculated using the distance formula, from the starting position of the robot. 

{{< code-toggle file="example">}}
{{</code-toggle>}}