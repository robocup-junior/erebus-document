---
title: Parameter Reference
description: Sizes of the field, game times, scoring multipliers, robot limits and the device names of the starter robot.
---

## Field

| Parameter | Value |
|---|---|
| Tile | 12 cm × 12 cm |
| Quarter tile (Areas 2 and 3) | 6 cm × 6 cm |
| Wall | 1 cm thick, 6 cm high |
| Letter victim | 2 cm × 2 cm |
| Cognitive target | 5 cm in diameter |

## Game

| Parameter | Value |
|---|---|
| Game time | 8 minutes of simulated time |
| Real-world time | 10 minutes |
| Automatic lack of progress | After 20 seconds in a fixed location |
| Stop time to report a wall token | At least 1 second |
| Time multiplier in a swamp | x5 on the first entry, +1 on each new entry into the same swamp, up to x10 |
| Area multipliers | 1, 1.25, 1.5 and 2 for Areas 1, 2, 3 and 4 |
| Exit bonus | +10% |
| Mapping bonus multiplier | correctness × 1.2 + 1 |

## Robot

| Parameter | Value |
|---|---|
| Budget | 3000 |
| Maximum number of cameras | 3 |
| Maximum number of distance sensors | 8 |
| Distance sensor range | 0 to 0.8 m |
| GPS accuracy | 0.0025 m |
| Maximum wheel velocity | 6.28 rad/s |
| Lidar | 512 points per layer, 4 layers, 0.01 to 1 m |

`timeStep` sets the number of milliseconds between sensor updates. `int(robot.getBasicTimeStep())` gets the basic time step of the world, which is 16 ms in the worlds of Erebus v26.1.

## Device names of the starter robot

These are the names to pass to `robot.getDevice()` with the [starter robot](/docs/robot/). In your own robots, you choose the names in the [Robot Customizer](/docs/robot/customizer/#components). The emitter and the receiver are always available.

| Device | Name |
|---|---|
| Wheel motors | `left wheel motor`, `right wheel motor` |
| Wheel encoders | `left wheel sensor`, `right wheel sensor` |
| Distance sensors | `leftDist`, `frontDist`, `rightDist` |
| Camera | `camera` |
| Colour sensor | `color` |
| GPS | `gps` |
| Gyroscope | `gyro` |
| Accelerometer | `accelerometer` |
| Lidar | `lidar` |
| Emitter | `emitter` |
| Receiver | `receiver` |
