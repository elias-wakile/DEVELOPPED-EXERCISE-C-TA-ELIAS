#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test47] Running ...");

  // HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  // insert elements.
  for (int kI = 0; kI < ELEMENTS; kI++) {
    HashSetInsert(hash_set, objectList[kI]);
  }
  if (!(hash_set->size == 100 && hash_set->capacity == 256)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  for (int kI = 0; kI < ELEMENTS / 2; ++kI) {
    int res = HashSetErase(hash_set, objectList[kI]);
    if (res != 1) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }

  SomeObject* good = HashSetAt(hash_set, 99);
  SomeObject* bad = HashSetAt(hash_set, 101);
  if (!(good != NULL && bad == NULL)) {
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