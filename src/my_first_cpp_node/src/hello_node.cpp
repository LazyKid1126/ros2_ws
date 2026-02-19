#include "rclcpp/rclcpp.hpp"

// 建立一個繼承自 rclcpp::Node 的類別（這是 ROS 2 的標準寫法）
class HelloNode : public rclcpp::Node
{
public:
    HelloNode() : Node("hello_node") // 節點的名稱
    {
        // 這是 ROS 2 的印出功能，類似於 C++ 的 std::cout
        RCLCPP_INFO(this->get_logger(), "Hello ROS 2! 樹莓派 C++ 節點啟動成功！");
    }
};

int main(int argc, char **argv)
{
    // 初始化 ROS 2 通訊介面
    rclcpp::init(argc, argv);
    
    // 建立節點並讓它保持運行（spin）
    rclcpp::spin(std::make_shared<HelloNode>());
    
    // 關閉 ROS 2 通訊介面
    rclcpp::shutdown();
    return 0;
}