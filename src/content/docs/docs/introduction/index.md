---
title: What is Erebus?
description: Erebus is the rescue simulation platform of RoboCupJunior, built on Webots. Learn how its parts fit together.
---

Erebus is a robot simulation competition environment. You develop a controller for a robot that autonomously explores a maze, finds and identifies wall tokens (letter victims and cognitive targets), avoids obstacles and traps, and builds a map of the environment.

It is built on [Webots](https://cyberbotics.com/), a robotic simulation platform designed for professional use and widely used in industry, education and research. Cyberbotics has maintained Webots continuously since 1998.

The platform is primarily designed for the [RoboCupJunior Rescue Simulation](https://junior.robocup.org/rescue/) competition. It is intended for intermediate to highly experienced programmers.

## How it fits together

| Component | What it does | Where to get it |
|---|---|---|
| **Webots R2023b** | The 3D robot simulator | [Webots R2023b release](https://github.com/cyberbotics/webots/releases/tag/R2023b) |
| **Erebus** | The worlds and the game manager (Main Supervisor), which applies the rules and calculates the score | [Erebus releases](https://github.com/robocup-junior/erebus/releases) |
| **Your controller** | Your robot's program, in Python or C/C++ | You write this! |
| **Robot Customizer** | Web tool to design a custom robot and export it as a JSON file | [robot.erebus.rcj.cloud](https://robot.erebus.rcj.cloud/) |
| **World Editor** | Web tool to draw practice maps and export them as `.wbt` worlds | [world.erebus.rcj.cloud](https://world.erebus.rcj.cloud/) |

## What can you do with it?

1. **Build a robot.** Choose its sensors and where they go, within a budget.
2. **Program it.** Your controller reads the sensors and decides what to do, with no human help.
3. **Run it.** Test it on the included worlds or on your own, and watch the score.
4. **Compete.** Take part in local, regional and international RoboCupJunior competitions.

If you already know Erebus, see [What's new in v26](/docs/whats-new/).

## Useful references
List of useful links for learning and working on the Erebus Simulator:
- [Webots User Guide](https://cyberbotics.com/doc/guide/index?version=R2023b)
- [Webots Reference Manual](https://cyberbotics.com/doc/reference/nodes-and-api-functions?version=R2023b)
- [Python Documentation](https://www.python.org/doc/)
- [C++ Documentation](https://www.cplusplus.com/doc/tutorial/)
- [OpenCV Tutorials](https://docs.opencv.org/4.x/d9/df8/tutorial_root.html)
- [RCJ Rescue Community Website](https://rescue.rcj.cloud/): events, team documents, and TDP, Poster and Video rubrics
- [RoboCupJunior Forum](https://junior.forum.robocup.org/): rule clarifications

## Next
[Install Erebus](/docs/installation/), then read the [Rules summary](/docs/rules/) to understand the game.
