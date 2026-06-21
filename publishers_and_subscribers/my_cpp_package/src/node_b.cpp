#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1; // Placeholder representing the first argument passed to the callback (the message)


class NodeB : public rclcpp::Node{
    public:
    NodeB() : Node("node_b"){
        //--Publishers--(data_type, topic, queue_size)
        str_pub_= this->create_publisher<std_msgs::msg::String>("str_topic", 10);
        bool_pub_= this->create_publisher<std_msgs::msg::Bool>("bool_topic", 10);
        float_pub_= this->create_publisher<std_msgs::msg::Float64>("float_topic", 10);
        int_pub_= this->create_publisher<std_msgs::msg::Int64>("int_topic", 10);

        timer_ = this->create_wall_timer(1s, std::bind(&NodeB::periodic_messages, this));

        //--Subscribers--(data_type, topic, queue_size, callback fxn)
        str_sub_ = this->create_subscription<std_msgs::msg::String>("str_topic", 10, std::bind(&NodeB::str_call, this, _1));
        bool_sub_ = this->create_subscription<std_msgs::msg::Bool>("bool_topic", 10, std::bind(&NodeB::bool_call, this, _1));
        float_sub_ = this->create_subscription<std_msgs::msg::Float64>("float_topic", 10, std::bind(&NodeB::float_call, this, _1));
        int_sub_ = this->create_subscription<std_msgs::msg::Int64>("int_topic", 10, std::bind(&NodeB::int_call, this, _1));
    }

    private:
    //Publishing fxns
    void periodic_messages(){
        //Publish string
        auto str_msg = std_msgs::msg::String();
        str_msg.data = "Heeeey";
        str_pub_->publish(str_msg);
        //Publish bool
        auto bool_msg = std_msgs::msg::Bool();
        bool_msg.data = false;
        bool_pub_->publish(bool_msg);
        //Publish float
        auto float_msg = std_msgs::msg::Float64();
        float_msg.data = 3.14159;
        float_pub_->publish(float_msg);
        //Publish int
        auto int_msg = std_msgs::msg::Int64();
        int_msg.data = 89;
        int_pub_->publish(int_msg);
    }
    //Subscription callbacks
    void str_call(const std_msgs::msg::String::SharedPtr msg) const{
        //RCLCPP_INFO works like printf, RCLCPP_INFO_STREAM works like cout
        RCLCPP_INFO(this->get_logger(), "Received String: %s", msg->data.c_str());
    }
    void bool_call(const std_msgs::msg::Bool::SharedPtr msg) const{
        RCLCPP_INFO(this->get_logger(), "Received bool: %s", msg->data ? "true" : "false");
    }
    void float_call(const std_msgs::msg::Float64::SharedPtr msg) const{
        RCLCPP_INFO(this->get_logger(), "Received float: %f", msg->data);
    }
    void int_call(const std_msgs::msg::Int64::SharedPtr msg) const{
        RCLCPP_INFO(this->get_logger(), "Received String: %ld", msg->data);
    }
    //objs
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr str_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr bool_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr float_pub_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr int_pub_;
    
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr str_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr bool_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr float_sub_;
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr int_sub_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NodeB>());
    rclcpp::shutdown();
    return 0;
}