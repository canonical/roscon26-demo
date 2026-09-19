#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Listener : public rclcpp::Node
{
public:
  Listener() : Node("toronto_listener")
  {
    subscription_ = create_subscription<std_msgs::msg::String>(
      "chatter", 10, [this](const std_msgs::msg::String & message) {
        RCLCPP_INFO(get_logger(), "I heard: '%s'", message.data.c_str());
      });
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  rclcpp::shutdown();
  return 0;
}
