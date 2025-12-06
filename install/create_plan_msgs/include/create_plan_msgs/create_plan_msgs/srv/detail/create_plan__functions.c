// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from create_plan_msgs:srv/CreatePlan.idl
// generated code does not contain a copyright notice
#include "create_plan_msgs/srv/detail/create_plan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `start`
// Member `goal`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
create_plan_msgs__srv__CreatePlan_Request__init(create_plan_msgs__srv__CreatePlan_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__PoseStamped__init(&msg->start)) {
    create_plan_msgs__srv__CreatePlan_Request__fini(msg);
    return false;
  }
  // goal
  if (!geometry_msgs__msg__PoseStamped__init(&msg->goal)) {
    create_plan_msgs__srv__CreatePlan_Request__fini(msg);
    return false;
  }
  return true;
}

void
create_plan_msgs__srv__CreatePlan_Request__fini(create_plan_msgs__srv__CreatePlan_Request * msg)
{
  if (!msg) {
    return;
  }
  // start
  geometry_msgs__msg__PoseStamped__fini(&msg->start);
  // goal
  geometry_msgs__msg__PoseStamped__fini(&msg->goal);
}

bool
create_plan_msgs__srv__CreatePlan_Request__are_equal(const create_plan_msgs__srv__CreatePlan_Request * lhs, const create_plan_msgs__srv__CreatePlan_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->start), &(rhs->start)))
  {
    return false;
  }
  // goal
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
create_plan_msgs__srv__CreatePlan_Request__copy(
  const create_plan_msgs__srv__CreatePlan_Request * input,
  create_plan_msgs__srv__CreatePlan_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->start), &(output->start)))
  {
    return false;
  }
  // goal
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

create_plan_msgs__srv__CreatePlan_Request *
create_plan_msgs__srv__CreatePlan_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Request * msg = (create_plan_msgs__srv__CreatePlan_Request *)allocator.allocate(sizeof(create_plan_msgs__srv__CreatePlan_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(create_plan_msgs__srv__CreatePlan_Request));
  bool success = create_plan_msgs__srv__CreatePlan_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
create_plan_msgs__srv__CreatePlan_Request__destroy(create_plan_msgs__srv__CreatePlan_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    create_plan_msgs__srv__CreatePlan_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
create_plan_msgs__srv__CreatePlan_Request__Sequence__init(create_plan_msgs__srv__CreatePlan_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Request * data = NULL;

  if (size) {
    data = (create_plan_msgs__srv__CreatePlan_Request *)allocator.zero_allocate(size, sizeof(create_plan_msgs__srv__CreatePlan_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = create_plan_msgs__srv__CreatePlan_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        create_plan_msgs__srv__CreatePlan_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
create_plan_msgs__srv__CreatePlan_Request__Sequence__fini(create_plan_msgs__srv__CreatePlan_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      create_plan_msgs__srv__CreatePlan_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

create_plan_msgs__srv__CreatePlan_Request__Sequence *
create_plan_msgs__srv__CreatePlan_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Request__Sequence * array = (create_plan_msgs__srv__CreatePlan_Request__Sequence *)allocator.allocate(sizeof(create_plan_msgs__srv__CreatePlan_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = create_plan_msgs__srv__CreatePlan_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
create_plan_msgs__srv__CreatePlan_Request__Sequence__destroy(create_plan_msgs__srv__CreatePlan_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    create_plan_msgs__srv__CreatePlan_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
create_plan_msgs__srv__CreatePlan_Request__Sequence__are_equal(const create_plan_msgs__srv__CreatePlan_Request__Sequence * lhs, const create_plan_msgs__srv__CreatePlan_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!create_plan_msgs__srv__CreatePlan_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
create_plan_msgs__srv__CreatePlan_Request__Sequence__copy(
  const create_plan_msgs__srv__CreatePlan_Request__Sequence * input,
  create_plan_msgs__srv__CreatePlan_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(create_plan_msgs__srv__CreatePlan_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    create_plan_msgs__srv__CreatePlan_Request * data =
      (create_plan_msgs__srv__CreatePlan_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!create_plan_msgs__srv__CreatePlan_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          create_plan_msgs__srv__CreatePlan_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!create_plan_msgs__srv__CreatePlan_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `path`
#include "nav_msgs/msg/detail/path__functions.h"

bool
create_plan_msgs__srv__CreatePlan_Response__init(create_plan_msgs__srv__CreatePlan_Response * msg)
{
  if (!msg) {
    return false;
  }
  // path
  if (!nav_msgs__msg__Path__init(&msg->path)) {
    create_plan_msgs__srv__CreatePlan_Response__fini(msg);
    return false;
  }
  return true;
}

void
create_plan_msgs__srv__CreatePlan_Response__fini(create_plan_msgs__srv__CreatePlan_Response * msg)
{
  if (!msg) {
    return;
  }
  // path
  nav_msgs__msg__Path__fini(&msg->path);
}

bool
create_plan_msgs__srv__CreatePlan_Response__are_equal(const create_plan_msgs__srv__CreatePlan_Response * lhs, const create_plan_msgs__srv__CreatePlan_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path
  if (!nav_msgs__msg__Path__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  return true;
}

bool
create_plan_msgs__srv__CreatePlan_Response__copy(
  const create_plan_msgs__srv__CreatePlan_Response * input,
  create_plan_msgs__srv__CreatePlan_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // path
  if (!nav_msgs__msg__Path__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  return true;
}

create_plan_msgs__srv__CreatePlan_Response *
create_plan_msgs__srv__CreatePlan_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Response * msg = (create_plan_msgs__srv__CreatePlan_Response *)allocator.allocate(sizeof(create_plan_msgs__srv__CreatePlan_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(create_plan_msgs__srv__CreatePlan_Response));
  bool success = create_plan_msgs__srv__CreatePlan_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
create_plan_msgs__srv__CreatePlan_Response__destroy(create_plan_msgs__srv__CreatePlan_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    create_plan_msgs__srv__CreatePlan_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
create_plan_msgs__srv__CreatePlan_Response__Sequence__init(create_plan_msgs__srv__CreatePlan_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Response * data = NULL;

  if (size) {
    data = (create_plan_msgs__srv__CreatePlan_Response *)allocator.zero_allocate(size, sizeof(create_plan_msgs__srv__CreatePlan_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = create_plan_msgs__srv__CreatePlan_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        create_plan_msgs__srv__CreatePlan_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
create_plan_msgs__srv__CreatePlan_Response__Sequence__fini(create_plan_msgs__srv__CreatePlan_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      create_plan_msgs__srv__CreatePlan_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

create_plan_msgs__srv__CreatePlan_Response__Sequence *
create_plan_msgs__srv__CreatePlan_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  create_plan_msgs__srv__CreatePlan_Response__Sequence * array = (create_plan_msgs__srv__CreatePlan_Response__Sequence *)allocator.allocate(sizeof(create_plan_msgs__srv__CreatePlan_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = create_plan_msgs__srv__CreatePlan_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
create_plan_msgs__srv__CreatePlan_Response__Sequence__destroy(create_plan_msgs__srv__CreatePlan_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    create_plan_msgs__srv__CreatePlan_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
create_plan_msgs__srv__CreatePlan_Response__Sequence__are_equal(const create_plan_msgs__srv__CreatePlan_Response__Sequence * lhs, const create_plan_msgs__srv__CreatePlan_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!create_plan_msgs__srv__CreatePlan_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
create_plan_msgs__srv__CreatePlan_Response__Sequence__copy(
  const create_plan_msgs__srv__CreatePlan_Response__Sequence * input,
  create_plan_msgs__srv__CreatePlan_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(create_plan_msgs__srv__CreatePlan_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    create_plan_msgs__srv__CreatePlan_Response * data =
      (create_plan_msgs__srv__CreatePlan_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!create_plan_msgs__srv__CreatePlan_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          create_plan_msgs__srv__CreatePlan_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!create_plan_msgs__srv__CreatePlan_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
