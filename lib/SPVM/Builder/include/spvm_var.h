#ifndef SPVM_VAR_H
#define SPVM_VAR_H

#include "spvm_base.h"

struct SPVM_var {
  SPVM_OP* op_name;
  SPVM_MY* my;
  int8_t is_declaration;
  int8_t is_outer;
};

SPVM_VAR* SPVM_VAR_new(SPVM_COMPILER* compiler);

#endif
