# A* Path Planner

A C++ implementation of the A* path planning algorithm for 2D grid-based robot navigation.

This project is being developed as part of a larger **2D Autonomous Mobile Robot** project. The objective of the path planner is to generate a collision-free path from the robot's current position to a desired goal while avoiding obstacles represented in a grid map.

## Current Features

- 2D grid-based environment
- 4-directional movement:
  - Up
  - Down
  - Left
  - Right
- Obstacle detection and avoidance
- Manhattan distance heuristic
- Open List and Closed List management
- Cost calculation using:
  - `g` — accumulated path cost
  - `h` — estimated cost to the goal
  - `f = g + h`
- Parent-node tracking
- Path reconstruction from goal to start
- Returns the final path as a sequence of `(x, y)` coordinates
- Returns an empty path when no valid route is found

## A* Cost Function

The planner evaluates nodes using:

```text
f(n) = g(n) + h(n)
```

where:

- `g(n)` is the actual accumulated cost from the start node to the current node.
- `h(n)` is the estimated remaining cost from the current node to the goal.
- `f(n)` is the estimated total path cost.

For the current 4-connected grid, the heuristic is Manhattan distance:

```text
h = |goalX - x| + |goalY - y|
```

Each horizontal or vertical movement has a cost of `1`.

## Map Representation

The environment is represented using a 2D integer vector:

```cpp
std::vector<std::vector<int>> map;
```

Current convention:

```text
0 = Free space
1 = Obstacle
```

The map is accessed using:

```cpp
map[y][x]
```

## Planner Input

The planner currently receives:

```text
Start position: (startX, startY)
Goal position:  (goalX, goalY)
2D grid map
```

## Planner Output

`findPath()` returns:

```cpp
std::vector<std::vector<int>>
```

representing an ordered sequence of grid coordinates:

```text
Start → ... → Goal
```

For example:

```text
(0,0)
(1,0)
(2,0)
(3,0)
...
(4,4)
```

If no valid route exists, the planner returns an empty vector.

## Project Structure

```text
AStarPathPlanner/
│
├── AStarPlanner.h
├── AStarPlanner.cpp
├── main.cpp
└── README.md
```

### `AStarPlanner.h`

Defines the `AStarPlanner` class, node representation, direction representation, and planner interface.

### `AStarPlanner.cpp`

Contains the A* search algorithm, heuristic calculation, neighbor evaluation, Open/Closed List handling, and path reconstruction.

### `main.cpp`

Used to create a test grid, initialize the planner, execute A*, and display the generated path.

## Role in the Autonomous Robot

The A* planner will eventually form one component of a larger autonomous navigation system:

```text
Localization
     ↓
Current Robot Pose
     ↓
Map + Goal
     ↓
A* Path Planner
     ↓
Collision-Free Path
     ↓
Motion Controller
     ↓
Left / Right Wheel Commands
```

The overall robot is planned as a differential-drive mobile robot.

## Development Status

**Work in progress.**

The initial A* implementation is complete at the algorithm level and is currently being tested and validated.

Planned improvements include:

- Additional test scenarios
- Input and map validation
- Improved data structures and search efficiency
- Visualization of the generated path
- Integration with the larger robot navigation architecture
- Integration with localization and motion control
- Extension toward more realistic robot navigation constraints

## Purpose

This project is being built primarily to develop a deeper understanding of autonomous robot navigation, including path planning, coordinate systems, localization, motion control, and eventually complete autonomous navigation.
