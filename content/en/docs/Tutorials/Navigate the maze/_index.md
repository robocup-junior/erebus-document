---
title: "Navigate the maze"
linkTitle: "Navigate the maze"
weight: 4	
description: >
  In this seminar we cover how to generate a first robot controller to navigate around a maze like environment.
toc_hide: true
---

> *Use parts of this tutorial in the component specific tutorials.*

> *This tutorial could be used after the component tutorials as a bigger project oriented one*


{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Introducing Your Robot
In this challenge, the robot is fixed and as Epuc (this is actually a real world robot!) Your robot has a number of components:
* Left and Right wheels. Can be controlled independently to set the speed
* Distance Sensors. A number of distance sensors around the robot to detect walls/objects
* Camera. Two RGB cameras on the front of the robot to provide visual information

{{< figure src="real_robot.thumbnail.jpg" class="center">}}


## Field
The field/environment which accompanies this tutorial (and is shown to the right) can be downloaded [here](https://drive.google.com/file/d/1_SvSJFczGxnr_OfCWiB8iGYwRkC1bd2f/view).  
Once downloaded, copy the files into `/game/world`.  
{{< figure src="field1.png" class="center">}}
We also have a short video showing how to change fields [here](https://youtu.be/VjHYlgjHD74).

## Tasks/Activities
After working on this seminar, work through the following tasks (of increasing difficulty):

* Investigate different speeds/motions and sensor values - what is the most efficient values for navigating around the maze?
* Alter the program to track around in the side walls of the maze. To do this think about how you could use the distance sensors from one side of the robot to track along a wall. You will still need to use the front distance sensors, so think carefully about what order to put you if statements for the different sensors!
* To search quicker, could you vary the speed depending on how close you are to walls/objects? Look at using the sensor values to calculate the speed of the wheels.

Remember, for help/advice, or if you want to share ideas, head to [discord](https://discord.com/invite/6FJxZxk).

## Exemplar Code
Below we step through the example code developed step by step, explaining what is going on. Try and build this up by yourself first, referring back to this if you need. The full uninterrupted program can be found [here](https://github.com/Shadow149/RescueMaze/blob/master/docs/tutorials/code1.py).

---

If you are new to Python, please don't worry, we will try and explain as we go along. One thing to watch out for is that the spacing/tabbing really matters, so be careful with that. This are also many useful Python 'cheat' sheets online such as [this one](https://perso.limsi.fr/pointal/_media/python:cours:mementopython3-english.pdf) to help you.

## Step-by-Step Introduction of the Code
First we initialise the robot and sensors. We import the controller class as we set the timestep and also the maximum velocity of the robot. We also set create a wheel_left and wheel_right object. (More details on the API can be found [here](https://github.com/Shadow149/RescueMaze/wiki/Abstraction-Layer)).

{{< code-toggle file="moving1">}}
{{</code-toggle>}}

In the next step in the program, we get the distance sensor readings, stored them in the lists and enable the sensors to update with ever time step.

The robot has an number of distance sensors with two front, two left, two right and two backwards (for details about the robot and sensors visit the Webots site [here](https://cyberbotics.com/doc/guide/epuck). The picture here shows the location of these on the robots, and how they are named:

{{< figure src="sensors_and_leds.png" class="center">}}


{{< code-toggle file="moving2">}}
{{</code-toggle>}}

Next, we create an array in which we set the speeds - we start by initalizing these to the max speed (which we defined at the beginning). We also set the 'position', we set this to be infinite, as this allows the wheels to turn infinitely, they are not limited by turning a certain amount.

{{< code-toggle file="moving3">}}
{{</code-toggle>}}

We setup some functions which we can then call to set the movement of the robot. In each of these we set the speed of the left and right wheel using the speeds list.

{{< code-toggle file="moving4">}}
{{</code-toggle>}}

{{< python-specific>}}
Here we have the main body of the program. First we setup a while loop that runs whilst the game is running (i.e. for the 8 minutes). We do this using `while robot.step(timeStep) != -1:` - so while the simulation is running and progressing, this will be true, and hence the while loop will run.

We then have a number of if statements, that check the different sensors to detect walls or obstacles. First, we consider the left and right sensors. There are two of each of the sensors so we loop through these using a for loop with a range of 2 `for i in range(2):`. Inside this, we then check to see if the sensors are below 80, and is we then turn the correct way to avoid the wall. Now, how do we decide what sensor value to use? The figure below shows the values that you return from the distance sensors - Y-axis is the sensor value (units), X-axis is the distance from the sensor in meters.
{{</python-specific>}}

{{< c-specific>}}
C-specific explanations here.  
You can use markdown format.
{{</c-specific>}}


{{< figure src="distance_sensor_lookup_table.png" class="center">}}

As you can see 80 corresponds to around xxx, which is a reasonable choice give the size of the worlds we are considering.

Next we also check the two front sensors. Note, we put this **after** the left and right sensors as this is higher priority - we do not want to crash into walls

At the end of the while loop, the last two commands then take the speeds we have set in the speeds array, and actually set the wheels to these positions using `wheel_left.setVelocity(speeds[0])` and the equivalent for the right.

{{< code-toggle file="moving5">}}
{{</code-toggle>}}
