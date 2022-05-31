#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test23] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  for (int k_i = 0; k_i < 6; ++k_i) {
    HashSetInsert(hash_set, &k_i);
  }

  if (hash_set->size != 6 && hash_set->capacity != 16) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}