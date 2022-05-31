#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS '{'
#include <stdio.h>

int main() {
  printf("[Test38] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  // insert elements.
  for (char kI = '!'; kI != ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }
  if (!(0.70 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.71)) {
    HashSetFree(&hash_set);
    return 1;
  } //now hash_set contains 90 vals and has a capacity of 128

  // erase.
  for (char kI = '!'; kI != '+'; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.62 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.63)) {
    HashSetFree(&hash_set);
    return 1;
  } //now hash_set contains 80 vals and has a capacity of 128

  // erase.
  for (char kI = '+'; kI != ']'; ++kI) {
    int res = HashSetErase(hash_set, &kI);
    if (res != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.46 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.47)) {
    HashSetFree(&hash_set);
    return 1;
  } //now hash_set contains 30 vals and has a capacity of 64

  // HashSet free.
  HashSetFree(&hash_set);
  return 0;
}