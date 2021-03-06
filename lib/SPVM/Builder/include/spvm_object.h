#ifndef SPVM_OBJECT_H
#define SPVM_OBJECT_H

#include "spvm_base.h"
#include "spvm_native.h"

// SPVM_OBJECT
struct SPVM_object {
  SPVM_RUNTIME_WEAKEN_BACKREF* weaken_backref_head;
  int32_t ref_count;
  int32_t basic_type_id;
  uint8_t type_dimension;
  uint8_t has_destructor;
  uint8_t runtime_type;
  int32_t array_length;
};

#endif
