#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
  Talker() : Node("toronto_talker")
  {
    publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = create_wall_timer(1s, [this] {
      std_msgs::msg::String message;
      message.data = "Hello Toronto from version 2.0.0";
      RCLCPP_INFO(get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    });
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}
