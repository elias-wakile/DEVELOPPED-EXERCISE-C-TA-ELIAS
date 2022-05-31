#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100

#include <stdio.h>

int main() {
  printf("[Test45] Running ...");

  // HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  // insert elements.
  for (int k_i = 0; k_i < ELEMENTS; k_i++) {
    HashSetInsert(hash_set, objectList[k_i]);
  }
  if (!(hash_set->size == 100 && hash_set->capacity == 256)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }


  for (int kI = 0; kI < ELEMENTS / 2; ++kI) {
    int conf_erase = HashSetErase(hash_set, objectList[kI]);
    if (conf_erase != 1) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(hash_set->size == 50 && hash_set->capacity == 128)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  for (int kI = ELEMENTS / 2; kI < ELEMENTS; ++kI) {
    int conf_erase = HashSetErase(hash_set, objectList[kI]);
    if (conf_erase != 1) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
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