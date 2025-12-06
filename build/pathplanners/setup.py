from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'pathplanners'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name, 'rviz'), ['rviz/visualizer.rviz']),
        
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='goldenglorys',
    maintainer_email='olusolagloryolamide@gmail.com',
    description='Path planning algorithms for Andino robot',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "map_node = pathplanners.map:main",
            "bfs = pathplanners.breadthfirstsearch:main",
            "dijkstra = pathplanners.dijkstra:main",
            "path_planner_node = pathplanners.nav2_planner:main"
        ],
    },
)
