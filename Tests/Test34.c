#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS '{'
#include <stdio.h>

int main() {
  printf("[Test34] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  for (char k_i = '!'; k_i != ELEMENTS; k_i++) {
    HashSetInsert(hash_set, &k_i);
  }

  char good = '@';
  char bad = '~';
  char *at_true = HashSetAt(hash_set, HashChar(&good));
  char *at_false = HashSetAt(hash_set, HashChar(&bad));

  if ((*at_true != '@') || (at_false != NULL)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashMap free.
  HashSetFree(&hash_set);

  return 0;
}