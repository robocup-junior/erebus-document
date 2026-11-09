---
title: Troubleshooting
description: Solutions to common problems when installing and running Erebus.
---

First of all, check the Webots console. Most problems show an error message there.

## Installation

### `No module named 'cv2'`
OpenCV is not installed in the Python used by Webots. Install the [required libraries](/docs/installation/#python-libraries) in that Python. If you have several installations, the **Python command** setting below tells you which one Webots uses.

### `WARNING: Python was not found`
Webots does not know where Python is.

1. Find it. On macOS and Linux, run `which python3` in a terminal. On Windows, check that typing `python` in a new Command Prompt opens Python. If it does not, install Python again, ticking the option to add it to your PATH.
2. Open the Webots preferences: **Webots > Preferences** on macOS, **Tools > Preferences** on Windows and Linux.

   ![The Preferences item in the Webots menu](./preferences_open.png)

3. Set the path in the **Python command** field. On Windows, `python` is usually enough.

   ![The Python command field in the Webots preferences](./preferences.png)

### `ERROR: Skipped PROTO 'custom_robot'`
This appears the first time you open a world, before Erebus has prepared the robot model. Erebus prepares it and reloads the world by itself, so you can ignore it.

### The game timer does not appear
The first start can take some minutes while Erebus installs libraries. If it never finishes, check the console for errors. If the automatic installation does not work, install the [required libraries](/docs/installation/#python-libraries) yourself.

## Running Erebus

### The control window does not appear
The control window is a web page opened by Webots.

1. If you closed it, or your browser blocked it, reload the world with the reload button of Webots. Erebus opens the control window again.
2. Otherwise, make sure the Scene Tree is displayed, with **Tools > Scene Tree**.
3. Find **DEF MAINSUPERVISOR Robot** in the Scene Tree, right-click it and choose **Show Robot Window**.

The control window has a private address, which changes each time the world is loaded. If you open the window at `localhost:1234` yourself, it shows **Read-only**, and its buttons do not work.

### The control window says "Access log incomplete"
This warning appears when [Wireshark](/docs/installation/#optional-wireshark) is not installed. It is meant for organizers at competitions: press **Acknowledge**, and practice as usual.

![The Show Robot Window option in the Scene Tree](./showrobot.png)

### The Webots screen is blank or black
Copy the download and unzip it to a separate folder before opening the world.

### The simulation runs too slowly
This is probably due to the performance of your computer. Lowering the quality of the graphics may help:

1. Open the Webots preferences.
2. Open the **OpenGL** tab.
3. Change the settings.

![The OpenGL tab of the Webots preferences](./opengl.png)

These settings change what the cameras see, and the competition uses [its own settings](/docs/competition/#opengl-settings), so check your program with those too.

## Your robot

### My program says a device was not found
See below. Also check that you loaded your robot under **Robot JSON** in **Robot setup** before starting the game.

## Your program

### `Device "..." was not found`
The device name in your program does not match your robot. The names of the starter robot are in the [Reference](/docs/reference/parameters/#device-names-of-the-starter-robot). For your own robot, they are the names you set in the [Robot Customizer](/docs/robot/customizer/). Check that your robot has been loaded.

### Nothing happens when I report a wall token
Turn on **Enable debugging** in **Advanced setup** in the control window, and check the console. The most common causes are that the robot had not been stopped for at least 1 second, that the coordinates were not converted to centimetres, and that the robot or the position was more than half a tile (6 cm) from the token. See [Communication](/docs/programming/communication/#scoring-wall-tokens).

### My reports are misidentifications
The robot must be at most half a tile from the token and on the same side of the wall, and each token can only be scored once. Reporting a fake also counts as a misidentification.

### The game ends with "Battery depleted"
The battery ran out. Stop on a contact tile for 5 seconds to replace it before that happens. See [Battery](/docs/programming/battery/).

### My program no longer receives the game information
Since Erebus v27, the reply to `G` is 20 bytes long, with the battery level at the end. Update the check of the length in your program. See [Game information](/docs/programming/communication/#game-information).

### The map gets 0% or a scoring error
Your map must contain the starting tile (`5`), and it can only be evaluated once. See [Submitting the map](/docs/programming/map-bonus/).

### The controller cannot connect in remote mode
See the [Remote Controller](/docs/competition/remote-controller/) guide for your operating system.

## Still stuck?
Ask on the [Discord server](https://discord.com/invite/6FJxZxk), or [open an issue](https://github.com/robocup-junior/erebus/issues). Include your operating system, your Erebus and Webots versions, and the message in the console.
