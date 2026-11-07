---
title: "Remote Controller"
linkTitle: "Remote Controller"
weight: 4
description: >
  This section explains how to use the remote controller setup, which is used at competitions.
---

The remote controller feature of Erebus allows you to run Webots simulations over a network. One computer runs the Webots simulation (the server), and the other computer runs the robot controller program (the client). We call this the "Server-Client Setup".

**According to the 2026 rules, this is how games are run at the competition.** Organizers run the game server and provide one RJ-45 socket. You need to bring:

- A computer with your program, ready to run, and with Webots R2023b installed
- An Ethernet cable. At least CAT5 is strongly recommended, to support 100 Mbit/s.
- An Ethernet port. If your computer does not have one, bring an adapter and test it in advance.

For smooth onboarding at the competition site, try out the setup well in advance. All teams must also submit a short video showing how they run their controller on an example map in this setup, along with the TDP, Poster and Video.

## How it works

1. Open the world and turn on remote mode in the control window.
1. Start your controller from a terminal. It connects to Webots and waits.
1. Press the start button in the control window.

Your controller uses the same Webots libraries and the same code as when it is loaded with the LOAD button. The custom robot, if you have one, is still loaded in the control window of the server.

## Things to check before the competition

- All the libraries your program needs are installed on the client.
- Your program does not depend on the speed of the computer: it must use `robot.step()` and the simulation time. Note that an image from the camera must travel through the network.
- Any image windows (like `cv2.imshow`) are turned off, unless you need them.
- You know the commands to run by heart. Writing them in a small script is a good idea.

## Setup Guide
