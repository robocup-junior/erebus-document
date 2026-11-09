---
title: What's new in v27
description: The changes in Erebus v27 and the 2027 rules that affect your robot.
---

Erebus v27 implements the 2027 rules. If you are coming from v26, these are the changes that affect your robot.

| Topic | Until 2026 | From 2027 |
|---|---|---|
| Battery | - | New: the robot has a [battery](/docs/rules/#the-battery) that drains with the speed of its motors. If it runs out, the game ends. |
| Contact tiles | - | New: cyan [contact tiles](/docs/rules/#contact-tiles). Staying still on one for 5 seconds replaces the battery. They are mapped as `k`. |
| Swamps | Game time runs faster: x5 on the first entry, up to x10 | The battery drains faster. The game time is not affected. |
| Victims | Symbols Φ, Ψ, Ω | [Smiley faces](/docs/rules/#smiley-victims): sad (harmed), neutral (stable) and happy (unharmed). They are still reported as `H`, `S`, `U`. |
| Fake victims | Three-dimensional symbols | Three-dimensional smiley faces |
| Game information | The `G` reply is 16 bytes | The `G` reply is 20 bytes, and ends with the battery level. See [Game information](/docs/programming/communication/#game-information). |
| Reporting distance | Erebus v26 accepted reports up to 9 cm from the token | Half a tile (6 cm), as the rules say |
| Areas | Four areas, Area 4 optional | Up to four areas: Area 1 is always there, and organizers may leave out Areas 2 to 4 |
| Webots | R2023b | **R2025a** |
| Python | 3.9 or later | 3.10 or later |

[Your first run](/docs/getting-started/) shows how to use the control window of Erebus v27.

## Updating your program

1. Read the `G` reply as 20 bytes. A program that only accepts 16 bytes no longer receives the game information.
1. Watch the battery level, and plan your route so that the robot reaches a contact tile before the battery runs out. See [Battery](/docs/programming/battery/).
1. Add contact tiles to your map, as `k`.
1. Update your victim detection to the smiley faces. The letters you report do not change.
1. Report tokens from closer: the centre of the robot, and the position you send, must be within half a tile of the token.
1. Swamps now cost battery instead of time, so take them into account in your battery plan.
1. Install Webots R2025a and Python 3.10 or later, and check that your program still works. See [Installation](/docs/installation/).
