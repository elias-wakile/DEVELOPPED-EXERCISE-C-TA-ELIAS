#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test20] Running ...");

  // HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  // insert elements.
  for (double kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }

  if (hash_set->size != 100) {
    HashSetFree(&hash_set);
    return 1;
  }

  unsigned int old_cap = hash_set->capacity;

  HashSetClear(hash_set);

  for (size_t k_i = 0; k_i < hash_set->capacity; ++k_i) {
    if ((hash_set->NodesList[k_i]->data != NULL) || (hash_set->NodesList[k_i]->hashCount != 0)) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  
  if ((hash_set->capacity != old_cap) || (hash_set->size != 0) || (HashSetGetLoadFactor(hash_set) != 0)){
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

}
