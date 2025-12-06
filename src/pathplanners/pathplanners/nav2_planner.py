#!/usr/bin/env python3
"""Nav2 path planner node integrating BFS, Dijkstra, and A*."""

import rclpy
from rclpy.node import Node

from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped
from create_plan_msgs.srv import CreatePlan
from nav2_simple_commander.robot_navigator import BasicNavigator

# Import algorithms
from pathplanners.breadthfirstsearch import bfs
from pathplanners.dijkstra import dijkstra
from pathplanners.astar import astar
from pathplanners.utils import (
    costmap_to_grid,
    world_to_grid,
    grid_to_world
)


class Nav2PathPlanner(Node):
    """Path planner node for Nav2 with multiple algorithms."""

    def __init__(self):
        super().__init__("nav2_path_planner")
        
        # Declare algorithm parameter
        self.declare_parameter('algorithm', 'astar')
        self.algorithm = self.get_parameter('algorithm').value
        
        self.get_logger().info(f"🤖 Nav2 Path Planner initialized")
        self.get_logger().info(f"📊 Algorithm: {self.algorithm.upper()}")
        
        # Initialize Nav2 navigator for costmap access
        self.basic_navigator = BasicNavigator()
        
        # Create planning service
        self.srv = self.create_service(
            CreatePlan,
            'create_plan',
            self.create_plan_callback
        )
        
        self.get_logger().info("✅ Service 'create_plan' ready")

    def create_plan_callback(self, request, response):
        """
        Service callback to create path plan.
        
        Args:
            request: CreatePlan.Request with start and goal poses
            response: CreatePlan.Response to populate with path
        
        Returns:
            CreatePlan.Response with computed path
        """
        goal_pose = request.goal
        start_pose = request.start
        time_now = self.get_clock().now().to_msg()
        
        self.get_logger().info("=" * 60)
        self.get_logger().info(f"🎯 Planning with: {self.algorithm.upper()}")
        self.get_logger().info(
            f"📍 Start: ({start_pose.pose.position.x:.2f}, "
            f"{start_pose.pose.position.y:.2f})"
        )
        self.get_logger().info(
            f"🏁 Goal: ({goal_pose.pose.position.x:.2f}, "
            f"{goal_pose.pose.position.y:.2f})"
        )
        
        # Get global costmap
        try:
            global_costmap = self.basic_navigator.getGlobalCostmap()
        except Exception as e:
            self.get_logger().error(f"❌ Failed to get costmap: {e}")
            response.path = self._empty_path(goal_pose, time_now)
            return response
        
        # Create path
        response.path = self.compute_path(
            start_pose,
            goal_pose,
            time_now,
            global_costmap
        )
        
        path_length = len(response.path.poses)
        self.get_logger().info(f"✨ Path generated: {path_length} waypoints")
        self.get_logger().info("=" * 60)
        
        return response

    def compute_path(self, start, goal, time_now, costmap):
        """
        Compute path using selected algorithm.
        
        Args:
            start: PoseStamped start pose
            goal: PoseStamped goal pose
            time_now: Current timestamp
            costmap: Nav2 Costmap2D
        
        Returns:
            Path message
        """
        path = Path()
        path.header.frame_id = goal.header.frame_id
        path.header.stamp = time_now
        
        # Convert costmap to grid
        grid = costmap_to_grid(costmap)
        
        # Convert poses to grid coordinates
        start_grid = world_to_grid(
            start.pose.position.x,
            start.pose.position.y,
            costmap
        )
        goal_grid = world_to_grid(
            goal.pose.position.x,
            goal.pose.position.y,
            costmap
        )
        
        self.get_logger().info(
            f"🗺️  Grid: Start{start_grid} → Goal{goal_grid}"
        )
        
        # Run selected algorithm
        path_coords = []
        if self.algorithm == 'astar':
            path_coords = astar(grid, start_grid, goal_grid)
        elif self.algorithm == 'dijkstra':
            path_coords = dijkstra(grid, start_grid, goal_grid)
        elif self.algorithm == 'bfs':
            path_coords = bfs(grid, start_grid, goal_grid)
        else:
            self.get_logger().error(f"❌ Unknown algorithm: {self.algorithm}")
            return path
        
        if not path_coords:
            self.get_logger().warn("⚠️  No path found!")
            return path
        
        # Convert grid path to world coordinates
        for grid_point in path_coords:
            pose = PoseStamped()
            world_point = grid_to_world(grid_point[0], grid_point[1], costmap)
            
            pose.pose.position.x = world_point[0]
            pose.pose.position.y = world_point[1]
            pose.pose.position.z = 0.0
            pose.header.stamp = time_now
            pose.header.frame_id = goal.header.frame_id
            
            path.poses.append(pose)
        
        return path

    def _empty_path(self, goal_pose, time_now):
        """Create empty path message."""
        path = Path()
        path.header.frame_id = goal_pose.header.frame_id
        path.header.stamp = time_now
        return path


def main(args=None):
    """Main function."""
    rclpy.init(args=args)
    
    nav2_path_planner = Nav2PathPlanner()
    
    try:
        rclpy.spin(nav2_path_planner)
    except KeyboardInterrupt:
        pass
    
    nav2_path_planner.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()