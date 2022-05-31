#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test31] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}