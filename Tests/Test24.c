#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test24] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  for (int k_i = 0; k_i < ELEMENTS; k_i++) {
    HashSetInsert(hash_set, &k_i);
  }

  int good = 99;
  int bad = 198;
  int *at_true = HashSetAt(hash_set, HashInt(&good));
  int *at_false = HashSetAt(hash_set, bad);

  if ((*at_true != 99) || (at_false != NULL)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}