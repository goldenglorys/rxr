#!/usr/bin/env python3
"""Dijkstra's algorithm adapted for Nav2 costmap."""

import heapq


def dijkstra(grid, start, goal):
    """
    Dijkstra's shortest path algorithm.
    
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
        print(f"Dijkstra: Start {start} out of bounds")
        return []
    if not (0 <= goal[0] < width and 0 <= goal[1] < height):
        print(f"Dijkstra: Goal {goal} out of bounds")
        return []
    if grid[start[1]][start[0]] == 1:
        print(f"Dijkstra: Start {start} is in obstacle")
        return []
    if grid[goal[1]][goal[0]] == 1:
        print(f"Dijkstra: Goal {goal} is in obstacle")
        return []
    
    # Priority queue: (cost, node)
    open_set = []
    heapq.heappush(open_set, (0, start))
    
    came_from = {}
    cost_so_far = {start: 0}
    
    # 4-directional movement
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    
    while open_set:
        current_cost, current = heapq.heappop(open_set)
        
        if current == goal:
            # Reconstruct path
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]
        
        # Skip if found better path
        if current_cost > cost_so_far.get(current, float('inf')):
            continue
        
        # Explore neighbors
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)
            
            if not (0 <= neighbor[0] < width and 0 <= neighbor[1] < height):
                continue
            
            if grid[neighbor[1]][neighbor[0]] == 1:
                continue
            
            new_cost = cost_so_far[current] + 1
            
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                came_from[neighbor] = current
                heapq.heappush(open_set, (new_cost, neighbor))
    
    print("Dijkstra: No path found")
    return []


def main(args=None):
    """Standalone main - not used with Nav2."""
    print("Dijkstra algorithm module - use via nav2_planner node")


if __name__ == "__main__":
    main()