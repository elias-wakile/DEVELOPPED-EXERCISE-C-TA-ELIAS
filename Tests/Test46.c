#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test46] Running ...");

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

  for (int kI = ELEMENTS; kI < ELEMENTS + 5; ++kI) {
    SomeObject* tempList[5];
    for (int k_i = ELEMENTS; k_i < ELEMENTS + 5; ++k_i) {
      tempList[k_i - ELEMENTS] = ObjectAlloc(k_i);
    }
    int res = HashSetErase(hash_set, tempList[kI - ELEMENTS]);
    if (res != 0) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      for (int k_i = 0; k_i < 5; ++k_i) {
        ObjectKeyFree((void **) &tempList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
    for (int k_i = 0; k_i < 5; ++k_i) {
      ObjectKeyFree((void **) &tempList[k_i]);
    }
  }

  for (int kI = ELEMENTS - 5; kI < ELEMENTS; ++kI) {
    int res = HashSetInsert(hash_set, objectList[kI]);
    if (res != 0) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }

  for (int kI = 0; kI < ELEMENTS; ++kI) {
    HashSetErase(hash_set, objectList[kI]);
  }

  if (!(hash_set->size == 0 && hash_set->capacity == 1)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;  }

  // HashSet free.
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    ObjectKeyFree((void **) &objectList[k_i]);
  }
  HashSetFree(&hash_set);

  return 0;
}