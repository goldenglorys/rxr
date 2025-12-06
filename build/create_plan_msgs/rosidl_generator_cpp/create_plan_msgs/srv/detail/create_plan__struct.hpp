// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice

#ifndef CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_HPP_
#define CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'start'
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__create_plan_msgs__srv__CreatePlan_Request __attribute__((deprecated))
#else
# define DEPRECATED__create_plan_msgs__srv__CreatePlan_Request __declspec(deprecated)
#endif

namespace create_plan_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CreatePlan_Request_
{
  using Type = CreatePlan_Request_<ContainerAllocator>;

  explicit CreatePlan_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit CreatePlan_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _start_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _start_type start;
  using _goal_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__start(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__goal(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__create_plan_msgs__srv__CreatePlan_Request
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__create_plan_msgs__srv__CreatePlan_Request
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CreatePlan_Request_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const CreatePlan_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CreatePlan_Request_

// alias to use template instance with default allocator
using CreatePlan_Request =
  create_plan_msgs::srv::CreatePlan_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace create_plan_msgs


// Include directives for member types
// Member 'path'
#include "nav_msgs/msg/detail/path__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__create_plan_msgs__srv__CreatePlan_Response __attribute__((deprecated))
#else
# define DEPRECATED__create_plan_msgs__srv__CreatePlan_Response __declspec(deprecated)
#endif

namespace create_plan_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CreatePlan_Response_
{
  using Type = CreatePlan_Response_<ContainerAllocator>;

  explicit CreatePlan_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path(_init)
  {
    (void)_init;
  }

  explicit CreatePlan_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _path_type =
    nav_msgs::msg::Path_<ContainerAllocator>;
  _path_type path;

  // setters for named parameter idiom
  Type & set__path(
    const nav_msgs::msg::Path_<ContainerAllocator> & _arg)
  {
    this->path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__create_plan_msgs__srv__CreatePlan_Response
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__create_plan_msgs__srv__CreatePlan_Response
    std::shared_ptr<create_plan_msgs::srv::CreatePlan_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CreatePlan_Response_ & other) const
  {
    if (this->path != other.path) {
      return false;
    }
    return true;
  }
  bool operator!=(const CreatePlan_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CreatePlan_Response_

// alias to use template instance with default allocator
using CreatePlan_Response =
  create_plan_msgs::srv::CreatePlan_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace create_plan_msgs

namespace create_plan_msgs
{

namespace srv
{

struct CreatePlan
{
  using Request = create_plan_msgs::srv::CreatePlan_Request;
  using Response = create_plan_msgs::srv::CreatePlan_Response;
};

}  // namespace srv

}  // namespace create_plan_msgs

#endif  // CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_HPP_
