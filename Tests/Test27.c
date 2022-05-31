#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test27] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  // insert elements.
  for (int kI = 0; kI < ELEMENTS; kI++) {
    HashSetInsert(hash_set, &kI);
  }
  if (!(hash_set->size == 100 && hash_set->capacity == 256)) {
    HashSetFree(&hash_set);
    return 1;
  }

  for (int kI = 0; kI < ELEMENTS / 2; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }

  int* good = HashSetAt(hash_set, 99);
  int* bad = HashSetAt(hash_set, 101);
  if (!(good != NULL && bad == NULL)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}