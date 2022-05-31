#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test39] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  //insert elements.
  for (char kI = '!'; kI != '5'; ++kI) {
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