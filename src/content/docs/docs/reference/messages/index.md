---
title: Message Reference
description: Reference for the messages exchanged with the Main Supervisor.
---

Messages are sent with the `emitter` device and received with the `receiver` device. See the [Communication tutorial](/docs/programming/communication/) for examples.

The format strings below are those of the Python [struct](https://docs.python.org/3/library/struct.html) module.

## Sent by the robot

| Message | Format | Length | Purpose |
|---|---|---|---|
| Report a wall token | `i i c`: x, z, type | 9 bytes | The position is in centimeters, and the type is one of `H`, `S`, `U`, `F`, `P`, `C`, `O`. The robot must have been stopped for at least 1 second. |
| Map data | `2i` followed by UTF-8 text: rows, columns, comma separated cells | Any other length | Stores the map, without evaluating it |
| `M` | `c` | 1 byte | Evaluates the stored map. This can only be done once. |
| `L` | `c` | 1 byte | Calls a lack of progress |
| `G` | `c` | 1 byte | Asks for the game information |
| `E` | `c` | 1 byte | Ends the game. It gives the exit bonus if the robot is on the starting tile and has identified a wall token. |

Erebus tells these messages apart by their length, so a report must be exactly 9 bytes.

## Received by the robot

| Message | Format | Length | Purpose |
|---|---|---|---|
| `L` | `c` | 1 byte | A lack of progress has happened |
| `G` | `c f i i`: `G`, score, remaining game time, remaining real-world time | 16 bytes | Reply to `G`. The times are in seconds. |

Note that the packet of `G` includes padding, since the `struct` format above aligns the float: the score starts at byte 4, and the times at bytes 8 and 12.

## Common Webots functions

| Function | Description |
|---|---|
| `robot.getDevice(name)` | Gets a device by name. In C++, use `robot->getMotor(name)`, `robot->getCamera(name)` and so on. |
| `robot.step(timeStep)` | Advances the simulation. It returns -1 when the simulation ends. |
| `robot.getTime()` | Gets the simulation time, in seconds |
| `device.enable(timeStep)` | Enables a sensor |
| `motor.setPosition(float("inf"))` | Lets the motor turn indefinitely |
| `motor.setVelocity(speed)` | Sets the speed of a motor, in radians per second |
