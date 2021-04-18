---
title: "Movement"
linkTitle: "Movement"
weight: 2
description: >
  Explanation of the commands used to control the robot's movement
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

**Note:** The Webots API accepts and returns angles in radians, a unit of measure for angles (similar to degrees). If you 
want to work in degrees, note:
* number_of_radians = number_of_degrees * PI / 180
* number_of_degrees = number_of_radians * 180 / PI

To use motors in Webots:
1. Create a motor object for each motor you want to use. These motor objects will be used to call motor related methods 
to control the motors.
2. Set the position target of each motor to infinity so the motors will never stop on their own.
3. Set the motors to rotate at a set angular velocity (in radians per second).

{{< code-toggle file="basics">}}
{{</code-toggle>}}

## Tracking Wheel Revolutions / Motor Encoders

Webots provides a PositionSensor that allows users to track how much a wheel has rotated - some may know this as motor 
encoders. To use the PositionSensor:
1. Create a PositionSensor object for each motor you want to track.
2. Enable the PositionSensor using the *enable* method. The parameter that you pass in is the number of milliseconds the program should wait before updating the PositionSensor's value.
3. Retrieve the amount of radians your motor has rotated so far. Note that rotating a motor backward decreases this count.

{{< code-toggle file="encoders">}}
{{</code-toggle>}}

## Full Example Program

{{< code-toggle file="sample">}}
{{</code-toggle>}}