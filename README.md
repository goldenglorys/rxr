# Path Planning Algorithms for Andino Robot

Integrated path planning algorithms (BFS, Dijkstra, A*) with ROS 2 Nav2 for autonomous navigation of the Andino differential drive robot.

[![ROS 2 Humble](https://img.shields.io/badge/ROS_2-Humble-blue)](https://docs.ros.org/en/humble/)
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![Python 3.10](https://img.shields.io/badge/python-3.10-blue.svg)](https://www.python.org/downloads/release/python-3100/)

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Algorithms](#algorithms)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Algorithm Comparison](#algorithm-comparison)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

---

## Overview

This project implements three classical path planning algos. integrated with the ROS 2 Navigation Stack (Nav2) for the Andino robot.

---

## Features

- **Multiple Algorithms:** BFS, Dijkstra, and A* pathfinding implementations
- **Nav2 Integration:** Custom planner plugin with seamless Nav2 compatibility
- **Real-time Obstacle Avoidance:** Uses global costmap for collision-free planning
- **Runtime Algorithm Selection:** Switch algorithms via ROS 2 parameters
- **Modular Architecture:** Easy to extend with new algorithms

---

## System Srch

```
┌─────────────────┐
│   User (RViz)   │ ← 2D Pose Estimate / Nav2 Goal
└────────┬────────┘
         │
         ↓
┌─────────────────┐
│ Nav2 Planner    │
│    Server       │
└────────┬────────┘
         │
         ↓
┌─────────────────┐
│  C++ Custom     │ ← Calls CreatePlan service
│  Nav2 Plugin    │
└────────┬────────┘
         │
         ↓
┌─────────────────┐
│  Python Planner │ ← Runs selected algorithm
│      Node        │    (A*, Dijkstra, BFS)
└────────┬────────┘
         │
         ↓
┌─────────────────┐
│   Path Result   │ → Returns to Nav2 Controller
└─────────────────┘
```

**Communication:** Service-based architecture decouples C++ plugin from Python algorithms.

---

## Algorithms

### Breadth-First Search (BFS)

- **Type:** Uninformed search
- **Optimality:** Unweighted shortest path
- **Complexity:** O(V + E)
- **Best for:** Simple environments, educational purposes

### Dijkstra's Algorithm

- **Type:** Weighted shortest path
- **Optimality:** Guaranteed optimal
- **Complexity:** O((V + E) log V)
- **Best for:** When optimality is critical, uniform costs

### A* (A-Star)

- **Type:** Informed search with heuristic
- **Optimality:** Optimal (with admissible heuristic)
- **Complexity:** O(b^d)
- **Heuristic:** Manhattan distance (4-directional movement)
- **Best for:** Production use - fast and optimal

**Performance Comparison:**

| Algorithm | Path Quality | Speed | Memory |
|-----------|--------------|-------|--------|
| BFS | Good | Fast | High |
| Dijkstra | Optimal | Slow | High |
| A* | Optimal | **Fastest** | Medium |

---

## Installation

### Prerequisites

- **OS:** Ubuntu 22.04 LTS
- **ROS 2:** Humble
- **Python:** 3.10+
- **Additional:**
  - Nav2 Navigation Stack
  - Andino simulation packages
  - Gazebo

### Install ROS 2 and Dependencies

```bash
# Install ROS 2 Humble
sudo apt update
sudo apt install ros-humble-desktop -y

# Install Andino packages
sudo apt install ros-humble-andino-gz -y

# Install Nav2
sudo apt install ros-humble-navigation2 -y
sudo apt install ros-humble-nav2-simple-commander -y

# Install additional tools
sudo apt install python3-pip -y
pip3 install numpy transforms3d
```

### Build the Project

```bash
# Create workspace
mkdir -p ~/exercises_ws/src
cd ~/exercises_ws/src

# Clone repository
git clone https://github.com/goldenglorys/rxr.git

# Build packages
cd ~/exercises_ws
colcon build --symlink-install

# Source workspace
source install/setup.bash
```

### Verify Installation

```bash
# Check packages
ros2 pkg list | grep -E "create_plan|custom_nav2|pathplanners"

# Expected output:
# create_plan_msgs
# custom_nav2_planner
# pathplanners
```

---

## Usage

### Quick Start

**Terminal 1 - Launch Simulation:**

```bash
source ~/exercises_ws/install/setup.bash
ros2 launch andino_gz andino_gz.launch.py nav2:=True
```

**Terminal 2 - Run Path Planner:**

```bash
source ~/exercises_ws/install/setup.bash
ros2 run pathplanners path_planner_node \
  --ros-args \
  -p use_sim_time:=True \
  -p algorithm:=astar
```

### RViz Configuration

1. **Set Fixed Frame:** Change to `map` (top-left panel)
2. **Add Map Display:**
   - Click "Add" → "Map"
   - Topic: `/map`
3. **Add Path Display:**
   - Click "Add" → "Path"
   - Topic: `/plan`
   - Color: Green or Red (for visibility)
4. **Set Initial Pose:**
   - Click "2D Pose Estimate" toolbar button
   - Click on map where robot is located
5. **Send Navigation Goal:**
   - Click "Nav2 Goal" toolbar button
   - Click destination on map
   - Robot will plan and execute path!

### Algorithm Selection

**A(star) Algorithm :**

```bash
ros2 run pathplanners path_planner_node \
  --ros-args -p use_sim_time:=True -p algorithm:=astar
```

**Dijkstra Algorithm :**

```bash
ros2 run pathplanners path_planner_node \
  --ros-args -p use_sim_time:=True -p algorithm:=dijkstra
```

**BFS Algorithm :**

```bash
ros2 run pathplanners path_planner_node \
  --ros-args -p use_sim_time:=True -p algorithm:=bfs
```

---

## Project Structure

```
rxr/
├── src/
│   ├── packages/
│   │   ├── create_plan_msgs/              # Custom service definition
│   │   │   ├── srv/
│   │   │   │   └── CreatePlan.srv         # Start + Goal → Path
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   │
│   │   └── custom_nav2_planner/           # C++ Nav2 plugin
│   │       ├── src/
│   │       │   └── custom_nav2_planner.cpp
│   │       ├── include/
│   │       │   └── custom_nav2_planner/
│   │       │       └── custom_nav2_planner.hpp
│   │       ├── global_planner_plugin.xml  # Plugin description
│   │       ├── CMakeLists.txt
│   │       └── package.xml
│   │
│   └── pathplanners/                       # Main Python package
│       ├── pathplanners/
│       │   ├── nav2_planner.py            # Service server + main node
│       │   ├── astar.py                   # A* implementation
│       │   ├── dijkstra.py                # Dijkstra implementation
│       │   ├── breadthfirstsearch.py      # BFS implementation
│       │   ├── utils.py                   # Coordinate conversions
│       │   └── __init__.py
│       ├── launch/
│       │   └── bringup.launch.py          # Launch file
│       ├── test/                          # Unit tests
│       │   ├── test_copyright.py
│       │   ├── test_flake8.py
│       │   └── test_pep257.py
│       ├── package.xml
│       ├── setup.py
│       ├── setup.cfg
│       └── README.md
│
├── build/                                  # Build artifacts
├── install/                                # Installed packages
├── log/                                    # Build logs
```

---

## Development

### Adding New Algorithms

1. Create new file in `pathplanners/` (e.g., `rrt_star.py`)
2. Implement function with signature:

   ```python
   def rrt_star(grid, start, goal):
       """Your algorithm here"""
       return path_coords  # List of (x, y) tuples
   ```

3. Import in `nav2_planner.py`:

   ```python
   from pathplanners.rrt_star import rrt_star
   ```

4. Add to algorithm selection:

   ```python
   elif self.algorithm == 'rrt_star':
       path_coords = rrt_star(grid, start_grid, goal_grid)
   ```

5. Update `setup.py` if needed

<!-- --- -->

<!-- <div align="center">

**⭐ Star this repository if you find it helpful! ⭐**

[![GitHub stars](https://img.shields.io/github/stars/goldenglorys/rxr?style=social)](https://github.com/goldenglorys/rxr/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/goldenglorys/rxr?style=social)](https://github.com/goldenglorys/rxr/network/members)

</div> -->
