---
title: "Getting Started"
linkTitle: "Getting Started"
weight: 1
description: >
  Get your robot perform its first moves
---

## First Steps to start with Erebus
In this first tutorial you will run the sample code and run your first program on the Simulator

## Get the sample code
Get the [sample code](sample.py) and save it to your working location.


## Run the sample code
1. Run the world.wbt file from /game/worlds/newworld.wbt, opening it in Webots.
1. Press the LOAD CONTROLLER button in the Competition Controller displayed on the left side of the screen, and select the sample code you just downloaded.
{{< figure src="panel.jpg" class="center">}}  
When the program is loaded, the color of the LOAD CONTROLLER button changes to orange.
{{< figure src="loaded.jpg" class="center">}}  
1. When you press the start button, the robot appears in the world and starts moving.
{{< figure src="play.jpg" class="center">}}  
1. To stop the robot temporarily, press the pause button.
{{< figure src="pause.jpg" class="center">}}  
1. If the robot is stuck, pressing the RELOCATE button will relocate the robot to the last reached checkpoint.
{{< figure src="relocate.jpg" class="center">}}  
1. Press the reset button to reset the loaded program and the game in progress.
{{< figure src="reset.jpg" class="center">}}  


## Manually move the robot where you want it to go
When you click on a robot in the simulation window, red, blue, and green arrows will appear. You can move the robot to any position by grabbing this arrow with the mouse. Note that the robot will not be displayed until the program is started.
{{< figure src="manual.jpg" class="center">}}  

## Common problems & Fixes
### Competition Controller does not appear
1. If the Scene Tree is not displayed, go to Tools --> Scene Tree in the top menu to display it.
2. Find "DEF MAINSUPERVISOR Robot" in the Scene Tree and right-click it. Click on "Show Robot Window".
{{< figure src="showrobot.png" class="center" width="400">}}  
