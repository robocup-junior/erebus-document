---
title: Rules summary
description: "A summary of the RoboCupJunior Rescue Simulation 2027 rules: the field, wall tokens, the battery, scoring and the competition."
---

:::note
This page is a summary to help you get started. The only official rules are the [RoboCupJunior Rescue Simulation Rules 2027](https://junior.robocup.org/wp-content/uploads/2026/09/RCJRescueSimulation2027-draft.pdf). This summary follows the version last updated on 2026-10-24. If this page and the official rules differ, the official rules apply.

Corrections and clarifications are posted on the [official RoboCupJunior Forum](https://junior.forum.robocup.org/). It is the responsibility of each team to check them.
:::

## The game in one minute
Your robot is dropped into an unknown maze, alone. In 8 minutes, with no help from you, it must:

1. **Explore** the maze without getting stuck or falling into holes.
2. **Find the wall tokens**, the victims and cognitive targets on the walls, and report what each one is.
3. **Keep its battery charged**, by stopping on a contact tile before it runs out.
4. **Map** the maze, and send the map at the end.
5. **Return** to where it started.

Everything below explains these five jobs in detail. You do not need to remember it all now: come back to it as you program each part.

## Mission and objective
![Top view of an Erebus field with four areas](./rules_environment.png)

The robot must autonomously explore an unknown environment while keeping itself out of trouble. There are three main missions:

- Navigating a complex maze without getting stuck
- Mapping the environment accurately
- Finding and identifying wall tokens: smiley victims and cognitive targets

## The field
The field consists of up to four areas. Area 1 is always part of the field, and organizers may leave out Areas 2 to 4. Each passage between areas is one standard tile wide. Tiles are a concept used to generate the field, not physical structures.

- A tile is **12 cm × 12 cm**. In Areas 2 and 3, each tile is subdivided into four **quarter tiles** of 6 cm × 6 cm.
- Walls are **1 cm thick and 6 cm high**.
- Pathways are at least as wide as the robot, and may open into wider foyers.

![Examples of the wall layouts of areas 1, 2 and 3](./rules_tiles.png)

| Area | Walls | Notes |
|---|---|---|
| Area 1 | Can be placed on the edges of each tile | The starting tile is in this area |
| Area 2 | Can be placed on the edges of each quarter tile | |
| Area 3 | Can be placed on the edges of each quarter tile | 90° corners can be rounded into a quarter circle |
| Area 4 (optional) | Not based on tiles; walls and obstacles are placed arbitrarily | May contain objects such as boxes, and may require diagonal movement |

### Passages between areas
Passages are single tiles with walls on two sides, so that they have an unambiguous entrance and exit. Their floor colour tells you which areas they connect:

![Table of the passage colours between each pair of areas](./rules_passages.png)

Wall tokens are not placed on the walls of passages.

### Linear and floating tiles
Tiles that lead to the starting tile by consistently following the leftmost or rightmost wall are **linear tiles**. All the others are **floating tiles**. Tokens on floating tiles are worth more points. Quarter tiles are not taken into account, and holes count as virtual walls here.

![A field showing linear tiles in grey and floating tiles in pink](./rules_linear_floating.png)

### Checkpoints
Silver tiles are checkpoints, and they can be anywhere on the field. Area 4 contains checkpoints immediately after its passages. After a lack of progress, the robot restarts from the last checkpoint it visited.

## Swamps, obstacles and holes
![A field with a swamp, a hole and an obstacle](./rules_obstacles.png)

* **Swamps** (brown tiles) make the battery drain faster while the robot is on them, since the motors have to work harder. The game time is not affected.
* **Obstacles** may be fixed to the floor, may have any shape and colour, and affect the width of the pathway. In Areas 1 to 3, the centre of an obstacle is always on a tile, never on the edge between tiles, and there is at most one obstacle per tile.
* **Holes** are tiles with an opening in the floor. Their edges are black, 1.5 cm from the neighbouring tiles. If the robot falls into one, a lack of progress occurs.

No tile is more than one of the following at the same time: swamp, hole, checkpoint, contact tile, starting tile, tile with an obstacle, or area passage.

## Contact tiles
Contact tiles are **cyan** tiles where the robot's battery can be replaced during the game. The robot must stay still on the tile while its battery is being replaced. See [The battery](#the-battery).

![A field with cyan contact tiles](./rules_contact_tiles.png)

## Wall tokens
There are two kinds of wall tokens: smiley victims and cognitive targets. Both can appear on any wall, including curved surfaces, except the walls of the passages between areas. Smiley victims can also be rotated to any angle, from 0 to 360 degrees.

![Cognitive targets and smiley victims on the walls of a field](./rules_wall_tokens.png)

### Smiley victims
Smiley victims are 2 cm × 2 cm images of a smiley-face emoji, printed in black. The facial expression represents the health status of the victim, and the code is the letter you report and write on the map.

| Status | Face | Code |
|---|---|---|
| Harmed | Sad | `H` |
| Stable | Neutral | `S` |
| Unharmed | Happy | `U` |

![A sad, a neutral and a happy face](./rules_victims.png)

### Fake victims
Some wall tokens show the same faces, but the emoji are **three-dimensional**. They are fake: you must not report them to the supervisor or include them on the map. The rules state that this depth can be detected with one of the sensors available in the Robot Customizer.

![Fake victims with three-dimensional faces on a wall](./rules_fake_victims.png)

### Cognitive targets
Cognitive targets represent hazmats. They are circles with a diameter of 5 cm made of five concentric parts, with diameters of 1, 2, 3, 4 and 5 cm. Each colour has a value:

| Black | Red | Yellow | Green | Blue |
|---|---|---|---|---|
| -2 | -1 | 0 | 1 | 2 |

Add up the values of all five parts to get the type. If the sum is not listed below, the target is a fake wall token and must not be reported or mapped.

| Sum | Hazmat | Code |
|---|---|---|
| 0 | Flammable Gas | `F` |
| 1 | Poison | `P` |
| 2 | Corrosive | `C` |
| 3 | Organic Peroxide | `O` |

Adjacent rings of the same colour are **not** merged: always count all five, even when colours repeat.

![Two example cognitive targets, one valid and one fake](./rules_cognitive_example.png)

The left target is Yellow, Blue, Red, Black, Green from the centre outwards: 0 + 2 - 1 - 2 + 1 = 0, so it is Flammable Gas (`F`). The right target is Blue, Yellow, Black, Black, Black: 2 + 0 - 2 - 2 - 2 = -4, so it is fake.

The [Wall Tokens tutorial](/docs/programming/wall-tokens/) shows how to read a target with a camera.

## The robot
- Teams use the robot model provided by the organizers, and may customize it with the [Robot Customizer](https://robot.erebus.rcj.cloud/) within a budget of **3000**. See [The Robot](/docs/robot/).
- The robot can use a GPS, a colour sensor, distance sensors, RGB cameras, a LiDAR, a gyroscope and an accelerometer.
- The simulated sensors have realistic noise. Your program must be robust to it, and organizers will not change the noise levels for the competition.

### The battery
The robot has a battery that drains depending on the speed of its motors. The battery level is shown in the control window, above the timers. The rules do not give the exact rate: teams are expected to find out how it behaves by testing.

- To replace the battery, the robot must **stay still on a contact tile for 5 seconds** of simulated time. The battery is then full again.
- In swamps, the battery drains faster.
- If the battery runs out, the game ends.

The [Battery](/docs/programming/battery/) tutorial shows how your program can read the battery level and replace it.
- Robots must be autonomous. Each team has one robot in the field.
- Pre-mapping is prohibited: this covers both the field and the location of wall tokens, including movements predefined from known positions. It results in immediate disqualification from the round.

## Playing a game
- A game lasts **8 minutes of simulated time**. A second timer runs in real time with a limit of **10 minutes**. The game ends when either timer expires.
- A tile counts as visited when the centre of the robot is inside it, as determined by the supervisor.
- The game also ends when the battery runs out, when the robot sends the exit command, or when the team captain calls the end of the game (depending on how the game is executed).
- Competition worlds are revealed just before the games, and programs cannot be changed after the official deadline of each round, as announced by the organizers.

### Lack of progress
A lack of progress (LoP) occurs when:

- The robot has fallen into a hole.
- The robot stays in a fixed location for 20 seconds or more (called automatically).
- The referee determines that the robot is not static, but stuck in a motion sequence.
- The robot calls it autonomously.
- In other cases, the team captain may ask for it, and the referee makes the final decision. This may not apply, depending on how the game is executed.

The robot is then placed back on the last visited checkpoint, or on the starting tile if it never reached one. Its direction cannot be chosen. Erebus also sends the letter `L` to the robot, so that your program can [react to it](/docs/programming/communication/#lack-of-progress).

## Scoring
Scoring is automated by Erebus. Rewards are not duplicated: for example, each checkpoint only scores the first time.

To identify a wall token, the robot must stop for **at least 1 second**, then [send the type and position](/docs/programming/communication/#scoring-wall-tokens) to the supervisor. The centre of the robot must be at most half a tile from the token.

| Item | Points |
|---|---|
| Wall token identification (TI) on a linear tile in Areas 1 to 3 | Smiley victim: 5, cognitive target: 10 |
| Wall token identification (TI) on a floating tile in Areas 1 to 3, and all tokens in Area 4 | Smiley victim: 15, cognitive target: 30 |
| Correct type (TT), in addition to TI | Smiley victim: 10, cognitive target: 20 |
| Checkpoint visited (CN) | 10 |
| Wall token misidentification (TMI) | -5 |
| Lack of progress (LoP) | -5 |

The total score cannot go below zero. A misidentification means reporting a position more than half a tile from the token, reporting a token where there is none, or reporting a smiley victim as a cognitive target or vice versa. Reporting a fake token falls in the second category.

**Area multipliers (AM)**: TI, TT and CN are multiplied by 1, 1.25, 1.5 and 2 in Areas 1, 2, 3 and 4 respectively. TMI and LoP are not multiplied.

**Exit bonus (EB)**: if the robot has identified at least one wall token, returns to the starting tile and sends the exit command, the score is increased by 10%.

**Mapping bonus (MB)**: the robot can submit a map of the maze. The multiplier is correctness × 1.2 + 1, so a perfect map multiplies the score by 2.2. See [Mapping](/docs/rules/mapping/).

The field score of a game is calculated as follows:

![Field score equals the sum over the four areas of TI plus TT plus CN times AM, minus TMI and LoP, all multiplied by EB and MB](./rules_field_score.png)

For example, a run with these results scores 2825.35 points:

![Worked example of a score calculation](./rules_scoring_example.png)

## The competition
How to prepare, the documents you must submit, the competition setup and the final score are in [Preparing for a competition](/docs/competition/).

## Next
Now that you know what your robot has to do, [get your robot](/docs/robot/).
