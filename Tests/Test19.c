#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test19] Running ...");

  //HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  //insert elements.
  for (double kI = 0; kI < 20; ++kI) {
    HashSetInsert(hash_set, &kI);
  }

  if (hash_set->size != 20 && hash_set->capacity != 32) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}