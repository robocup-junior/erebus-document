---
title: "Distance Sensor"
linkTitle: "Distance Sensor"
weight: 1
description: >
  Gets the distance to objects in the environment
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The distance sensors in Erebus are configured to have a range between <b>0 </b>to <b>0.8 </b>meters. They will return the distance to the first object blocking their line of sight.

There are 4 basic steps to using this sensor:

1. Start by importing or including the appropriate class for the distance sensor.
2. Retrieve the sensor by name from the robot.
3. Enable the sensor by passing in the update rate of the sensor. (Usually the timestep) 
4. Finally, retrieve values from the sensor.

{{< code-toggle file="basics">}}
{{</code-toggle>}}


## Example

This example shows how to enable, poll, and print values from multiple distance sensors using a list or array. This is useful for managing multiple distance sensors:

{{< code-toggle file="example">}}
{{</code-toggle>}}