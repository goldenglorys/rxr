// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "create_plan_msgs/srv/detail/create_plan__rosidl_typesupport_introspection_c.h"
#include "create_plan_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "create_plan_msgs/srv/detail/create_plan__functions.h"
#include "create_plan_msgs/srv/detail/create_plan__struct.h"


// Include directives for member types
// Member `start`
// Member `goal`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `start`
// Member `goal`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  create_plan_msgs__srv__CreatePlan_Request__init(message_memory);
}

void create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_fini_function(void * message_memory)
{
  create_plan_msgs__srv__CreatePlan_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_member_array[2] = {
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(create_plan_msgs__srv__CreatePlan_Request, start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(create_plan_msgs__srv__CreatePlan_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_members = {
  "create_plan_msgs__srv",  // message namespace
  "CreatePlan_Request",  // message name
  2,  // number of fields
  sizeof(create_plan_msgs__srv__CreatePlan_Request),
  create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_member_array,  // message members
  create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_type_support_handle = {
  0,
  &create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_create_plan_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Request)() {
  create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_type_support_handle.typesupport_identifier) {
    create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &create_plan_msgs__srv__CreatePlan_Request__rosidl_typesupport_introspection_c__CreatePlan_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "create_plan_msgs/srv/detail/create_plan__rosidl_typesupport_introspection_c.h"
// already included above
// #include "create_plan_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "create_plan_msgs/srv/detail/create_plan__functions.h"
// already included above
// #include "create_plan_msgs/srv/detail/create_plan__struct.h"


// Include directives for member types
// Member `path`
#include "nav_msgs/msg/path.h"
// Member `path`
#include "nav_msgs/msg/detail/path__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  create_plan_msgs__srv__CreatePlan_Response__init(message_memory);
}

void create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_fini_function(void * message_memory)
{
  create_plan_msgs__srv__CreatePlan_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_member_array[1] = {
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(create_plan_msgs__srv__CreatePlan_Response, path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_members = {
  "create_plan_msgs__srv",  // message namespace
  "CreatePlan_Response",  // message name
  1,  // number of fields
  sizeof(create_plan_msgs__srv__CreatePlan_Response),
  create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_member_array,  // message members
  create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_type_support_handle = {
  0,
  &create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_create_plan_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Response)() {
  create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nav_msgs, msg, Path)();
  if (!create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_type_support_handle.typesupport_identifier) {
    create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &create_plan_msgs__srv__CreatePlan_Response__rosidl_typesupport_introspection_c__CreatePlan_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "create_plan_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "create_plan_msgs/srv/detail/create_plan__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_members = {
  "create_plan_msgs__srv",  // service namespace
  "CreatePlan",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_Request_message_type_support_handle,
  NULL  // response message
  // create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_Response_message_type_support_handle
};

static rosidl_service_type_support_t create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_type_support_handle = {
  0,
  &create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_create_plan_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan)() {
  if (!create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_type_support_handle.typesupport_identifier) {
    create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, create_plan_msgs, srv, CreatePlan_Response)()->data;
  }

  return &create_plan_msgs__srv__detail__create_plan__rosidl_typesupport_introspection_c__CreatePlan_service_type_support_handle;
}
