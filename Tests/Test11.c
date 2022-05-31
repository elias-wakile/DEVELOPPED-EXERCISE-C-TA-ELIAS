#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test11] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}