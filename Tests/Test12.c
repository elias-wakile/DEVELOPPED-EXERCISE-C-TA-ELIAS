#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test12] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  for (double k_i = 0; k_i < ELEMENTS; ++k_i) {
    if (HashSetInsert(hash_set, &k_i) != 1){
        HashSetFree(&hash_set);
        return 1;
    }
  }


  double value_exists = 0;
  double value_not_exist = 101;
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