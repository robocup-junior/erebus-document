---
title: What's new in v26
description: The changes in Erebus v26 and the 2026 rules that affect your robot.
---

Erebus v26 implements the 2026 rules. If you are coming from an earlier version, these are the changes that affect your robot.

| Topic | Until 2025 | From 2026 |
|---|---|---|
| Letter victims | Letters H, S, U | Symbols Φ (harmed), Ψ (stable), Ω (unharmed). They are still reported as `H`, `S`, `U`. |
| Hazmat signs | Four hazmat labels | Replaced by [cognitive targets](/docs/rules/#cognitive-targets): concentric coloured rings whose values add up to the type. They are still reported as `F`, `P`, `C`, `O`. |
| Fake tokens | - | New: [fake victims](/docs/rules/#fake-victims) with three-dimensional letters, and cognitive targets whose sum is not 0 to 3. Do not report or map them. |
| Swamps | Time consumed 5x faster | The first entry into a swamp is x5, and each new entry into the same swamp adds 1, up to x10. |
| Obstacles on the map | Not mapped | Tiles with an obstacle are mapped as `x`. |
| Mapping bonus | Up to x2 | The multiplier is now correctness × 1.2 + 1. |
| Sensor noise | - | The GPS has noise. Organizers will not change the noise levels for the competition. |
| Game execution | Announced per event | Server-client setup: your controller runs on your own computer, connected to the game server by Ethernet. See [Remote Controller](/docs/competition/remote-controller/). |
| Documents | TDP, Poster, Video | In addition, a short video showing how you run your controller in the server-client setup. |
| Missed games | -50 points | 0 points. |

The Webots version has not changed: Erebus v26 still runs on Webots **R2023b**.

The two versions released after v26.0.0 do not change the rules. v26.0.1 adds example worlds with fake victims and a script that turns victims of an existing world into fakes, and v26.1 fixes how obstacles are marked in Area 4.

## Updating your program

1. Update your victim detection to the new symbols. The letters you report do not change.
2. Replace hazmat detection with [cognitive target reading](/docs/programming/wall-tokens/#reading-a-cognitive-target).
3. Make sure your program does not report fakes, and leaves them out of the map.
4. Add obstacles to your map, as `x`.
5. Plan your route with the new swamps in mind: each time the robot enters the same swamp, it costs more time.
6. Practice the [server-client setup](/docs/competition/remote-controller/).
