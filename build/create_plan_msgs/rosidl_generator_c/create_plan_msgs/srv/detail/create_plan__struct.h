// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice

#ifndef CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_H_
#define CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/CreatePlan in the package create_plan_msgs.
typedef struct create_plan_msgs__srv__CreatePlan_Request
{
  geometry_msgs__msg__PoseStamped start;
  geometry_msgs__msg__PoseStamped goal;
} create_plan_msgs__srv__CreatePlan_Request;

// Struct for a sequence of create_plan_msgs__srv__CreatePlan_Request.
typedef struct create_plan_msgs__srv__CreatePlan_Request__Sequence
{
  create_plan_msgs__srv__CreatePlan_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} create_plan_msgs__srv__CreatePlan_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'path'
#include "nav_msgs/msg/detail/path__struct.h"

/// Struct defined in srv/CreatePlan in the package create_plan_msgs.
typedef struct create_plan_msgs__srv__CreatePlan_Response
{
  nav_msgs__msg__Path path;
} create_plan_msgs__srv__CreatePlan_Response;

// Struct for a sequence of create_plan_msgs__srv__CreatePlan_Response.
typedef struct create_plan_msgs__srv__CreatePlan_Response__Sequence
{
  create_plan_msgs__srv__CreatePlan_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} create_plan_msgs__srv__CreatePlan_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CREATE_PLAN_MSGS__SRV__DETAIL__CREATE_PLAN__STRUCT_H_
