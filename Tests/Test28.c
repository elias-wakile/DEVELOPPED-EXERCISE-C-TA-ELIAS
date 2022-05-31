#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test28] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashInt, IntKeyCpy, IntKeyCmp, IntKeyFree);

  // insert elements.
  for (int kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }
  if (!(0.39 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.391)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // erase.
  for (int kI = 0; kI < 10; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.351 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.352)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // erase.
  for (int kI = 10; kI < 50; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.39 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.391)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);
  return 0;
}