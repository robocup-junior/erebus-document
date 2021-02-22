---
title: "Windows"
linkTitle: "Windows"
weight: 2
description: >
  Installation Guide for Windows
---

## Installation Guide
1. Download & Install Python 3.7 64 bit from the [official website](https://www.python.org/ftp/python/3.7.8/python-3.7.8-amd64.exe). Check out this great installation guide if you need some help! During the install option, please make your python installation is referenced in your PATH (see picture below!)
![](python-path.png)

1. Download & Install the Webots version 2020.a revision 1 from their [official repository](https://github.com/cyberbotics/webots/releases/download/R2020a-rev1/webots-R2020a-rev1_setup.exe).

1. Download and extract the latest Erebus [Release Build](https://github.com/Shadow149/RescueMaze/releases).

## Run the environment
Run the world.wbt file from `/game/worlds/newworld.wbt`, opening it in Webots.

## Common problems & Fixes
* **If your Webots screen comes up blank/black.** Copy and the download, unzip to a separate folder before opening the world. It should then work.
* **Can't load a controller.** This most likely means that Python has not been added to the Path correctly. To adress this:

1. Check to see if Python is in your path. Goto Command Prompt --> type PATH. Your will get some file lcoations returned. Is Python in this? If not add it using this method: https://datatofish.com/add-python-to-windows-path/
1/ To check this has worked, open a new command prompt windows and type 'python' - python should now open
1. Now tell Webots where python is. Open webots --> tools--> prefereces --> python command. enter 'python' of the same word used in your path.
Paths are messy and frustrating, and it can take a bit of work to iron out all the issues!
