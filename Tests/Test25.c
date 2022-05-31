#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100

#include <stdio.h>

int main() {
  printf("[Test25] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  // insert elements.
  for (int kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }
  if (!(hash_set->size == 100 && hash_set->capacity == 256)) {
    HashSetFree(&hash_set);
    return 1;
  }


  for (int kI = 0; kI < ELEMENTS / 2; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      return 1;
    }
  }
  if (!(hash_set->size == 50 && hash_set->capacity == 128)) {
    return 1;
  }

  for (int kI = ELEMENTS / 2; kI < ELEMENTS; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      return 1;
    }
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}