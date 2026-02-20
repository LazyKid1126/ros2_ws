#include "rclcpp/rclcpp.hpp"
#include "chrono"
//using namespace
using namespace std::chrono_literals;
// rclcpp::Node 
class HelloNode : public rclcpp::Node
{
public:
    HelloNode() : Node("hello_node"), count_(0) 
    {
        //timer
        timer_ = this->create_wall_timer(1000ms, std::bind(&HelloNode::timer_callback, this));
        //print
        RCLCPP_INFO(this->get_logger(), "Ros 2 Tick Tock");
    }
private:
    //timer_callback function
    void timer_callback()
    {
        count_++;
        RCLCPP_INFO(this->get_logger(), "current count: %d",count_);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    int count_;
};


int main(int argc, char **argv)
{
    //main
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HelloNode>());
    rclcpp::shutdown();
    return 0;
}