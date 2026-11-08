---
title: FAQ
description: Frequently asked questions about Erebus and the competition.
---

## About Erebus

### Do I need a real robot?
No. Everything happens in the simulator. The robot is a virtual e-puck that you design.

### Which programming languages can I use?
Python and C/C++ are covered in this documentation. Erebus can also load Java and MATLAB controllers, but this documentation has no examples for them.

### Is a powerful computer needed?
No, see the [requirements](/docs/installation/). Slower computers may need [lower graphics settings](/docs/troubleshooting/#the-simulation-runs-too-slowly).

### Can I use a newer version of Webots?
No. Erebus v26 runs on Webots **R2023b**. You can keep other versions installed next to it.

### Can I use libraries like OpenCV or NumPy?
Yes. External code is allowed, as long as you credit its creators and respect its license. Teams should prioritize learning, and must be able to explain how their solution works.

## The game

### What is the best order to learn things?
Follow [the learning path](/docs/#the-learning-path): understand the game, get your robot, run it, learn the basics, then play the game.

### Do I need to make a robot before programming?
Yes. Every program runs on a robot you load, so start with [Get your robot](/docs/robot/). You can download the finished starter robot if you are in a hurry.

### Where does the robot start?
On the starting tile, which is in Area 1. It always faces a direction without a wall.

### What happens if the robot falls into a hole?
A lack of progress occurs: the robot returns to the last checkpoint it visited, and you lose 5 points.

### Does the robot have to return to the start?
No, but returning to the starting tile and sending `E` gives a 10% exit bonus, as long as it has identified at least one wall token.

### How can my robot tell how much time is left?
With the [`G` message](/docs/programming/communication/#game-information). There are two timers, and the game time runs faster in swamps.

### Do I have to explore Area 4?
No. It is optional, but its tokens are worth the most: the highest points, multiplied by 2.

### Do I have to map Area 4?
No. All of its cells are `*`, so you only need to fill them in.

### Can my robot know the map beforehand?
No. Pre-mapping the field or the location of wall tokens is prohibited.

## The competition

### How do I take part?
Through your regional RoboCupJunior competition. Your Regional Representative assigns the places for the international competition. See the [RoboCupJunior website](https://junior.robocup.org/).

### What should I prepare?
See [Preparing for a competition](/docs/competition/).

### Where can I ask about the rules?
On the [RoboCupJunior Forum](https://junior.forum.robocup.org/). Clarifications are also posted there, so check it regularly.
