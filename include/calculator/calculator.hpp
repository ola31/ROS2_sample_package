#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include<memory>
#include<sstream>
#include <string>
#include <utility>
#include <vector>
#include <stdexcept>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "msg_src_action_interface_example/msg/arithmetic.hpp"
#include "msg_srv_action_interface_example/srv/arithmetic_operator.hpp"
#include "msg_srv_action_interface_exemple/action/arithmetic_checker.hpp"

class Calculator : public rclcpp::Node
{
public:
    using ArithmeticArgument = msg_srv_action_interface_exemple::msg::ArithmeticArgument;
    using ArithmeticOperator = msg_srv_action_interface_exemple::srv::ArithmeticOperator;
    using ArithmeticChecker = msg_srv_action_interface_exemple::action::ArithmeticChecker;
    using GoalHandleArithmeticChecker = rclcpp_action::serverGoalHandle<ArithmeticChecker>

    explicit Calculator(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions);
    virtual ~Calculator();

    float calculate_given_formula(const float &a, const float &b,  const int8_t & operator);

private:
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GualUUID & uuid,
        std::shared_ptr<const ArithmeticChecker::Goal> goal);
        rclcpp_action::CancelResponce handle_cancel(const std::shared_ptr<GoalHangleArithmeticChecker> goal_handle);

        rclcpp::Subsciption<ArithmeticArgument>::SharedPtr arithmetic_argument_subscriber_;

        rclcpp::Service<ArithmeticOperator>::SharedPtr arithmetic_argument_server_;

        rclcpp::action::Server<ArithmeticChecker>::SharedPtr arithmetic_action_server_;

        float argument_a;
        float argument_b;

        int8_t argument_operator_;
        float argument_result_;

        std::string argument_formula_;
        std::vector<std::string> operator_;
};



#endif // CALCULATOR_HPP
