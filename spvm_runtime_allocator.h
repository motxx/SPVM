#ifndef SPVM_RUNTIME_ALLOCATOR_H
#define SPVM_RUNTIME_ALLOCATOR_H

#include <stddef.h>

#include "spvm_base.h"
#include "spvm_nai.h"

struct SPVM_runtime_allocator {
  // Memory_pool
  SPVM_MEMORY_POOL* memory_pool;
  
  // Free lists
  SPVM_DYNAMIC_ARRAY** freelists;

  // use memory pool max reference byte size
  int64_t object_max_byte_size_use_memory_pool;
};

SPVM_RUNTIME_ALLOCATOR* SPVM_RUNTIME_ALLOCATOR_new(SPVM_RUNTIME* runtime);

void* SPVM_RUNTIME_ALLOCATOR_malloc(SPVM_NAI* nai, SPVM_RUNTIME_ALLOCATOR* allocator, int32_t size);
void SPVM_RUNTIME_ALLOCATOR_free_object(SPVM_NAI* nai, SPVM_RUNTIME_ALLOCATOR* allocator, SPVM_OBJECT* object);
int32_t SPVM_RUNTIME_ALLOCATOR_get_freelist_index(SPVM_NAI* nai, SPVM_RUNTIME_ALLOCATOR* allocator, int64_t size);

void SPVM_RUNTIME_ALLOCATOR_free(SPVM_RUNTIME* runtime, SPVM_RUNTIME_ALLOCATOR* allocator);

#endif
