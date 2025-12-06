// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice

#ifndef CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__TRAITS_HPP_
#define CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "create_plan_msgs/srv/detail/create_plan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace create_plan_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CreatePlan_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    to_flow_style_yaml(msg.start, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CreatePlan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start:\n";
    to_block_style_yaml(msg.start, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CreatePlan_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace create_plan_msgs

namespace rosidl_generator_traits
{

[[deprecated("use create_plan_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const create_plan_msgs::srv::CreatePlan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  create_plan_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use create_plan_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const create_plan_msgs::srv::CreatePlan_Request & msg)
{
  return create_plan_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<create_plan_msgs::srv::CreatePlan_Request>()
{
  return "create_plan_msgs::srv::CreatePlan_Request";
}

template<>
inline const char * name<create_plan_msgs::srv::CreatePlan_Request>()
{
  return "create_plan_msgs/srv/CreatePlan_Request";
}

template<>
struct has_fixed_size<create_plan_msgs::srv::CreatePlan_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<create_plan_msgs::srv::CreatePlan_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<create_plan_msgs::srv::CreatePlan_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'path'
#include "nav_msgs/msg/detail/path__traits.hpp"

namespace create_plan_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CreatePlan_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: path
  {
    out << "path: ";
    to_flow_style_yaml(msg.path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CreatePlan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path:\n";
    to_block_style_yaml(msg.path, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CreatePlan_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace create_plan_msgs

namespace rosidl_generator_traits
{

[[deprecated("use create_plan_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const create_plan_msgs::srv::CreatePlan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  create_plan_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use create_plan_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const create_plan_msgs::srv::CreatePlan_Response & msg)
{
  return create_plan_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<create_plan_msgs::srv::CreatePlan_Response>()
{
  return "create_plan_msgs::srv::CreatePlan_Response";
}

template<>
inline const char * name<create_plan_msgs::srv::CreatePlan_Response>()
{
  return "create_plan_msgs/srv/CreatePlan_Response";
}

template<>
struct has_fixed_size<create_plan_msgs::srv::CreatePlan_Response>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Path>::value> {};

template<>
struct has_bounded_size<create_plan_msgs::srv::CreatePlan_Response>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Path>::value> {};

template<>
struct is_message<create_plan_msgs::srv::CreatePlan_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<create_plan_msgs::srv::CreatePlan>()
{
  return "create_plan_msgs::srv::CreatePlan";
}

template<>
inline const char * name<create_plan_msgs::srv::CreatePlan>()
{
  return "create_plan_msgs/srv/CreatePlan";
}

template<>
struct has_fixed_size<create_plan_msgs::srv::CreatePlan>
  : std::integral_constant<
    bool,
    has_fixed_size<create_plan_msgs::srv::CreatePlan_Request>::value &&
    has_fixed_size<create_plan_msgs::srv::CreatePlan_Response>::value
  >
{
};

template<>
struct has_bounded_size<create_plan_msgs::srv::CreatePlan>
  : std::integral_constant<
    bool,
    has_bounded_size<create_plan_msgs::srv::CreatePlan_Request>::value &&
    has_bounded_size<create_plan_msgs::srv::CreatePlan_Response>::value
  >
{
};

template<>
struct is_service<create_plan_msgs::srv::CreatePlan>
  : std::true_type
{
};

template<>
struct is_service_request<create_plan_msgs::srv::CreatePlan_Request>
  : std::true_type
{
};

template<>
struct is_service_response<create_plan_msgs::srv::CreatePlan_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__TRAITS_HPP_
