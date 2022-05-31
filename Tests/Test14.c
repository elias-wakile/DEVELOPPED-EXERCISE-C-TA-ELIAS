#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test14] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  for (double k_i = 0; k_i < ELEMENTS; k_i++) {
    HashSetInsert(hash_set, &k_i);
  }

  double good = 99;
  int bad = 198;
  double *at_true = HashSetAt(hash_set, HashDouble(&good));
  double *at_false = HashSetAt(hash_set, bad);

  if ((*at_true != 99) || (at_false != NULL)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}