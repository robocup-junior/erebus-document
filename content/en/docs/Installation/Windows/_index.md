---
title: "Windows"
linkTitle: "Windows"
weight: 2
description: >
  Installation Guide for Windows
---

## Quick Installation Guide
1. Download & Install Python **3.9** 64 bit from the [official website](https://www.python.org/ftp/python/3.9.4/python-3.9.4-amd64.exe). During the install option, please make your python installation is referenced in your PATH (see picture below!)
![](python-path.png)

1. Download & Install the Webots version **2021.a** from their [official repository](https://github.com/cyberbotics/webots/releases/download/R2021a/webots-R2021a_setup.exe).

1. Download and **extract** the latest Erebus [Release Build](https://gitlab.com/rcj-rescue-tc/erebus/erebus/-/releases).
![](download_erebus.png)


## Run the environment
Double click to run the world.wbt file from `/game/worlds/world1.wbt`, opening it in Webots.
The first time you run the simulator, it will automatically install the Python libraries needed to run the simulation, which may take some time (Initializing Process).

If the time limit is not displayed, as in the following image, the initializing process is in progress. This process can take up to a minutes, depending on the performance of your computer.  
![](initializing.png)


## Troubleshooting
### The initial processing is not finished forever
1. First of all, please check the console window. If you see any errors, you will need to try to resolve them.
2. If you don't see any errors, the automatic installation of the required libraries may not be working properly; start Powershell and run the following command.
  `python3 -m pip install numpy termcolor`

### If your Webots screen comes up blank/black
Copy and the download, unzip to a separate folder before opening the world. It should then work.

### Can't load a controller
This most likely means that Python has not been added to the Path correctly. To adress this:

1. Check to see if Python is in your path. Goto Command Prompt --> type PATH. Your will get some file lcoations returned. Is Python in this? If not add it using this method: https://datatofish.com/add-python-to-windows-path/
1/ To check this has worked, open a new command prompt windows and type 'python' - python should now open
1. Now tell Webots where python is. Open webots --> tools--> prefereces --> python command. enter 'python' of the same word used in your path.
Paths are messy and frustrating, and it can take a bit of work to iron out all the issues!
