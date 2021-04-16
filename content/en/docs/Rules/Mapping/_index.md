---
title: "Mapping"
linkTitle: "Mapping"
weight: 2
description: >
 More information and examples on mapping
---

## General Idea
Mapping is scored as a multiplier to the overall scores obtained during the run. To obtain a mapping multiplier, the robot must submit a matrix to the game’s main supervisor at the end of the game. Here, the submitted matrix is compared against the “answer key” to produce a correctness score.

## Rules for Mapping
* Each quarter tile and its surrounding edges and vertices will be represented by a cell (value).
* Each element in the world is represented by the following:
    |                                   |                                                    | 
    | :-------------------------------: | :------------------------------------------------: | 
    | Walls                             | 1                                                  | 
    | Holes                             | 2                                                  | 
    | Swamps                            | 3                                                  | 
    | Checkpoints                       | 4                                                  | 
    | Starting tile                     | 5                                                  | 
    | Connection tiles from area 1 to 2 | 6                                                  | 
    | Connection tiles from area 1 to 3 | 7                                                  | 
    | Connection tiles from area 2 to 3 | 8                                                  | 
    | Victims                           | The corresponding victim code. (eg. H,S,U,F,P,C,O) | 
* Any other tiles/edges/vertices should be a '0'.
* For curved walls in area 3, the vertex should be represented by a '0'.
* The presence of a victim should be marked on the cell that represents the corresponding wall. If more than one victim is on a wall, the entry should be concatenated. 
* Maps can be stored in any rotation as long as it is a multiple of 90°
* Ambiguous edge cases will be noted in the example section in this page.
{{< figure src="map-matrix.png" class="center">}}

