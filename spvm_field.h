#ifndef SPVM_FIELD_H
#define SPVM_FIELD_H

#include "spvm_base.h"

// Field information
struct SPVM_field {
  SPVM_OP* op_package;
  SPVM_OP* op_name;
  SPVM_OP* op_type;
  int32_t id;
  int32_t index;
  _Bool has_getter;
  _Bool has_setter;
  int32_t byte_offset;
};

SPVM_FIELD* SPVM_FIELD_new(SPVM_COMPILER* compiler);
int32_t SPVM_FIELD_get_byte_size(SPVM_COMPILER* compiler, SPVM_FIELD* field);

#endif
