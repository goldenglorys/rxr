#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from heapq import heappush, heappop
import math


class PathPlannerNode(Node):

    def __init__(self):
        super().__init__("path_planner_node")

        # Use BasicNavigator to get the Global Costmap (Harris code pattern)
        self.basic_navigator = BasicNavigator()

        # Publisher for the calculated path
        self.path_pub = self.create_publisher(Path, "/plan", 10)

        # Subscriber: Listen for Goal Click in RViz
        self.create_subscription(PoseStamped, "/goal_pose", self.goal_callback, 10)

        # Subscriber: Listen for Start Click in RViz (2D Pose Estimate)
        self.create_subscription(
            PoseWithCovarianceStamped, "/initialpose", self.start_callback, 10
        )

        self.current_start = None
        self.get_logger().info(
            "A* Planner Ready. Set '2D Pose Estimate' then '2D Nav Goal' in RViz."
        )

    def start_callback(self, msg):
        # Update start position when user clicks "2D Pose Estimate"
        self.current_start = PoseStamped()
        self.current_start.header = msg.header
        self.current_start.pose = msg.pose.pose
        self.get_logger().info(
            f"Start Pose Updated: ({self.current_start.pose.position.x:.2f}, {self.current_start.pose.position.y:.2f})"
        )

    def goal_callback(self, msg):
        goal_pose = msg

        # If no start set, assume 0,0 or warn user
        if self.current_start is None:
            self.get_logger().warn(
                "No Start Pose! Assuming (0,0). Use '2D Pose Estimate' to set it."
            )
            self.current_start = PoseStamped()
            self.current_start.header = goal_pose.header
            self.current_start.pose.position.x = 0.0
            self.current_start.pose.position.y = 0.0

        time_now = self.get_clock().now().to_msg()

        self.get_logger().info(
            f"Planning from ({self.current_start.pose.position.x:.2f}, {self.current_start.pose.position.y:.2f}) to ({goal_pose.pose.position.x:.2f}, {goal_pose.pose.position.y:.2f})"
        )

        # 1. Access the global costmap using BasicNavigator
        global_costmap = self.basic_navigator.getGlobalCostmap()

        if global_costmap is None:
            self.get_logger().error("Could not get Costmap! Is Nav2 running?")
            return

        # 2. Convert to Grid
        costmap_grid, resolution, origin_x, origin_y = convert_costmap_to_grid(
            global_costmap
        )

        # 3. Run A*
        path = create_a_star_plan(
            self.current_start,
            goal_pose,
            time_now,
            costmap_grid,
            resolution,
            origin_x,
            origin_y,
        )

        # 4. Publish
        if path and len(path.poses) > 0:
            self.path_pub.publish(path)
            self.get_logger().info(f"Path Found! Length: {len(path.poses)} steps.")
            # Update start to be current goal for next movement
            self.current_start = goal_pose
        else:
            self.get_logger().warn("A* Failed to find a path.")


# --- HELPER FUNCTIONS (Same logic as Harris code, just cleaned up) ---


def convert_costmap_to_grid(costmap):
    """Converts nav2_msgs/Costmap to 2D grid"""
    width = costmap.metadata.size_x
    height = costmap.metadata.size_y
    resolution = costmap.metadata.resolution
    origin_x = costmap.metadata.origin.position.x
    origin_y = costmap.metadata.origin.position.y

    flat_data = list(costmap.data)
    grid = []

    # 0 = Free, >0 = Obstacle
    for i in range(height):
        row = flat_data[i * width : (i + 1) * width]
        processed_row = [0 if cell == 0 else 1 for cell in row]
        grid.append(processed_row)

    return grid, resolution, origin_x, origin_y


def create_a_star_plan(start, goal, time_now, costmap, resolution, origin_x, origin_y):

    def heuristic(node, goal_node):
        # Euclidean distance
        return math.sqrt((node[0] - goal_node[0]) ** 2 + (node[1] - goal_node[1]) ** 2)

    def get_neighbors(node, grid):
        # 4-directional movement (Up, Down, Left, Right)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        neighbors = []
        rows = len(grid)
        cols = len(grid[0])

        for dx, dy in directions:
            ny = node[0] + dy
            nx = node[1] + dx
            # Check bounds and collision (0 == free)
            if 0 <= ny < rows and 0 <= nx < cols and grid[ny][nx] == 0:
                neighbors.append((ny, nx))
        return neighbors

    # Convert World Coordinates to Grid Indices
    start_row = int((start.pose.position.y - origin_y) / resolution)
    start_col = int((start.pose.position.x - origin_x) / resolution)
    goal_row = int((goal.pose.position.y - origin_y) / resolution)
    goal_col = int((goal.pose.position.x - origin_x) / resolution)

    start_index = (start_row, start_col)
    goal_index = (goal_row, goal_col)

    # Safety Bounds Check
    rows = len(costmap)
    cols = len(costmap[0])
    if not (0 <= start_row < rows and 0 <= start_col < cols):
        return Path()
    if not (0 <= goal_row < rows and 0 <= goal_col < cols):
        return Path()

    # Collision Check (Start or Goal inside wall)
    if costmap[start_row][start_col] != 0 or costmap[goal_row][goal_col] != 0:
        return Path()

    # A* Core
    open_list = []
    heappush(open_list, (0 + heuristic(start_index, goal_index), start_index))
    came_from = {}
    g_score = {start_index: 0}

    while open_list:
        _, current = heappop(open_list)

        if current == goal_index:
            # Reconstruct Path
            path = Path()
            path.header.frame_id = "map"
            path.header.stamp = time_now

            path_points = [current]
            while current in came_from:
                current = came_from[current]
                path_points.append(current)
            path_points.reverse()

            for r, c in path_points:
                px = c * resolution + origin_x
                py = r * resolution + origin_y
                pose = PoseStamped()
                pose.header = path.header
                pose.pose.position.x = px
                pose.pose.position.y = py
                pose.pose.orientation.w = 1.0
                path.poses.append(pose)
            return path

        for neighbor in get_neighbors(current, costmap):
            tentative_g = g_score[current] + 1
            if neighbor not in g_score or tentative_g < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score = tentative_g + heuristic(neighbor, goal_index)
                heappush(open_list, (f_score, neighbor))

    return Path()


def main(args=None):
    rclpy.init(args=args)
    path_planner_node = PathPlannerNode()
    try:
        rclpy.spin(path_planner_node)
    except KeyboardInterrupt:
        pass
    path_planner_node.destroy_node()
    rclpy.try_shutdown()


if __name__ == "__main__":
    main()
