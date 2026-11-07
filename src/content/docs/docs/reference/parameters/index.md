---
title: Parameter Reference
description: Reference for important parameters.
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

`timeStep` sets the number of milliseconds between sensor updates. Example programs use 32 ms, and `int(robot.getBasicTimeStep())` gets the basic time step of the world.

## Device names of the default robot

These are the names to pass to `robot.getDevice()`. In a custom robot, you choose the names in the Robot Customizer. The emitter and the receiver are always available.

| Device | Name |
|---|---|
| Left and right motors | `wheel1 motor`, `wheel2 motor` |
| Wheel encoders | `wheel1 sensor`, `wheel2 sensor` |
| Distance sensors | `ps0` to `ps7` |
| Cameras | `camera_centre`, `camera_left`, `camera_right` |
| Colour sensor | `colour_sensor` |
| GPS | `gps` |
| Gyroscope | `gyro` |
| Accelerometer | `accelerometer` |
| Emitter | `emitter` |
| Receiver | `receiver` |
