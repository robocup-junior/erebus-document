---
title: Linux (Ubuntu)
description: How to set up the Remote Controller on Linux (Ubuntu 22.04 LTS).
---

# Running the game server and controller programs on the same computer
First, try running the game server and your controller program on the same computer. This is not the same as the competition setup, but it is useful for debugging locally.

## Toggle remote mode
Open the world, press **Robot setup** in the control window, and turn on **Remote mode**. Load your robot under **Robot JSON** first, if you have a custom robot.

![Remote mode, turned on in Robot setup](./toggle_remote.png)

If the control window is not displayed, right-click "DEF MAINSUPERVISOR Robot" in the Scene Tree and choose "Show Robot Window".

## Execute your program
Open a terminal and run the following commands, replacing `<Your controller path>` with the path to your controller program.

```bash
export WEBOTS_HOME=/usr/local/webots
"$WEBOTS_HOME/webots-controller" "<Your controller path>"
```

This assumes Webots was installed with the `.deb` package in `/usr/local/webots`. If you installed it elsewhere, change `WEBOTS_HOME` accordingly.

The controller connects to Webots and waits until the game starts.

## Start the game
Press **Run match** in the control window. The robot appears, and your program starts running.

## Terminate the game
To stop the game, press Ctrl+C in the terminal.

When the game ends, press **Reset** to run it again. Remote mode is turned off by the reset, unless **Keep on Reset** is on.

# Running the game server on a different computer
This is the setup used at official competitions. The computer that runs your controller (the client) and the one that runs the game (the server) must be connected to the same network.

1. (Server) Start Webots on the server, open the world and turn on **Remote mode** in **Robot setup** of the control window.
1. (Server) Find the IP address of the server, for example with the `ip addr` command.
1. (Client) Run the following commands, replacing `<Your controller path>` with the path to your controller program and `<Server IP address>` with the IP address you found in the previous step.

    ```bash
    export WEBOTS_HOME=/usr/local/webots
    "$WEBOTS_HOME/webots-controller" --protocol=tcp --ip-address=<Server IP address> "<Your controller path>"
    ```
1. (Server) Start the game by pressing **Run match**.

## Troubleshooting
- **The controller cannot connect:** check that the two computers can reach each other, for example with `ping`, that the firewall of the server allows TCP port 1234, and that the list of allowed IPs in the Network tab of the Webots preferences is empty or includes the client.
- **The controller waits, but the robot does not move:** check that **Remote mode** is on, and press **Run match**.
- **The controller does not find a Python library:** the program runs with the Python installation of the client, so install the library there.

# Official documentation
For more details about this setup, see the [Webots guide](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
