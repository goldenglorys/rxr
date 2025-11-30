import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import OccupancyGrid, Path
from geometry_msgs.msg import PoseStamped, Point
from rclpy.qos import QoSProfile, DurabilityPolicy, ReliabilityPolicy
import math
import heapq

class PathPlanner(Node):

    def __init__(self):
        super().__init__('path_planner_server')
        
        # 1. Action Server: This replaces the standard bt_navigator for this assignment
        self._action_server = ActionServer(
            self,
            NavigateToPose,
            '/navigate_to_pose',
            self.execute_callback)

        # 2. Costmap Subscriber: To see obstacles
        qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL, reliability=ReliabilityPolicy.RELIABLE)
        self.subscription = self.create_subscription(
            OccupancyGrid,
            '/global_costmap/costmap',
            self.costmap_callback,
            qos)
        
        # 3. Path Publisher: To visualize in RViz
        self.path_publisher = self.create_publisher(Path, '/plan', 10)
        
        self.costmap = None
        self.width = 0
        self.height = 0
        self.resolution = 0.0
        self.origin_x = 0.0
        self.origin_y = 0.0

        self.get_logger().info('Path Planner Server (A*) Started')

    def costmap_callback(self, msg):
        self.costmap = msg.data
        self.width = msg.info.width
        self.height = msg.info.height
        self.resolution = msg.info.resolution
        self.origin_x = msg.info.origin.position.x
        self.origin_y = msg.info.origin.position.y
        self.get_logger().info('Costmap received!')

    def world_to_grid(self, wx, wy):
        if self.resolution == 0: return 0, 0
        gx = int((wx - self.origin_x) / self.resolution)
        gy = int((wy - self.origin_y) / self.resolution)
        return gx, gy

    def grid_to_world(self, gx, gy):
        wx = (gx * self.resolution) + self.origin_x + (self.resolution / 2)
        wy = (gy * self.resolution) + self.origin_y + (self.resolution / 2)
        return wx, wy

    def is_valid(self, gx, gy):
        # Check bounds
        if gx < 0 or gx >= self.width or gy < 0 or gy >= self.height:
            return False
        
        # Check collision (Costmap values: 0=Free, 100=Lethal, -1=Unknown)
        index = gy * self.width + gx
        # Treat unknown (-1) and obstacles (>50) as invalid
        val = self.costmap[index]
        if val != 0 and val != -1: # Strict check: only 0 is definitely free
             if val > 50: 
                 return False
        return True

    def heuristic(self, a, b):
        # Euclidean distance
        return math.sqrt((b[0] - a[0])**2 + (b[1] - a[1])**2)

    def a_star_search(self, start_world, goal_world):
        start_grid = self.world_to_grid(start_world[0], start_world[1])
        goal_grid = self.world_to_grid(goal_world[0], goal_world[1])

        if not self.is_valid(goal_grid[0], goal_grid[1]):
            self.get_logger().warn('Goal is inside an obstacle!')
            return []

        # Priority Queue: (Cost, (x, y))
        frontier = []
        heapq.heappush(frontier, (0, start_grid))
        
        came_from = {}
        cost_so_far = {}
        
        came_from[start_grid] = None
        cost_so_far[start_grid] = 0

        current = None

        while frontier:
            _, current = heapq.heappop(frontier)

            # Check if we reached the goal (or very close to it)
            if current == goal_grid:
                break

            # Check 8 neighbors (diagonal movement allowed)
            neighbors = [
                (0, 1), (0, -1), (1, 0), (-1, 0), 
                (1, 1), (1, -1), (-1, 1), (-1, -1)
            ]

            for dx, dy in neighbors:
                next_node = (current[0] + dx, current[1] + dy)

                if self.is_valid(next_node[0], next_node[1]):
                    # Cost is 1.0 for straight, 1.414 for diagonal
                    move_cost = 1.414 if (dx != 0 and dy != 0) else 1.0
                    new_cost = cost_so_far[current] + move_cost
                    
                    if next_node not in cost_so_far or new_cost < cost_so_far[next_node]:
                        cost_so_far[next_node] = new_cost
                        priority = new_cost + self.heuristic(next_node, goal_grid)
                        heapq.heappush(frontier, (priority, next_node))
                        came_from[next_node] = current

        # Reconstruct path
        path = []
        if current != goal_grid:
            self.get_logger().warn('A* failed to find a path')
            return []

        while current is not None:
            wx, wy = self.grid_to_world(current[0], current[1])
            path.append((wx, wy))
            current = came_from[current]
        
        path.reverse()
        return path

    def execute_callback(self, goal_handle):
        self.get_logger().info('Calculating path...')

        if self.costmap is None:
            self.get_logger().error('Costmap not received yet')
            goal_handle.abort()
            return NavigateToPose.Result()

            # For simplicity, assume start is robot's current position at (0,0)
        start_pos = (0.0, 0.0) 
        
        goal_msg = goal_handle.request.pose.pose.position
        goal_pos = (goal_msg.x, goal_msg.y)

        # Run A*
        path_points = self.a_star_search(start_pos, goal_pos)

        if not path_points:
            goal_handle.abort()
            return NavigateToPose.Result()

        # Publish Path for RViz
        path_msg = Path()
        path_msg.header.frame_id = 'map'
        path_msg.header.stamp = self.get_clock().now().to_msg()
        
        for p in path_points:
            pose = PoseStamped()
            pose.pose.position.x = p[0]
            pose.pose.position.y = p[1]
            path_msg.poses.append(pose)
        
        self.path_publisher.publish(path_msg)

        self.get_logger().info(f'Path found with {len(path_points)} points')
        goal_handle.succeed()
        
        return NavigateToPose.Result()

def main(args=None):
    rclpy.init(args=args)
    path_planner = PathPlanner()
    rclpy.spin(path_planner)
    path_planner.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()