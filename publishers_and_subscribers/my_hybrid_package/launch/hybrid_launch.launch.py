from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 1. The Python Publisher
        Node(
            package='my_hybrid_package',
            executable='my_py_pub.py',
            name='python_publisher',
            output='screen'
        ),
        
        # 2. The C++ Subscriber
        Node(
            package='my_hybrid_package',
            executable='my_node_c',
            name='cpp_subscriber',
            output='screen'
        ),
        
        # 3. The Python Subscriber
        Node(
            package='my_hybrid_package',
            executable='my_py_sub.py',
            name='python_subscriber',
            output='screen'
        )
    ])