#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test21] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}