#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>
#define ELEMENTS 6

int main() {
  printf("[Test43] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  for (int k_i = 0; k_i < 6; ++k_i) {
    HashSetInsert(hash_set, objectList[k_i]);
  }

  if (hash_set->size != 6 && hash_set->capacity != 16) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  // HashSet free.
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    ObjectKeyFree((void **) &objectList[k_i]);
  }
  HashSetFree(&hash_set);

  return 0;
}