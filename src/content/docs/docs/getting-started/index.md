---
title: Your first run
description: Get your robot to perform its first moves.
---

In this page you will run the sample code and run your first program on the simulator.
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

![The Erebus control window](./control_window.png)

| Part | Use |
|---|---|
| Left **LOAD** (laptop icon) | Loads the controller program of your robot |
| Right **LOAD** (robot icon) | Loads a custom robot (`.json` file). Without one, the [default robot](/docs/robot/) is used. |
| **TOGGLE REMOTE** | Lets a program running outside Webots control the robot. See [Remote Controller](/docs/competition/remote-controller/). |
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
![Start button](./start_button.png)
1. To stop the robot temporarily, press the pause button.
![Pause button](./pause_button.png)
1. If the robot is stuck, pressing the restart button will trigger a lack of progress, which relocates the robot to the last reached checkpoint and costs 5 points.
![Lack of progress button](./lop_button.png)
1. Press the Reset button to reset the loaded program and the game in progress. Reload the world if you want to run it again after a game has ended.

While the game is running, the score history appears at the bottom of the window. It tells you exactly why you gained or lost points, so it is the best tool to check your program.

![The control window during a game, with the score history](./control_window_running.png)

At the end of the game, the same information is saved in the `game/logs` folder.

## Using other worlds
Press **Worlds** to change to another world. Each world has a thumbnail, and you can also add your own, made with the [World Editor](/docs/tools/world-editor/).

![The Worlds tab of the control window](./worlds.png)

The worlds included in Erebus v26.1 are:

| World | Purpose |
|---|---|
| `world1.wbt`, `world2.wbt` | Example worlds. `world2.wbt` includes Area 4. |
| `world3.wbt`, `world4.wbt` | Larger example worlds, which also include **fake victims** |
| `mapping_example_1.wbt` to `mapping_example_3.wbt` | Worlds to test your mapping. See [Mapping](/docs/rules/mapping/). |
| `NewPassages.wbt` | Example of the passages between areas |

## Settings
![The Settings tab of the control window](./settings.png)

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
![The robot selected in Webots, with arrows to move it](./manual.png)

## Programming languages
Python programs can be loaded directly. C and C++ programs must be [compiled first](/docs/programming/cpp/).

## What to read next
- [The Robot](/docs/robot/): what your robot has, and how to customize it
- [Movement](/docs/robot/movement/) and [Sensors](/docs/robot/sensors/): the basics of controlling it
- [Navigate the maze](/docs/programming/navigate-the-maze/): a first complete program
- [Communication](/docs/programming/communication/): how to score points
- [Wall Tokens](/docs/programming/wall-tokens/): how to tell victims, targets and fakes apart

If something does not work, see [Troubleshooting](/docs/troubleshooting/).
