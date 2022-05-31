#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test16] Running ...");

  // HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  // insert elements.
  for (double kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }

  if (!(hash_set->size == 100 && hash_set->capacity == 256)) {
    HashSetFree(&hash_set);
    return 1;
  }

  for (double kI = ELEMENTS; kI < ELEMENTS + 5; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 0) {
      HashSetFree(&hash_set);
      return 1;
    }
  }

  for (double kI = ELEMENTS - 5; kI < ELEMENTS; ++kI) {
    int res = HashSetInsert(hash_set, &kI);
    if (res != 0) {
      HashSetFree(&hash_set);
      return 1;
    }
  }

  for (double kI = 0; kI < ELEMENTS; ++kI) {
    HashSetErase(hash_set, &kI);
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}