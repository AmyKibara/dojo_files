#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Bool, Float64, Int32

class NodeC(Node):
    def __init__(self):
        super().__init__('node_c')

        #--Publishers--(data_type, topic, queue_size)
        self.str_pub = self.create_publisher(String, 'shared_topic', 10)
    
        #Timer for periodic publishing--(period(s), callback fxn)
        self.timer = self.create_timer(1.0, self.periodic_messages)

    #Publishing fxns 
    def periodic_messages(self):
        #Publish string
        str_msg = String()
        str_msg.data = "Hi there hello hi"
        self.str_pub.publish(str_msg)
        

def main(args=None):
    rclpy.init(args=args)
    nodeC = NodeC()
    try:
        rclpy.spin(nodeC)
    except KeyboardInterrupt:
        pass
    finally:
        nodeC.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
