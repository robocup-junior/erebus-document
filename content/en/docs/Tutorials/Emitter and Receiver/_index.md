---
title: "Emitter and Receiver"
linkTitle: "Emitter and Receiver"
weight: 7
description: >
  Communicate with the Main Supervisor
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The emitter and receiver are used to communicate with the Main Supervisor, Erebus' game manager. The emitter can be used to <b>score victims or hazard maps</b> as well as signify the <b>end of play</b> to receive an exit bonus, while the receiver can be used to notify the robot controller in the event of a <b>Lack of Progress</b>.

First, set up the emitter and receiver:

{{< code-toggle file="setup">}}
{{</code-toggle>}}

<b>Note:</b> In contrast to other devices, the emitter does not have to be enabled.

#### Scoring Game Elements

To earn points for identifying victim letters and hazard maps, the emitter should be used to report the position and the type of the game element. The message to the Main Supervisor should be formatted as follows:

X Pos <b>(integer),</b> Z Pos <b>(integer),</b> Victim Type <b>(character)</b>

<b>Note:</b> The X position and Z Position should be in <b>centimeters.</b> Thus, it is important to multiply the position given by the GPS by 100 to convert meters to centimeters.

{{< code-toggle file="scoring">}}
{{</code-toggle>}}

#### Signaling Lack of Progress

To call of lack of progress autonomously (using your program), send the character <b>'L'</b> using the emitter. The letter <b>'L'</b> will be sent back to the robot's receiver as per the <b>Lack of Progress</b> section below.

{{< code-toggle file="sendLOP">}}
{{</code-toggle>}}

#### Signaling End of Play

To signal to the Main Supervisor the end of play in order to receive an exit bonus, send the character <b>'E'</b> using the emitter:

{{< code-toggle file="endOfRun">}}
{{</code-toggle>}}

#### Lack of Progress

The receiver can be used to detect lack of progress messages sent by the Main Supervisor, so that the robot controller can respond accordingly:

{{< code-toggle file="LOP">}}
{{</code-toggle>}}

#### Game Information

Your program can retrieve the robot's current game score and the time remaining in your run. Use the emitter to send the character <b>'G'</b> to the supervisor, and it will send back a package that starts with the letter <b>'G'</b> and is followed by the score and time remaining:

{{< code-toggle file="gameInfo">}}
{{</code-toggle>}}