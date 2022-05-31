#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test48] Running ...");


  // HashSet alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  // insert elements.
  for (int kI = 0; kI < ELEMENTS; ++kI) {
    HashSetInsert(hash_set, objectList[kI]);
  }
  if (!(0.39 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.391)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  // erase.
  for (int kI = 0; kI < 10; ++kI) {
    int res = HashSetErase(hash_set, objectList[kI]);
    if (res != 1) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.351 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.352)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  // erase.
  for (int kI = 10; kI < 50; ++kI) {
    int res = HashSetErase(hash_set, objectList[kI]);
    if (res != 1) {
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }
  if (!(0.39 < HashSetGetLoadFactor(hash_set) && HashSetGetLoadFactor(hash_set) < 0.391)) {
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