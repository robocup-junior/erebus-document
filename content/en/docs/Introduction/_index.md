---
title: "Introduction"
linkTitle: "Introduction"
weight: 1
description: >
  Introduction to the Erebus platform
---

## Erebus Rescue Simulator
Erebus is a robot simulation competition environment. You develop a controller for a robot that autonomously explores a maze, finds and identifies wall tokens (letter victims and cognitive targets), avoids obstacles and traps, and builds a map of the environment.

It is built on [Webots](https://cyberbotics.com/), a robotic simulation platform designed for professional use and widely used in industry, education and research. Cyberbotics has maintained Webots continuously since 1998.

The platform is primarily designed for the [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) competition. It is intended for intermediate to highly experienced programmers.

## How the platform fits together

| Component | What it does | Where to get it |
|---|---|---|
| **Webots R2023b** | The 3D robot simulator | [Webots R2023b release](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | The worlds and the game manager (Main Supervisor), which applies the rules and calculates the score | [Erebus releases](https://github.com/robocup-junior/erebus/releases) |
| **Your controller** | Your robot's program, in Python or C/C++ | You write this! |
| **Robot Customizer** | Web tool to design a custom robot and export it as a JSON file | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Web tool to draw practice maps and export them as `.wbt` worlds | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## What's new in v26
Erebus v26 implements the 2026 rules. If you are coming from an earlier version, these are the changes that affect your robot:

| Topic | Until 2025 | From 2026 |
|---|---|---|
| Letter victims | Letters H, S, U | Symbols Φ (harmed), Ψ (stable), Ω (unharmed). They are still reported as `H`, `S`, `U`. |
| Hazmat signs | Four hazmat labels | Replaced by [cognitive targets](/docs/rules/#cognitive-targets): concentric coloured rings whose values add up to the type. They are still reported as `F`, `P`, `C`, `O`. |
| Fake tokens | - | New: [fake victims](/docs/rules/#fake-victims) with three-dimensional letters, and cognitive targets whose sum is not 0 to 3. Do not report or map them. |
| Swamps | Time consumed 5x faster | The first entry into a swamp is x5, and each new entry into the same swamp adds 1, up to x10. |
| Obstacles on the map | Not mapped | Tiles with an obstacle are mapped as `x`. |
| Mapping bonus | Up to x2 | The multiplier is now correctness × 1.2 + 1. |
| Sensor noise | - | The GPS has noise. Organizers will not change the noise levels for the competition. |
| Game execution | Announced per event | Server-client setup: your controller runs on your own computer, connected to the game server by Ethernet. See [Remote Controller](/docs/tutorials/remotecontroller/). |
| Documents | TDP, Poster, Video | In addition, a short video showing how you run your controller in the server-client setup. |
| Missed games | -50 points | 0 points. |

The Webots version has not changed: Erebus v26 still runs on Webots **R2023b**.

The two versions released after v26.0.0 do not change the rules. v26.0.1 adds example worlds with fake victims and a script that turns victims of an existing world into fakes, and v26.1 fixes how obstacles are marked in Area 4.

## Useful references
List of useful links for learning and working on the Erebus Simulator:
- [Webots User Guide](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots Reference Manual](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python Documentation](https://www.python.org/doc/)
- [C++ Documentation](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV Tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue Community Website](https://rescue.rcj.cloud/): events, team documents, and TDP, Poster and Video rubrics
- [RoboCupJunior Forum](https://junior.forum.robocup.org/): rule clarifications
