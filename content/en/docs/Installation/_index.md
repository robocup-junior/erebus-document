---
title: "Installation"
linkTitle: "Installation"
weight: 4
description: >
  This section explains how to setup the environment.
---

## Software Requirements
There are key components which make up the simulation system. These must each be installed. Although installation is easy, the download and install of Webots can take a little bit of time! The three components are:

1. Webots Robot Simulator Version **R2023b** - the simulation environment. Erebus v26 does not support other versions of Webots.
1. Erebus - the worlds and the Competition Supervisor, which implements the rules and scoring. The latest version is **v26.1**.
1. Python Version **3.9 or later** - needed to run Erebus itself, and to write controllers for the robots. You can also write controllers in C/C++.

## Minimum System Requirements
* OS-Linux: Ubuntu 20.04 LTS, 22.04 LTS
* OS-Windows: Windows 11, Windows 10 64-bit
* OS-Mac: macOS 11 "Big Sur" and 12 "Monterey". These are the versions supported by Webots R2023b. Newer versions of macOS may work too: this documentation was checked on macOS 26.
* CPU: Dual Core 2 GHz
* RAM: 2 GB
* Nvidia 512MB or AMD OpenGL 512MB

## Python libraries
Erebus needs the Python libraries below. Most of them are installed automatically when it starts, but **OpenCV is not**, so you must install it yourself or Erebus will stop with `No module named 'cv2'`. The guide of each operating system includes this step.

`python3 -m pip install numpy termcolor requests overrides pillow opencv-python`

## OpenGL settings
Unless organizers announce otherwise, the following OpenGL settings are used at the competition. They affect what the cameras see, so it is a good idea to test with them. You can find them in the Webots preferences, in the OpenGL tab.

| Setting | Value |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Installation Guide
