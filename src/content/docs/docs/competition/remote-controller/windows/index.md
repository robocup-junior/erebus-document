---
title: Windows
description: How to set up the Remote Controller on Windows.
---

# Running the game server and controller programs on the same computer
First, try running the game server and your controller program on the same computer. This is not the same as the competition setup, but it is useful for debugging locally.

## Toggle remote mode
Open the world, press **Robot setup** in the control window, and turn on **Remote mode**. Load your robot under **Robot JSON** first, if you have a custom robot.  
![Remote mode, turned on in Robot setup](../mac/toggle_remote.png)

If the control window is not displayed, right-click "DEF MAINSUPERVISOR Robot" in the Scene Tree and choose "Show Robot Window".  
![The Show Robot Window option](./showRobotWindow.png)

## Execute your program
Open PowerShell. You can usually find it in the list of applications.  
![PowerShell in the list of applications](./powerShell.png)

Run the following command in PowerShell, replacing `<Your controller path>` with the path to your controller program.

`webots-controller.exe <Your controller path>`

If the command is not found, use its full path, which by default is `C:\Program Files\Webots\msys64\mingw64\bin\webots-controller.exe`.

If you do not know the path to your controller program, drag and drop the file into the PowerShell window, and its path is filled in automatically.  
![Dragging a file into the PowerShell window](./dragAndDrop.png)

Then press Enter to run the command. The controller connects to Webots and waits until the game starts.

## Start the game
Press **Run match** in the control window to start the game.  
![The Run match button of the control window](../../../getting-started/match-controls.png)

## Terminate the game
To stop the game, press Ctrl+C in PowerShell to stop your program.

When the game ends, press **Reset** to run it again. Remote mode is turned off by the reset, unless **Keep on Reset** is on.

# Running the game server on a different computer
This is the setup used at official competitions. The computer that runs your controller (the client) and the one that runs the game (the server) must be connected to the same network.

1. (Server) Start Webots on the server, open the world and turn on **Remote mode** in **Robot setup** of the control window.
2. (Server) Find the IP address of the server. See [Find your IP address in Windows](https://support.microsoft.com/en-gb/windows/find-your-ip-address-in-windows-f21a9bbc-c582-55cd-35e0-73431160a1b9).
3. (Client) Run the following command in PowerShell, replacing `<Your controller path>` with the path to your controller program and `<Server IP address>` with the IP address you found in the previous step.  
`webots-controller.exe --protocol=tcp --ip-address=<Server IP address> <Your controller path>`
4. (Server) Start the game by pressing **Run match**.

# Troubleshooting
If the controller cannot connect, check that the two computers can reach each other, that the firewall of the server allows TCP port 1234, and that the list of allowed IPs in the Network tab of the Webots preferences is empty or includes the client.

# Official documentation
For more details about this setup, see the [Webots guide](https://cyberbotics.com/doc/guide/running-extern-robot-controllers?version=R2025a).
