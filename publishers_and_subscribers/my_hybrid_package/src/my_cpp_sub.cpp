#include "rclcpp/rclcpp.hpp" //ros2 c++ client library
#include "std_msgs/msg/string.hpp" //std message type for strs


using std::placeholders::_1; 

class NodeE : public rclcpp::Node{
    public:
    NodeE(): Node("node_e"){
       str_sub_ = this->create_subscription<std_msgs::msg::String>("shared_topic", 10, std::bind(&NodeE::str_call, this, _1));
    }

    private:
    void str_call(const std_msgs::msg::String::SharedPtr msg) const{
        //RCLCPP_INFO works like printf, RCLCPP_INFO_STREAM works like cout
        RCLCPP_INFO(this->get_logger(), "Received String: %s", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr str_sub_;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NodeE>());
    rclcpp::shutdown();
    return 0;
}
