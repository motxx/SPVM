#include "spvm_native.h"
#include "math.h"

int32_t SPNATIVE__MySin__spvm_sin_native(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  double* input_array  = stack[0].dref;
  double* output_array = stack[1].dref;
  int32_t array_count  = stack[2].ival;

  for (int32_t i = 0; i < array_count; i++) {
    output_array[i] = sin(input_array[i]);
    if (i < 5 || (i >= 5 && i >= array_count - 5)) {
      printf("i: %d input: %.10f\n", i, input_array[i]);
      printf("i: %d output: %.10f\n", i, output_array[i]);
    }
  }
  
  return SPVM_SUCCESS;
}
