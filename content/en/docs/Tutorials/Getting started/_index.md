---
title: "Getting Started"
linkTitle: "Getting Started"
weight: 1
description: >
  Get your robot to perform its first moves
---

## First Steps to start with Erebus
In this first tutorial you will run the sample code and run your first program on the Simulator.  
This assumes you have correctly installed Webots and downloaded the release. If not please visit the [installation page](/docs/installation/).



## Run the sample code
1. Run the world.wbt file from /game/worlds/world1.wbt, opening it in Webots.
1. Press the LOAD button in the Competition Controller displayed on the left side of the screen, and select the sample code included in the release you just downloaded located in the "player_controllers" folder (currently the general sample code is named "ExamplePlayerController_updated.py").
{{< figure src="main_screen_unloaded.png" class="center">}}  
When the program is loaded, the colour of the LOAD button changes to orange.
{{< figure src="main_screen_loaded.png" class="center">}} 
1. The interface to control the simulation is shown below. The top band is for loading the robot controller and a custom robot if you do make one (see [here](https://erebus.rcj.cloud/docs/rules/the-robot/) for more info). Two bands below, the three circular buttons is what you will use to interact with the simulation once the robot is moving. Below that, the remaining time and the current score is displayed.
{{< figure src="controller.png" class="center" size="height:300px">}}  
1. When you press the start button, the robot appears in the world and starts moving.
{{< figure src="start_button.png" class="center" size="width:100px">}}  
1. To stop the robot temporarily, press the pause button.
{{< figure src="pause_button.png" class="center" size="width:100px">}}  

1. If the robot is stuck, pressing the restart button will trigger a lack of progress to relocate the robot to the last reached checkpoint.
{{< figure src="lop_button.png" class="center" size="width:100px">}}  
1. Press the reset button to reset the loaded program and the game in progress. The setting button on the left hand side of the reset button allows you to toggle some debugging options.
{{< figure src="reset_buttons.png" class="center" size="width:300px">}} 


## Manually move the robot where you want it to go
When you click on a robot in the simulation window, red, blue, and green arrows will appear. You can move the robot to any position by grabbing this arrow with the mouse. Note that the robot will not be displayed until the program is started.
{{< figure src="manual.png" class="center">}}  

## Common problems & Fixes
### Competition Controller does not appear
1. If the Scene Tree is not displayed, go to Tools --> Scene Tree in the top menu to display it.
2. Find "DEF MAINSUPERVISOR Robot" in the Scene Tree and right-click it. Click on "Show Robot Window".
{{< figure src="showrobot.png" class="center" width="400">}}  
