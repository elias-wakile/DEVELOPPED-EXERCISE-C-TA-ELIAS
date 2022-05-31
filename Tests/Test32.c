#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS '{'
#include <stdio.h>

int main() {
  printf("[Test32] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  for (char k_i = '!'; k_i != ELEMENTS; ++k_i) {
    if (HashSetInsert(hash_set, &k_i) != 1){
        HashSetFree(&hash_set);
        return 1;
    }
  }


  char value_exists = '@';
  char value_not_exist = '~';
  int contains_val_1 = HashSetContainsValue(hash_set, &value_exists);
  int contains_val_2 = HashSetContainsValue(hash_set, &value_not_exist);

  if (!(contains_val_1 == 1 && contains_val_2 == 0)) {
      HashSetFree(&hash_set);
        return 1;
  }

  // HashMap free.
  HashSetFree(&hash_set);
  return 0;
}