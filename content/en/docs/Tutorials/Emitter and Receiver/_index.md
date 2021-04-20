---
title: "Emitter and Receiver"
linkTitle: "Emitter and Receiver"
weight: 1
description: >
  Communicate with the Main Supervisor
---

{{% pageinfo %}}
This page is under construction.
{{% /pageinfo %}}

## Basics

The emitter and receiver are used to communicate with the Main Supervisor, Erebus' game manager. The emitter can be used to <b>score victims or hazard maps</b> as well as signify the <b>end of run</b> to receive an exit bonus, while the receiver can be used to notify the robot controller in the event of a <b>Lack of Progress</b>.

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

#### Signaling End of Run

To signal to the Main Supervisor the end of run in order to receive an exit bonus, send the character <b>'E'</b> using the emitter:

{{< code-toggle file="endOfRun">}}
{{</code-toggle>}}

#### Lack of Progress

The receiver can be used to detect lack of progress messages sent by the Main Supervisor, so that the robot controller can respond accordingly:



{{< code-toggle file="LOP">}}
{{</code-toggle>}}
