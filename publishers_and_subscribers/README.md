# NODES
Contains publisher and subscriber nodes made via ros2

## Callback fxns
These are fuctions uyou write but never explicitly call, theyre called by another system(like ros2 executor) and are entirely event driven. Subscriber callbacks run when a new message is received, timer callbacks publish something periodically 

## Message types
- Good practice to have a publisher have one type of message when the data streams are independent and don't rely on exact timing with one another.
- If required to have multiple messages, define the message format in a simple text file with a .msg extension. By bundling them into one custom message type, your node only needs one publisher and one subscriber. You guarantee that all the data elements stay perfectly synced together when they travel across the ROS network.

#### Message file
```
# custom_robot_msgs/msg/RobotCommand.msg

float64 x
float64 y
float64 z
bool close_gripper

```
#### Example in python:
Import into code and apply
```
from custom_robot_msgs.msg import RobotCommand
...
# 1. Instantiate the custom message
msg = RobotCommand()
# 2. Fill in all the bundled data fields
msg.x = 10.5
msg.y = -5.0
msg.z = 2.0
msg.close_gripper = True
# 3. Publish the synchronized bundle
self.cmd_pub.publish(msg)
self.get_logger().info('Published bundled command: Gripper closing at coordinates.')
```
#### Example in C++:
Import into code and apply
```
#include "custom_robot_msgs/msg/robot_command.hpp"
...
cmd_pub_ = this->create_publisher<custom_robot_msgs::msg::RobotCommand>("robot_commands", 10);

...
auto msg = custom_robot_msgs::msg::RobotCommand();

// 2. Fill in all the bundled data fields
msg.x = 10.5;
msg.y = -5.0;
msg.z = 2.0;
msg.close_gripper = true;

// 3. Publish the synchronized bundle
cmd_pub_->publish(msg);
...
rclcpp::Publisher<custom_robot_msgs::msg::RobotCommand>::SharedPtr cmd_pub_;
```

