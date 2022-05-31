#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100

#include <stdio.h>

int main() {
  printf("[Test15] Running ...");

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


  for (double kI = 0; kI < ELEMENTS / 2; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(hash_set->size == 50 && hash_set->capacity == 128)) {
    HashSetFree(&hash_set);
    return 1;
  }

  for (double kI = ELEMENTS / 2; kI < ELEMENTS; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}