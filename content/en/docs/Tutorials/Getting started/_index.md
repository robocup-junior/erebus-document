---
title: "Getting Started"
linkTitle: "Getting Started"
weight: 1
description: >
  Get your robot to perform its first moves
---

## First Steps to start with Erebus
In this first tutorial you will run the sample code and run your first program on the simulator.
This assumes you have correctly installed Webots and downloaded the release. If not, please visit the [installation page](/docs/installation/).

## The Erebus folder
These are the main folders of the release you downloaded:

| Folder | Contents |
|---|---|
| `game/worlds` | The worlds (`.wbt` files). Open one of them to start. |
| `game/logs` | The game logs written at the end of each game |
| `player_controllers` | Example controllers |

## The control window
1. Open `game/worlds/world1.wbt` in Webots.
1. Webots opens the Erebus control window (the robot window of the Main Supervisor) in your web browser. This is where you load your program and run the game.

{{< figure src="control_window.png" class="center">}}

| Part | Use |
|---|---|
| Left **LOAD** (laptop icon) | Loads the controller program of your robot |
| Right **LOAD** (robot icon) | Loads a custom robot (`.json` file). Without one, the [default robot](/docs/tutorials/the-robot/) is used. |
| **TOGGLE REMOTE** | Lets a program running outside Webots control the robot. See [Remote Controller](/docs/tutorials/remotecontroller/). |
| **Docker path** | Folder with a `Dockerfile`, to run your controller in a container with the Docker button next to the play button. See the [erebus-dockerfiles](https://github.com/robocup-junior/erebus-dockerfiles) repository. This is optional. |
| **Settings** | Links and options, explained below |
| **Worlds** | Changes to another world |
| **Reset** | Resets the loaded program and the game |
| **Give up!** | Ends the game |
| Timers | The game time, and below it the real-world time in brackets. The game ends when either of them reaches 0. |
| Calculator | The current score |

## Run the sample code
1. Press the left LOAD button, and select the sample code included in the release, in the `player_controllers` folder. The general sample code is `ExamplePlayerController_updated.py`. When the program is loaded, the LOAD button turns into an orange REMOVE button.

1. When you press the start button, the robot appears in the world and starts moving.
{{< figure src="start_button.png" class="center" size="width:85px">}}
1. To stop the robot temporarily, press the pause button.
{{< figure src="pause_button.png" class="center" size="width:60px">}}
1. If the robot is stuck, pressing the restart button will trigger a lack of progress, which relocates the robot to the last reached checkpoint and costs 5 points.
{{< figure src="lop_button.png" class="center" size="width:60px">}}
1. Press the Reset button to reset the loaded program and the game in progress. Reload the world if you want to run it again after a game has ended.

While the game is running, the score history appears at the bottom of the window. It tells you exactly why you gained or lost points, so it is the best tool to check your program.

{{< figure src="control_window_running.png" class="center">}}

At the end of the game, the same information is saved in the `game/logs` folder.

## Using other worlds
Press **Worlds** to change to another world. Each world has a thumbnail, and you can also add your own, made with the [World Editor](/docs/tutorials/map-creator/).

{{< figure src="worlds.png" class="center">}}

The worlds included in Erebus v26.1 are:

| World | Purpose |
|---|---|
| `world1.wbt`, `world2.wbt` | Example worlds. `world2.wbt` includes Area 4. |
| `world3.wbt`, `world4.wbt` | Larger example worlds, which also include **fake victims** |
| `mapping_example_1.wbt` to `mapping_example_3.wbt` | Worlds to test your mapping. See [Mapping](/docs/rules/mapping/). |
| `NewPassages.wbt` | Example of the passages between areas |

## Settings
{{< figure src="settings.png" class="center">}}

| Setting | Use |
|---|---|
| Keep controller/robot files | Keeps your program and robot loaded when the world is reloaded |
| Disable automatic LoP | Stops the automatic lack of progress after 20 seconds. Only for debugging. |
| Automatic camera | Makes the view follow the robot |
| Recording | Records the game as a video |
| Keep remote controller on | Keeps TOGGLE REMOTE on when the world is reloaded |
| Enable debugging | Prints extra information in the Webots console, for example why a wall token report was rejected |

The links at the top lead to the changelog and to tools for making worlds and robots. To make worlds with the 2026 rules, use the [World Editor](https://world.erebus.rcj.cloud/).

## Manually move the robot where you want it to go
When you click on a robot in the simulation window, red, blue, and green arrows will appear. You can move the robot to any position by grabbing these arrows with the mouse. Note that the robot will not be displayed until the program is started.
{{< figure src="manual.png" class="center">}}

## Programming languages
Python programs can be loaded directly. C/C++ programs must be compiled first, for example with the Webots [controller](https://cyberbotics.com/doc/guide/controller-programming?version=R2023b) tools, and you load the resulting executable (`.exe` on Windows).

## What to read next
- [The Robot](/docs/tutorials/the-robot/): what your robot has, and how to customize it
- [Movement](/docs/tutorials/movement/) and [Sensors](/docs/tutorials/sensors/): the basics of controlling it
- [Navigate the maze](/docs/tutorials/navigate-the-maze/): a first complete program
- [Emitter and Receiver](/docs/tutorials/emitter-and-receiver/): how to score points
- [Wall Tokens](/docs/tutorials/wall-tokens/): how to tell victims, targets and fakes apart

## Common problems & Fixes
### The Competition Supervisor does not appear
1. If the Scene Tree is not displayed, go to Tools --> Scene Tree in the top menu to display it.
2. Find "DEF MAINSUPERVISOR Robot" in the Scene Tree and right-click it. Click on "Show Robot Window".
{{< figure src="showrobot.png" class="center" width="400">}}

3. If the Supervisor tab still does not open, try to open the following [link](http://localhost:1234/robot_windows/MainSupervisorWindow/MainSupervisorWindow.html?name=robot) in your browser manually.

### Nothing happens when I report a wall token
Check the Webots console, and turn on **Enable debugging** in Settings. The most common causes are that the robot had not been stopped for at least 1 second, and that the coordinates were not converted to centimeters. See [Emitter and Receiver](/docs/tutorials/emitter-and-receiver/#scoring-wall-tokens).
