#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>

#include "spvm_api.h"

float SPVM__Float__POSITIVE_INFINITY(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t positive_infinity_bits = 0x7f800000;
  
  float positive_infinity;
  
  memcpy((void*)&positive_infinity, (void*)&positive_infinity_bits, sizeof(float));
  
  return positive_infinity;
}

float SPVM__Float__NEGATIVE_INFINITY(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t negative_infinity_bits = 0xff800000;
  
  float negative_infinity;
  
  memcpy((void*)&negative_infinity, (void*)&negative_infinity_bits, sizeof(float));
  
  return negative_infinity;
}

float SPVM__Float__NaN(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t nan_bits = 0x7fc00000;
  
  float nan;
  
  memcpy((void*)&nan, (void*)&nan_bits, sizeof(float));
  
  return nan;
}

float SPVM__Float__MAX_VALUE(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t max_value_bits = 0x7f7fffff;
  
  float max_value;
  
  memcpy((void*)&max_value, (void*)&max_value_bits, sizeof(float));
  
  return max_value;
}

float SPVM__Float__MIN_NORMAL(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t min_normal_bits = 0x00800000;
  
  float min_normal;
  
  memcpy((void*)&min_normal, (void*)&min_normal_bits, sizeof(float));
  
  return min_normal;
}

float SPVM__Float__MIN_VALUE(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t min_value_bits = 0x1;
  
  float min_value;
  
  memcpy((void*)&min_value, (void*)&min_value_bits, sizeof(float));
  
  return min_value;
}

float SPVM__Float__MAX_EXPONENT(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t max_exponent_bits = 0x1;
  
  float max_exponent;
  
  memcpy((void*)&max_exponent, (void*)&max_exponent_bits, sizeof(float));
  
  return max_exponent;
}

int32_t SPVM__Float__is_infinite(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  float float_value = args[0].float_value;
  
  int32_t int_value;
  
  memcpy((void*)&int_value, (void*)&float_value, sizeof(float));
  
  if (int_value == 0x7f800000 || int_value == 0xff800000) {
    return 1;
  }
  else {
    return 0;
  }
}
