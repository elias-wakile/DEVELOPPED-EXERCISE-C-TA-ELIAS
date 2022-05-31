#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS '{'

#include <stdio.h>

int main() {
  printf("[Test35] Running ...");
  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashChar, CharKeyCpy, CharKeyCmp, CharKeyFree);

  // insert elements.
  for (char kI = '!'; kI != ELEMENTS; ++kI) {
    HashSetInsert(hash_set, &kI);
  }
  if (!(hash_set->size == 90 && hash_set->capacity == 128)) {
    HashSetFree(&hash_set);
    return 1;
  }


  for (int kI = '!'; kI != 'I'; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(hash_set->size == 50 && hash_set->capacity == 128)) {
    HashSetFree(&hash_set);
    return 1;
  }

  for (int kI = 'I'; kI != ELEMENTS; ++kI) {
    int conf_erase = HashSetErase(hash_set, &kI);
    if (conf_erase != 1) {
      HashSetFree(&hash_set);
      return 1;
    }
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  HashSetFree(&hash_set);

  return 0;
}