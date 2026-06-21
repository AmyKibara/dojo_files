#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class NodeD(Node):
    def __init__(self):
        super().__init__('node_d')

        #--Subscribers--(data_type, topic, callback fxn, queue_size)
        self.str_sub = self.create_subscription(String, 'shared_topic', self.str_call, 10)
    
    #Subscriber fxns
    def str_call(self, msg):
        self.get_logger().info(f"Received string: {msg.data}")

def main(args=None):
    rclpy.init(args=args)
    nodeD = NodeD()
    try:
        rclpy.spin(nodeD)
    except KeyboardInterrupt:
        pass
    finally:
        nodeD.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
