---
title: Get your robot
description: Every program runs on a robot that you design. Download the starter robot, or build it yourself.
---

In Erebus, **you design your robot**: you choose its sensors and where they go, within a budget. Every program needs one, so the first step is to get a robot and load it in Erebus.

![A real e-puck robot](./real_robot.thumbnail.jpg)

The robot is based on the [e-puck](https://cyberbotics.com/doc/guide/epuck?version=R2023b), a small round educational robot with two wheels. You add sensors to it with the [Robot Customizer](https://robot.erebus.rcj.cloud/), and save the design as a `.json` file that Erebus loads.

## The starter robot
This documentation uses one robot everywhere, the **starter robot**, so that every example works as it is. It has all the sensors the tutorials need:

| Component | Name in your program | What it is for |
|---|---|---|
| Two wheels | `left wheel motor`, `right wheel motor` | Moving |
| Wheel encoders | `left wheel sensor`, `right wheel sensor` | Measuring how far the wheels turned |
| Three distance sensors | `leftDist`, `frontDist`, `rightDist` | Finding walls on the left, in front and on the right |
| Camera, 64 × 40 pixels | `camera` | Finding wall tokens |
| Colour sensor | `color` | Seeing the floor: holes, swamps and passages |
| GPS | `gps` | Knowing its position, to report tokens |
| Gyro | `gyro` | Measuring how much it has turned |
| Accelerometer | `accelerometer` | Measuring acceleration |
| Lidar | `lidar` | Measuring distances all around |
| Emitter and receiver | `emitter`, `receiver` | Talking to the game. Every robot has them. |

It costs 2400 of the budget of 3000.

## Choose your path

**Recommended: build it yourself.** It takes about 15 minutes, and you will understand every part of your robot. Follow [Build your robot](/docs/robot/build/).

**In a hurry:** download the finished robot and continue with the tutorials. You can always come back and build it later.

<a href="/downloads/starter-robot.json" download>Download starter-robot.json</a>

## Load it in Erebus
1. Open a world, such as `game/worlds/world1.wbt`.
2. In the control window, press the **right LOAD button**, with the robot icon, and choose your `.json` file.
3. Check the Webots console. Erebus lists each component with its cost, and ends with `Your custom robot has been successfully generated!`.

:::note
Erebus v26.1 also prints `PROTO parameter 'camera_width' has no matching IS field` in red. You can ignore it: your camera still has the resolution you chose.
:::

The robot stays loaded until you load another one or reset the game. Next, [run your first program](/docs/getting-started/).

## Designing your own
Once you know the basics, change the starter robot or design a new one: more cameras with higher resolution, more distance sensors, sensors in other places. The [Robot Customizer reference](/docs/robot/customizer/) lists all the components, their costs and limits.

If you change the name of a component, change it in your program too.
