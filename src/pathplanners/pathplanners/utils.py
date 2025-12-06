#!/usr/bin/env python3
"""Utility functions for converting between costmap and grid coordinates."""

import numpy as np


def costmap_to_grid(costmap, obstacle_threshold=253):
    """
    Convert Nav2 costmap to binary grid.
    
    Args:
        costmap: Nav2 Costmap2D object
        obstacle_threshold: Cost above which cells are obstacles (default 253)
    
    Returns:
        numpy array: Binary grid (0=free, 1=occupied)
    """
    width = costmap.getSizeInCellsX()
    height = costmap.getSizeInCellsY()
    grid = np.zeros((height, width), dtype=int)
    
    for y in range(height):
        for x in range(width):
            cost = costmap.getCost(x, y)
            if cost >= obstacle_threshold:
                grid[y][x] = 1
    
    return grid


def world_to_grid(world_x, world_y, costmap):
    """
    Convert world coordinates to grid coordinates.
    
    Args:
        world_x: X in world frame
        world_y: Y in world frame
        costmap: Nav2 Costmap2D object
    
    Returns:
        tuple: (grid_x, grid_y)
    """
    origin_x = costmap.getOriginX()
    origin_y = costmap.getOriginY()
    resolution = costmap.getResolution()
    
    grid_x = int((world_x - origin_x) / resolution)
    grid_y = int((world_y - origin_y) / resolution)
    
    return (grid_x, grid_y)


def grid_to_world(grid_x, grid_y, costmap):
    """
    Convert grid coordinates to world coordinates.
    
    Args:
        grid_x: X in grid
        grid_y: Y in grid
        costmap: Nav2 Costmap2D object
    
    Returns:
        tuple: (world_x, world_y)
    """
    origin_x = costmap.getOriginX()
    origin_y = costmap.getOriginY()
    resolution = costmap.getResolution()
    
    world_x = grid_x * resolution + origin_x
    world_y = grid_y * resolution + origin_y
    
    return (world_x, world_y)