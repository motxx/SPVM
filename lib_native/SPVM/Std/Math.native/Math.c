#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>

#include "spvm_api.h"

#define SPVM__MATH__PI 3.14159265358979323846
#define SPVM__MATH__E 2.7182818284590452354

double SPVM__Std__Math__sin(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = sin(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__cos(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = cos(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__tan(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = tan(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__asin(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = asin(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__acosh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = acosh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__atanh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = atanh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__asinh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = asinh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__acos(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = acos(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__atan(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = atan(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__exp(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = exp(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__exp2(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = exp2(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__log(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = log(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__log10(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = log10(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__sqrt(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = sqrt(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__cbrt(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = cbrt(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__ceil(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = ceil(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__remainder(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  // x - Math.Round(x / y) * y
  double value = remainder(args[0].double_value, args[1].double_value);

  return value;
}

double SPVM__Std__Math__floor(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = floor(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__nearbyint(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = nearbyint(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__atan2(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = atan2(args[0].double_value, args[1].double_value);
  
  return value;
}

double SPVM__Std__Math__pow(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = pow(args[0].double_value, args[1].double_value);
  
  return value;
}

double SPVM__Std__Math__round(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = round(args[0].double_value);
  
  return value;
}

int32_t SPVM__Std__Math__abs(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int32_t value = (int32_t)labs(args[0].int_value);
  
  return value;
}

int64_t SPVM__Std__Math__labs(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  int64_t value = (int64_t)labs(args[0].long_value);
  
  return value;
}

double SPVM__Std__Math__fabs(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = fabs(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__erf(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = erf(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__erfc(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = erfc(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__lgamma(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = lgamma(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__tgamma(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = tgamma(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__sinh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = sinh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__cosh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = cosh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__tanh(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = tanh(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__hypot(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = hypot(args[0].double_value, args[1].double_value);
  
  return value;
}

double SPVM__Std__Math__expm1(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = expm1(args[0].double_value);
  
  return value;
}

double SPVM__Std__Math__log1p(SPVM_API* api, SPVM_API_VALUE* args) {
  (void)api;
  
  double value = log1p(args[0].double_value);
  
  return value;
}
