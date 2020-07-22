#include "spvm_native.h"
#include "math.h"

int32_t SPNATIVE__TestArray__test(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  double* input_array = stack[0].dref;
  int32_t array_count = stack[1].ival;

  printf("spvm_array (in native)\n");
  for (int32_t i = 0; i < array_count + 3; i++) {
    printf("%.10f ", input_array[i]);
  }
  printf("\n");
  
  return SPVM_SUCCESS;
}
