#!/usr/bin/env python3
"""A* algorithm for Nav2 costmap."""

import heapq


def heuristic(a, b):
    """Manhattan distance heuristic."""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


def astar(grid, start, goal):
    """
    A* pathfinding algorithm.

    Args:
        grid: 2D numpy array (0=free, 1=occupied)
        start: tuple (x, y) start position
        goal: tuple (x, y) goal position

    Returns:
        list: Path as [(x, y), ...] or empty list if no path
    """
    height, width = grid.shape

    # Validate inputs
    if not (0 <= start[0] < width and 0 <= start[1] < height):
        print(f"A*: Start {start} out of bounds")
        return []
    if not (0 <= goal[0] < width and 0 <= goal[1] < height):
        print(f"A*: Goal {goal} out of bounds")
        return []
    if grid[start[1]][start[0]] == 1:
        print(f"A*: Start {start} is in obstacle")
        return []
    if grid[goal[1]][goal[0]] == 1:
        print(f"A*: Goal {goal} is in obstacle")
        return []

    # Priority queue: (f_score, node)
    open_set = []
    heapq.heappush(open_set, (0, start))

    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}

    # 4-directional movement
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    while open_set:
        _, current = heapq.heappop(open_set)

        if current == goal:
            # Reconstruct path
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        # Explore neighbors
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)

            if not (0 <= neighbor[0] < width and 0 <= neighbor[1] < height):
                continue

            if grid[neighbor[1]][neighbor[0]] == 1:
                continue

            tentative_g_score = g_score[current] + 1

            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = tentative_g_score + heuristic(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))

    print("A*: No path found")
    return []


def main(args=None):
    """Standalone main - not used with Nav2."""
    print("A* algorithm module - use via nav2_planner node")


if __name__ == "__main__":
    main()
