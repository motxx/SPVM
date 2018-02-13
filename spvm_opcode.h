#ifndef SPVM_OPCODE_H
#define SPVM_OPCODE_H

#include "spvm_base.h"






























































































enum {
  SPVM_OPCODE_C_CODE_NOP,
  SPVM_OPCODE_C_CODE_ADD_INT,
  SPVM_OPCODE_C_CODE_ADD_LONG,
  SPVM_OPCODE_C_CODE_ADD_FLOAT,
  SPVM_OPCODE_C_CODE_ADD_DOUBLE,
  SPVM_OPCODE_C_CODE_SUBTRACT_INT,
  SPVM_OPCODE_C_CODE_SUBTRACT_LONG,
  SPVM_OPCODE_C_CODE_SUBTRACT_FLOAT,
  SPVM_OPCODE_C_CODE_SUBTRACT_DOUBLE,
  SPVM_OPCODE_C_CODE_MULTIPLY_INT,
  SPVM_OPCODE_C_CODE_MULTIPLY_LONG,
  SPVM_OPCODE_C_CODE_MULTIPLY_FLOAT,
  SPVM_OPCODE_C_CODE_MULTIPLY_DOUBLE,
  SPVM_OPCODE_C_CODE_DIVIDE_INT,
  SPVM_OPCODE_C_CODE_DIVIDE_LONG,
  SPVM_OPCODE_C_CODE_DIVIDE_FLOAT,
  SPVM_OPCODE_C_CODE_DIVIDE_DOUBLE,
  SPVM_OPCODE_C_CODE_REMAINDER_BYTE,
  SPVM_OPCODE_C_CODE_REMAINDER_SHORT,
  SPVM_OPCODE_C_CODE_REMAINDER_INT,
  SPVM_OPCODE_C_CODE_REMAINDER_LONG,
  SPVM_OPCODE_C_CODE_REMAINDER_FLOAT,
  SPVM_OPCODE_C_CODE_REMAINDER_DOUBLE,
  SPVM_OPCODE_C_CODE_LEFT_SHIFT_BYTE,
  SPVM_OPCODE_C_CODE_LEFT_SHIFT_SHORT,
  SPVM_OPCODE_C_CODE_LEFT_SHIFT_INT,
  SPVM_OPCODE_C_CODE_LEFT_SHIFT_LONG,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_BYTE,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_SHORT,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_INT,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_LONG,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_UNSIGNED_BYTE,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_UNSIGNED_SHORT,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_UNSIGNED_INT,
  SPVM_OPCODE_C_CODE_RIGHT_SHIFT_UNSIGNED_LONG,
  SPVM_OPCODE_C_CODE_BIT_AND_BYTE,
  SPVM_OPCODE_C_CODE_BIT_AND_SHORT,
  SPVM_OPCODE_C_CODE_BIT_AND_INT,
  SPVM_OPCODE_C_CODE_BIT_AND_LONG,
  SPVM_OPCODE_C_CODE_BIT_OR_BYTE,
  SPVM_OPCODE_C_CODE_BIT_OR_SHORT,
  SPVM_OPCODE_C_CODE_BIT_OR_INT,
  SPVM_OPCODE_C_CODE_BIT_OR_LONG,
  SPVM_OPCODE_C_CODE_BIT_XOR_BYTE,
  SPVM_OPCODE_C_CODE_BIT_XOR_SHORT,
  SPVM_OPCODE_C_CODE_BIT_XOR_INT,
  SPVM_OPCODE_C_CODE_BIT_XOR_LONG,
  SPVM_OPCODE_C_CODE_COMPLEMENT_INT,
  SPVM_OPCODE_C_CODE_COMPLEMENT_LONG,
  SPVM_OPCODE_C_CODE_NEGATE_INT,
  SPVM_OPCODE_C_CODE_NEGATE_LONG,
  SPVM_OPCODE_C_CODE_NEGATE_FLOAT,
  SPVM_OPCODE_C_CODE_NEGATE_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_BYTE_TO_BYTE,
  SPVM_OPCODE_C_CODE_CONVERT_SHORT_TO_SHORT,
  SPVM_OPCODE_C_CODE_CONVERT_INT_TO_INT,
  SPVM_OPCODE_C_CODE_CONVERT_LONG_TO_LONG,
  SPVM_OPCODE_C_CODE_CONVERT_FLOAT_TO_FLOAT,
  SPVM_OPCODE_C_CODE_CONVERT_DOUBLE_TO_DOUBLE,
  SPVM_OPCODE_C_CODE_GT_BYTE,
  SPVM_OPCODE_C_CODE_GT_SHORT,
  SPVM_OPCODE_C_CODE_GT_INT,
  SPVM_OPCODE_C_CODE_GT_LONG,
  SPVM_OPCODE_C_CODE_GT_FLOAT,
  SPVM_OPCODE_C_CODE_GT_DOUBLE,
  SPVM_OPCODE_C_CODE_GE_BYTE,
  SPVM_OPCODE_C_CODE_GE_SHORT,
  SPVM_OPCODE_C_CODE_GE_INT,
  SPVM_OPCODE_C_CODE_GE_LONG,
  SPVM_OPCODE_C_CODE_GE_FLOAT,
  SPVM_OPCODE_C_CODE_GE_DOUBLE,
  SPVM_OPCODE_C_CODE_LT_BYTE,
  SPVM_OPCODE_C_CODE_LT_SHORT,
  SPVM_OPCODE_C_CODE_LT_INT,
  SPVM_OPCODE_C_CODE_LT_LONG,
  SPVM_OPCODE_C_CODE_LT_FLOAT,
  SPVM_OPCODE_C_CODE_LT_DOUBLE,
  SPVM_OPCODE_C_CODE_LE_BYTE,
  SPVM_OPCODE_C_CODE_LE_SHORT,
  SPVM_OPCODE_C_CODE_LE_INT,
  SPVM_OPCODE_C_CODE_LE_LONG,
  SPVM_OPCODE_C_CODE_LE_FLOAT,
  SPVM_OPCODE_C_CODE_LE_DOUBLE,
  SPVM_OPCODE_C_CODE_IS_UNDEF,
  SPVM_OPCODE_C_CODE_IS_NOT_UNDEF,
  SPVM_OPCODE_C_CODE_EQ_BYTE,
  SPVM_OPCODE_C_CODE_EQ_SHORT,
  SPVM_OPCODE_C_CODE_EQ_INT,
  SPVM_OPCODE_C_CODE_EQ_LONG,
  SPVM_OPCODE_C_CODE_EQ_FLOAT,
  SPVM_OPCODE_C_CODE_EQ_DOUBLE,
  SPVM_OPCODE_C_CODE_EQ_OBJECT,
  SPVM_OPCODE_C_CODE_NE_BYTE,
  SPVM_OPCODE_C_CODE_NE_SHORT,
  SPVM_OPCODE_C_CODE_NE_INT,
  SPVM_OPCODE_C_CODE_NE_LONG,
  SPVM_OPCODE_C_CODE_NE_FLOAT,
  SPVM_OPCODE_C_CODE_NE_DOUBLE,
  SPVM_OPCODE_C_CODE_NE_OBJECT,
  SPVM_OPCODE_C_CODE_INC_BYTE,
  SPVM_OPCODE_C_CODE_INC_SHORT,
  SPVM_OPCODE_C_CODE_INC_INT,
  SPVM_OPCODE_C_CODE_INC_LONG,
  SPVM_OPCODE_C_CODE_BOOL_BYTE,
  SPVM_OPCODE_C_CODE_BOOL_SHORT,
  SPVM_OPCODE_C_CODE_BOOL_INT,
  SPVM_OPCODE_C_CODE_BOOL_LONG,
  SPVM_OPCODE_C_CODE_BOOL_FLOAT,
  SPVM_OPCODE_C_CODE_BOOL_DOUBLE,
  SPVM_OPCODE_C_CODE_BOOL_OBJECT,
  SPVM_OPCODE_C_CODE_LOAD_UNDEF,
  SPVM_OPCODE_C_CODE_MOVE,
  SPVM_OPCODE_C_CODE_NEW_OBJECT,
  SPVM_OPCODE_C_CODE_NEW_STRING,
  SPVM_OPCODE_C_CODE_NEW_OBJECT_ARRAY,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_BYTE,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_SHORT,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_INT,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_LONG,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_FLOAT,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_DOUBLE,
  SPVM_OPCODE_C_CODE_ARRAY_LOAD_OBJECT,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_BYTE,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_SHORT,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_INT,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_LONG,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_FLOAT,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_DOUBLE,
  SPVM_OPCODE_C_CODE_ARRAY_STORE_OBJECT,
  SPVM_OPCODE_C_CODE_ARRAY_LENGTH,
  SPVM_OPCODE_C_CODE_GET_FIELD_BYTE,
  SPVM_OPCODE_C_CODE_GET_FIELD_SHORT,
  SPVM_OPCODE_C_CODE_GET_FIELD_INT,
  SPVM_OPCODE_C_CODE_GET_FIELD_LONG,
  SPVM_OPCODE_C_CODE_GET_FIELD_FLOAT,
  SPVM_OPCODE_C_CODE_GET_FIELD_DOUBLE,
  SPVM_OPCODE_C_CODE_GET_FIELD_OBJECT,
  SPVM_OPCODE_C_CODE_SET_FIELD_BYTE,
  SPVM_OPCODE_C_CODE_SET_FIELD_SHORT,
  SPVM_OPCODE_C_CODE_SET_FIELD_INT,
  SPVM_OPCODE_C_CODE_SET_FIELD_LONG,
  SPVM_OPCODE_C_CODE_SET_FIELD_FLOAT,
  SPVM_OPCODE_C_CODE_SET_FIELD_DOUBLE,
  SPVM_OPCODE_C_CODE_SET_FIELD_OBJECT,
  SPVM_OPCODE_C_CODE_IF_EQ_ZERO,
  SPVM_OPCODE_C_CODE_IF_NE_ZERO,
  SPVM_OPCODE_C_CODE_TABLE_SWITCH,
  SPVM_OPCODE_C_CODE_TABLE_SWITCH_RANGE,
  SPVM_OPCODE_C_CODE_LOOKUP_SWITCH,
  SPVM_OPCODE_C_CODE_GOTO,
  SPVM_OPCODE_C_CODE_CALL_SUB,
  SPVM_OPCODE_C_CODE_RETURN,
  SPVM_OPCODE_C_CODE_CROAK,
  SPVM_OPCODE_C_CODE_LOAD_EXCEPTION_VAR,
  SPVM_OPCODE_C_CODE_STORE_EXCEPTION_VAR,
  SPVM_OPCODE_C_CODE_CURRENT_LINE,
  SPVM_OPCODE_C_CODE_WEAKEN_FIELD_OBJECT,
  SPVM_OPCODE_C_CODE_NEW_BYTE_ARRAY,
  SPVM_OPCODE_C_CODE_NEW_SHORT_ARRAY,
  SPVM_OPCODE_C_CODE_NEW_INT_ARRAY,
  SPVM_OPCODE_C_CODE_NEW_LONG_ARRAY,
  SPVM_OPCODE_C_CODE_NEW_FLOAT_ARRAY,
  SPVM_OPCODE_C_CODE_NEW_DOUBLE_ARRAY,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_STRING,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_BYTE,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_SHORT,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_INT,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_LONG,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_FLOAT,
  SPVM_OPCODE_C_CODE_CONCAT_STRING_DOUBLE,
  SPVM_OPCODE_C_CODE_PUSH_EVAL,
  SPVM_OPCODE_C_CODE_POP_EVAL,
  SPVM_OPCODE_C_CODE_PUSH_ARG,
  SPVM_OPCODE_C_CODE_INC_REF_COUNT,
  SPVM_OPCODE_C_CODE_DEC_REF_COUNT,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_BYTE,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_SHORT,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_INT,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_LONG,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_FLOAT,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_DOUBLE,
  SPVM_OPCODE_C_CODE_LOAD_PACKAGE_VAR_OBJECT,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_BYTE,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_SHORT,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_INT,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_LONG,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_FLOAT,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_DOUBLE,
  SPVM_OPCODE_C_CODE_STORE_PACKAGE_VAR_OBJECT,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_BYTE,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_SHORT,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_INT,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_LONG,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_FLOAT,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_DOUBLE,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_BYTE_0,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_SHORT_0,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_INT_0,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_LONG_0,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_FLOAT_0,
  SPVM_OPCODE_C_CODE_LOAD_CONSTANT_DOUBLE_0,
  SPVM_OPCODE_C_CODE_CASE,
  SPVM_OPCODE_C_CODE_IF_CROAK_CATCH,
  SPVM_OPCODE_C_CODE_IF_CROAK_RETURN,
  SPVM_OPCODE_C_CODE_SET_CROAK_FLAG_TRUE,
  SPVM_OPCODE_C_CODE_MOVE_BYTE,
  SPVM_OPCODE_C_CODE_MOVE_SHORT,
  SPVM_OPCODE_C_CODE_MOVE_INT,
  SPVM_OPCODE_C_CODE_MOVE_LONG,
  SPVM_OPCODE_C_CODE_MOVE_FLOAT,
  SPVM_OPCODE_C_CODE_MOVE_DOUBLE,
  SPVM_OPCODE_C_CODE_MOVE_OBJECT,
  SPVM_OPCODE_C_CODE_PUSH_AUTO_DEC_REF_COUNT,
  SPVM_OPCODE_C_CODE_LEAVE_SCOPE,
};

enum {
  SPVM_OPCODE_C_FLAG_IS_LABEL = 1
};

extern const char* const SPVM_OPCODE_C_CODE_NAMES[];

struct SPVM_opcode {
  int16_t code;
  int8_t has_label;
  int8_t dummy;
  int32_t operand0;
  int32_t operand1;
  int32_t operand2;
};

enum {
  SPVM_OPCODE_C_UNIT = sizeof(SPVM_OPCODE) / sizeof(int32_t)
};

SPVM_OPCODE* SPVM_OPCODE_new();

#endif
