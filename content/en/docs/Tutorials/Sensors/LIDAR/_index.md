---
title: "LIDAR"
linkTitle: "LIDAR"
weight: 5
description: >
  Gets distances to objects in the environment in a wider field of view
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The Lidar returns the distances to the objects in the environment in <b>meters</b>, similar to the Distance Sensor, but provides 360 degrees of full coverage. The two basic properties of a Lidar in Webots are the <b>number of layers</b> and the <b>horizontal resolution</b>. The number of layers is the amount of lasers, "stacked" on top of each other, to provide vertical information in addition to horizontal. The horizontal resolution is the number of points per layer. These properties can be found using:

{{< code-toggle file="properties">}}
{{</code-toggle>}}

There are 4 basic steps to using this sensor:

1. Start by importing or including the appropriate class for the lidar
2. Retrieve the sensor by name from the robot.
3. Enable the sensor by passing in the update rate of the sensor. (Usually the timestep) 
4. Finally, retrieve values from the sensor.

<b>Note:</b> The lidar relies on OpenGL rendering information to retrieve distances. As such, make sure the lidar is outside the body of the robot, so that it is not blocked by the inside of the robot.

{{< code-toggle file="basic">}}
{{</code-toggle>}}

In addition to retrieving the distances, the lidar also has the option of constructing a <b>point cloud</b> from the distances. The point cloud is a collection of x, y, and z ray collision points relative to the position of the lidar. Each point is stored in a <b>LidarPoint</b> object, which also contains information on the layer where the point originated from and what time the point was taken.

 <b>Note:</b> Enabling the point cloud is computationally expensive.


{{< code-toggle file="basic2">}}
{{</code-toggle>}}