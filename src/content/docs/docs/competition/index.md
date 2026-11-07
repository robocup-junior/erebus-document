---
title: Preparing for a competition
description: A checklist to get ready for a RoboCupJunior Rescue Simulation competition.
---

This page is a guide for the international competition under the 2026 rules. Local and regional competitions may differ, so check with your organizer. The official [rules](/docs/rules/) always apply.

## Timeline

| When | What |
|---|---|
| Throughout the year | Follow the [event page](/docs/events/upcoming-events/) and the [forum](https://junior.forum.robocup.org/), where clarifications are posted |
| At least 4 weeks before | Organizers give instructions for the web form to prepare the interviews |
| 3 weeks before the first day | Deadline for the documents |
| Setup day | Be at the venue early for registration, interviews and the team meetings |
| Each round | Worlds are revealed just before the games. Programs cannot change after each round's deadline. |
| After the scoring runs | Technical Challenge |

## Documents to submit
Templates and rubrics are on the [RCJ Rescue Community Website](https://rescue.rcj.cloud/).

- [ ] **Technical Description Paper (TDP).** Follow the template strictly: otherwise, the score for the document is 0.
- [ ] **Poster,** as a file and as a physical poster at the venue, no larger than A1.
- [ ] **Video** showcasing your project.
- [ ] **Server-client video,** new in 2026: a short video showing how you run your controller on an example map in the server-client setup.
- [ ] **Source code** and the **web form** for the interviews.

## Competition setup
Games run in a server-client setup: organizers run the game server and provide one RJ-45 socket, and your program runs on your computer. See [Remote Controller](/docs/competition/remote-controller/).

Bring:

- [ ] A computer with your program and all its libraries installed, and Webots R2023b
- [ ] An Ethernet cable, and an adapter if your computer needs one
- [ ] Your robot's `.json` file, if you have a custom robot
- [ ] The physical poster

## OpenGL settings
Unless organizers announce otherwise, the following settings are used. They affect what the cameras see, so test with them. You can find them in the OpenGL tab of the Webots preferences.

| Setting | Value |
|---|---|
| Ambient Occlusion | Low |
| Texture Quality | Low |
| Max Texture Filtering | 4 |
| Shadows | Disabled |
| Anti-aliasing | Disabled |

## Testing your robot
- [ ] Run on every included world, especially `world3.wbt` and `world4.wbt`, which include fakes.
- [ ] Make your own maps with the [World Editor](/docs/tools/world-editor/), including all four areas.
- [ ] Check the whole game: does it run to the end, submit the map and return to the start in time?
- [ ] Test what happens after a lack of progress.
- [ ] Test on the computer you will bring, and with the OpenGL settings above.

## During the competition
- Only the captain and co-captain may access the competition area, unless a referee says otherwise.
- The referee operates the simulation. You cannot touch game equipment after the game starts.
- Mentors cannot help during the competition.
- Be ready to explain your work: each team member should have a technical role and know how it works.

## Final score
The final score at international competitions combines:

| Part | Weight | Contents |
|---|---|---|
| Field score | 0.6 | Mean of the normalized field scores. The worst round or rounds are omitted. |
| Rubrics | 0.2 | TDP (0.6), Video (0.2), Poster (0.2) |
| Technical Challenge | 0.2 | Mini-tasks announced at the competition, solved by reprogramming your robot in limited time |

Ties are resolved based on the mean of the normalized field scores. The SuperTeam Challenge is a separate event with its own award.
