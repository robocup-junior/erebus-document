---
title: "Navigate the maze"
linkTitle: "Navigate the maze"
weight: 8
description: >
  In this seminar we cover how to generate a first robot controller to navigate around a maze like environment.
---
## Introducing Your Robot
In this challenge, the robot is a customizable e-puck. You can design your robot [here](https://robot.erebus.rcj.cloud/), adding the optimal sensors at the optimal positions. From there, you can export your robot as a JSON file, which you can then load into the robot window in Webots.

{{< figure src="real_robot.thumbnail.jpg" class="center">}}

## Field
For the sample program, we will be working in a field similar to the one shown below. If you are unfamiliar with how to load the various worlds, see [Getting Started](/docs/tutorials/getting-started/).

{{< figure src="field1.png" class="center" width="600">}}


## Tasks/Activities
After working on this seminar, work through the following tasks (of increasing difficulty):

* Investigate different speeds/motions and sensor values - what is the most efficient values for navigating around the maze?
* Alter the program to track around in the side walls of the maze. To do this think about how you could use the distance sensors from one side of the robot to track along a wall. You will still need to use the front distance sensors, so think carefully about what order to put your if statements for the different sensors!
* To search quicker, could you vary the speed depending on how close you are to walls/objects? Look at using the sensor values to calculate the speed of the wheels.

Remember, for help/advice, or if you want to share ideas, head to [discord](https://discord.com/invite/6FJxZxk).

## Exemplar Code
Below we step through the example code developed step by step, explaining what is going on. Try and build this up by yourself first, referring back to this if you need. The full uninterrupted program can be found here: <a href="sample.cpp" download>C++</a> | <a href="sample.py" download>Python</a>

---

## Step-by-Step Introduction of the Code
First we initialize the robot and sensors. We import/include the necessary classes as we set the time step and also the maximum velocity of the robot. We also create a wheel_left and wheel_right object. (More details on the API can be found [here](https://cyberbotics.com/doc/reference/nodes-and-api-functions)). Lastly, we initialize an array to store the left and right motor speeds - we start by initializing these to the max speed.

{{< code-toggle file="moving1">}}
{{</code-toggle>}}

In the next step of the program, we initialize our distance sensors, camera, color sensor, emitter, and GPS. Remember that you can customize your own robot [here](https://robot.erebus.rcj.cloud/). Here is the layout for our sample robot:
1. Three distance sensors facing left, forward, and right
2. One forward facing camera for wall token detection
3. One downward facing color sensor to detect black pits
4. One GPS for the robot's position when reporting wall tokens
5. An emitter for reporting wall tokens (not in diagram, on robot by default)

Here is the JSON file for the sample robot: <a href="SampleRobot.json" download>Sample Robot JSON</a>

{{< figure src="robot.png" class="center">}}

{{< code-toggle file="moving2">}}
{{</code-toggle>}}

Next, we set the 'position', we set this to be infinite, as this allows the wheels to turn infinitely, they are not limited by turning a certain amount.

{{< code-toggle file="moving3">}}
{{</code-toggle>}}

We setup some functions which we can then call to set the movement of the robot. In each of these we set the speed of the left and right wheel using the speeds list. We also define a delay function for prolonged movements and a getColor function to retrieve the brightness level seen by the color sensor (grayscaled value from 0 (black) to 255 (white)).

{{< code-toggle file="moving4">}}
{{</code-toggle>}}

We also create a function to help detect wall tokens. It accepts a camera image and returns true if it detects something that may be a victim. It searches for contours (a contiguous shape within the image) whose area and width to height ratio fit within a certain range. Note that this function is by no means the optimal solution: it is prone to misdetections, can miss victims, and cannot tell apart different symbols, cognitive targets or fakes - it is meant as an introduction for you to improve upon, for example with the [Wall Tokens tutorial](/docs/tutorials/wall-tokens/). Remember that every misidentification costs 5 points.

After retrieving the image from the camera sensor, this function uses OpenCV to scan for victims. OpenCV for C++ can be difficult to install, and OpenCV in and of itself can be difficult to learn. Thus, if you feel a different method of victim detection will suffice, by all means comment out this function and implement your own solution. Do note, however, that the best solution essentially requires OpenCV or some other image processing library and that the internet has many useful resources for learning OpenCV.

{{< code-toggle file="moving5">}}
{{</code-toggle>}}

To receive points for a wall token, you must stop for at least 1 second and then report its location and type to the supervisor. The following function accepts a character for the type and reports it to the supervisor.

{{< code-toggle file="moving6">}}
{{</code-toggle>}}

Here we have the main body of the program. First we setup a while loop that runs whilst the game is running (i.e. for the 8 minutes of the game). It first checks for walls on the left, right, and front side, and turns away from any detected walls. It then uses the color sensor to check for a black pit, spinning away if detected. Lastly, it checks for a victim in view of the front camera and reports anything it sees. Since the sample detection function is unable to differentiate between symbols, it always reports 'H' (harmed) as a guess. If the guess is wrong you still score the identification, but not the correct type bonus.

{{< code-toggle file="moving7">}}
{{</code-toggle>}}

That about concludes the sample program. Again, you can find the uninterrupted full programs here: <a href="sample.cpp" download>C++</a> | <a href="sample.py" download>Python</a>. Note that this sample program is by no means an optimal solution, it is just meant to introduce you to working in the Webots environment in Rescue Simulation. Good luck programming!