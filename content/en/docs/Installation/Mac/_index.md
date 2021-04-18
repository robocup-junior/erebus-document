---
title: "Mac"
linkTitle: "Mac"
weight: 3
description: >
  Installation Guide for macOS
---

## Installation & Setup Guide
1. Download & Install Python **3.8** 64 bit from the [official website](https://www.python.org/ftp/python/3.8.9/python-3.8.9-macosx10.9.pkg).  **Even if you have Python installed on your system via brew, anaconda, etc., we recommend that you install it afresh. Otherwise, the simulation may not work properly.** 

1. Download & Install the Webots version **2021.a** from their [official repository](https://github.com/cyberbotics/webots/releases/download/R2021a/webots-R2021a.dmg).

1. **Specify the Python path to Webots.**
    1. Open Webots -> Preferences.  
    ![](preferences_open.png)
    1. Set the following path to "Python command" field.  
    `/Library/Frameworks/Python.framework/Versions/3.8/bin/python3` 
    ![](preferences.png) 


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
2. If you don't see any errors, the automatic installation of the required libraries may not be working properly; start Terminal and run the following command.
  `/Library/Frameworks/Python.framework/Versions/3.8/bin/python3 -m pip install numpy termcolor requests`

### The simulation runs too slowly
This is probably due to the low performance of your computer. This may be improved by adjusting the "accuracy" of the graphics according to the following procedure.
1. Open Webots -> Preferences.
2. Open the OpenGL tab
3. Set the various parameters appropriately. In particular, it is recommended to enable "Disable shadows".
![](opengl.png)