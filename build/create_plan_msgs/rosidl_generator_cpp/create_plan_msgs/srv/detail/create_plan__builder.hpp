// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice

#ifndef CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__BUILDER_HPP_
#define CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "create_plan_msgs/srv/detail/create_plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace create_plan_msgs
{

namespace srv
{

namespace builder
{

class Init_CreatePlan_Request_goal
{
public:
  explicit Init_CreatePlan_Request_goal(::create_plan_msgs::srv::CreatePlan_Request & msg)
  : msg_(msg)
  {}
  ::create_plan_msgs::srv::CreatePlan_Request goal(::create_plan_msgs::srv::CreatePlan_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::create_plan_msgs::srv::CreatePlan_Request msg_;
};

class Init_CreatePlan_Request_start
{
public:
  Init_CreatePlan_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CreatePlan_Request_goal start(::create_plan_msgs::srv::CreatePlan_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_CreatePlan_Request_goal(msg_);
  }

private:
  ::create_plan_msgs::srv::CreatePlan_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::create_plan_msgs::srv::CreatePlan_Request>()
{
  return create_plan_msgs::srv::builder::Init_CreatePlan_Request_start();
}

}  // namespace create_plan_msgs


namespace create_plan_msgs
{

namespace srv
{

namespace builder
{

class Init_CreatePlan_Response_path
{
public:
  Init_CreatePlan_Response_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::create_plan_msgs::srv::CreatePlan_Response path(::create_plan_msgs::srv::CreatePlan_Response::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::create_plan_msgs::srv::CreatePlan_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::create_plan_msgs::srv::CreatePlan_Response>()
{
  return create_plan_msgs::srv::builder::Init_CreatePlan_Response_path();
}

}  // namespace create_plan_msgs

#endif  // CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__BUILDER_HPP_
