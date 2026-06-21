#Very basic launch file
from launch import LaunchDescription
from launch_ros.actions import Node

##if launch file brings up more than one nodes, then more than one Node object created and insluded in the return LaunchDescription
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_cpp_package',
            executable='my_node_b',
            name='node_b',
            output='screen'
        )
    ])