#ifndef SPVM_CONSTANT_POOL_FIELD_H
#define SPVM_CONSTANT_POOL_FIELD_H

#include "spvm_base.h"

// SPVM_CONSTANT_POOL_FIELD
struct SPVM_constant_pool_field {
  int32_t name_id;
  int32_t index;
  int32_t type_id;
};

#endif
