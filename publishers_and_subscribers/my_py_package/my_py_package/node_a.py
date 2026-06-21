import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Bool, Float64, Int32

class NodeA(Node):
    def __init__(self):
        super().__init__('node_a')

        #--Publishers--(data_type, topic, queue_size)
        self.str_pub = self.create_publisher(String, 'str_topic', 10)
        self.bool_pub = self.create_publisher(Bool, 'bool_topic', 10)
        self.float_pub = self.create_publisher(Float64, 'float_topic', 10)
        self.int_pub = self.create_publisher(Int32, 'int_topic', 10)

        #Timer for periodic publishing--(period(s), callback fxn)
        self.timer = self.create_timer(1.0, self.periodic_messages)

        #--Subscribers--(data_type, topic, callback fxn, queue_size)
        self.str_sub = self.create_subscription(String, 'str_topic', self.str_call, 10)
        self.bool_sub = self.create_subscription(Bool, 'bool_topic', self.bool_call, 10)
        self.float_sub = self.create_subscription(Float64, 'float_topic', self.float_call, 10)
        self.int_sub = self.create_subscription(Int32, 'int_topic', self.int_call, 10)

    #Publishing fxns 
    def periodic_messages(self):
        #Publish string
        str_msg = String()
        str_msg.data = "Hi there hello hi"
        self.str_pub.publish(str_msg)
        #Publish bool
        bool_msg = Bool()
        bool_msg.data = False
        self.bool_pub.publish(bool_msg)
        #Publish float
        float_msg = Float64()
        float_msg.data = 3.14159
        self.float_pub.publish(float_msg)
        #Publish string
        int_msg = Int32()
        int_msg.data = 67
        self.int_pub.publish(int_msg)
    
    #Subscriber fxns
    def str_call(self, msg):
        self.get_logger().info(f"Received string: {msg.data}")
    def bool_call(self, msg):
        self.get_logger().info(f"Received bool: {msg.data}")
    def float_call(self, msg):
        self.get_logger().info(f"Received float: {msg.data}")
    def int_call(self, msg):
        self.get_logger().info(f"Received int: {msg.data}")


def main(args=None):
    rclpy.init(args=args)
    nodeA = NodeA()
    try:
        rclpy.spin(nodeA)
    except KeyboardInterrupt:
        pass
    finally:
        nodeA.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
