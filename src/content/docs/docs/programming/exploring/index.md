---
title: Exploring and mapping
description: Ideas for exploring the maze systematically and building the map.
---

A robot that wanders at random will not score much. This page shows how to go from wandering to exploring systematically. These are ideas to build on, not a complete solution.

## Know where you are
Tiles are 12 cm wide, so the GPS position gives you the tile. The position of the start is different in each world, so measure everything from there:

```python
TILE = 0.12
startX, _, startZ = gps.getValues() # At the start of the game

def currentTile():
    x, _, z = gps.getValues()
    return round((x - startX) / TILE), round((z - startZ) / TILE)
```

:::note
Without a GPS you can estimate the position with the wheel encoders and the gyro, but errors add up.
:::

## Remember what you have seen
Keep a dictionary of tiles, with what you know about each one: which sides have walls, what the floor is, and whether you have visited it.

```python
tiles = {}
tiles[(0, 0)] = {"walls": {"N": False, "E": True, "S": False, "W": True}, "floor": "start", "visited": True}
```

The tiles do not tell the whole story in Areas 2 and 3, where walls can be on quarter tiles. Storing the map at the resolution of quarter tiles, or using a Lidar point cloud, will prepare you for them.

## Decide where to go
Do not just follow a wall: that never reaches [floating tiles](/docs/rules/#linear-and-floating-tiles), whose tokens are worth more. A common approach is:

1. From the current tile, list the neighbours with no wall in between.
2. Go to an unvisited one, if there is one.
3. If not, find the nearest tile with an unvisited neighbour with a breadth-first search, and go there.
4. When no such tile is left, or time runs low, return to the start the same way.

Treat holes as walls. Swamps cost time, and more each time you enter the same one, so visit them only when worthwhile.

## Handle the unexpected
- **Lack of progress:** the robot is moved to the last checkpoint. [Listen for the `L` message](/docs/programming/communication/#lack-of-progress), and update your position.
- **Time:** ask for the time left with [`G`](/docs/programming/communication/#game-information). Leave enough to send the map and return to the start.
- **Noise:** sensors are noisy, so compare several readings before trusting a wall or a token.

## From tiles to the map matrix
The [map matrix](/docs/rules/mapping/) has 4 cells per tile, plus one. For a tile in row `r` and column `c` of your map:

| Element | Matrix position (row, column) |
|---|---|
| Floor marks, such as `4` or `5` | Rows `4r + 1` and `4r + 3`, columns `4c + 1` and `4c + 3` |
| North wall | Row `4r`, columns `4c` to `4c + 4` |
| West wall | Column `4c`, rows `4r` to `4r + 4` |

Your map can start anywhere: Erebus [aligns the matrix](/docs/rules/mapping/#how-correctness-is-calculated) using the starting tile, and it tries the four rotations. The [Mapping rules](/docs/rules/mapping/) explain every value of the matrix. Then [submit it](/docs/programming/map-bonus/).

Test it with the example worlds, whose correct answers are in [Mapping rules](/docs/rules/mapping/#examples). The result appears as `Map Correctness` in the history of the control window.
