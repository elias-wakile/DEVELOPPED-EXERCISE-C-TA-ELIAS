#include "HashSet.h"
#include "Utils.h"
#include <stdio.h>
#define ELEMENTS 20

int main() {
  printf("[Test49] Running ...");

  //HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  //insert elements.
  for (int kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, objectList[kI]);
  }

  if (hash_set->size != ELEMENTS && hash_set->capacity != 32) {
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