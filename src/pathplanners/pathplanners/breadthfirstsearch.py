#!/usr/bin/env python3
"""BFS algorithm adapted for Nav2 costmap."""

from collections import deque


def bfs(grid, start, goal):
    """
    Breadth-First Search pathfinding.
    
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
        print(f"BFS: Start {start} out of bounds")
        return []
    if not (0 <= goal[0] < width and 0 <= goal[1] < height):
        print(f"BFS: Goal {goal} out of bounds")
        return []
    if grid[start[1]][start[0]] == 1:
        print(f"BFS: Start {start} is in obstacle")
        return []
    if grid[goal[1]][goal[0]] == 1:
        print(f"BFS: Goal {goal} is in obstacle")
        return []
    
    # BFS setup
    queue = deque([start])
    came_from = {start: None}
    
    # 4-directional movement: right, down, left, up
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    
    while queue:
        current = queue.popleft()
        
        if current == goal:
            # Reconstruct path
            path = []
            while current is not None:
                path.append(current)
                current = came_from[current]
            return path[::-1]
        
        # Explore neighbors
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)
            
            # Check bounds
            if not (0 <= neighbor[0] < width and 0 <= neighbor[1] < height):
                continue
            
            # Check obstacle
            if grid[neighbor[1]][neighbor[0]] == 1:
                continue
            
            # Check visited
            if neighbor in came_from:
                continue
            
            queue.append(neighbor)
            came_from[neighbor] = current
    
    print("BFS: No path found")
    return []


def main(args=None):
    """Standalone main - not used with Nav2."""
    print("BFS algorithm module - use via nav2_planner node")


if __name__ == "__main__":
    main()