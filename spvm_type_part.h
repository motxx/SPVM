#ifndef SPVM_TYPE_PART_H
#define SPVM_TYPE_PART_H

#include "spvm_base.h"

enum {
  SPVM_TYPE_PART_C_CODE_NAME,
  SPVM_TYPE_PART_C_CODE_CHAR
};

extern const char* const SPVM_TYPE_PART_C_CODE_NAMES[];

struct SPVM_type_part {
  union {
    const char* char_name;
  } uv;
  int32_t code;
};

SPVM_TYPE_PART* SPVM_TYPE_PART_new(SPVM_COMPILER* compiler);

#endif
