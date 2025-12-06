from setuptools import find_packages
from setuptools import setup

setup(
    name='create_plan_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('create_plan_msgs', 'create_plan_msgs.*')),
)
