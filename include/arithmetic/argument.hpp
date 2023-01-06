#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <chrono>
#include <memory>
#include <string>
#include <utility>

#include "rclcpp/rclcpp.hpp"

#include "msg_srv_action_interface_exaemple/msg/arithmetic_argument.hpp"

class Argument : public rclcpp::Node
{
public:
    using ArithmeticArgument = msg_srv_action_interface_exaemple::msg::ArithmeticArgument;

    explicit Argument(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions());
    virtual ~Argument();

private:
    void publish_random_arithmetic_argument();
    void update_parameter();

    float min_random_num;
    float max_random_num;

    rclcpp::Publisher<ArithmeticArgument>::SharedPtr arithmetic_argument_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<rcl_interfaces::msg::ParameterEvent>::SharedPtr parameter_event_sub_;
    rclcpp::AsyncParameterClient::SharedPtr parameters_client_;

};




#endif // ARGUMENT_HPP
