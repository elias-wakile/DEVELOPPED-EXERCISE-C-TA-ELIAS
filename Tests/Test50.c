#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test50] Running ...");

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

  if (hash_set->size != ELEMENTS) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    HashSetFree(&hash_set);
    return 1;
  }

  unsigned int old_cap = hash_set->capacity;

  HashSetClear(hash_set);

  for (size_t k_i = 0; k_i < hash_set->capacity; ++k_i) {
    if ((hash_set->NodesList[k_i]->data != NULL) || (hash_set->NodesList[k_i]->hashCount != 0)) {
      for (int kI = 0; kI < ELEMENTS; ++kI) {
        ObjectKeyFree((void **) &objectList[kI]);
      }
      HashSetFree(&hash_set);
      return 1;
    }
  }
  
  if ((hash_set->capacity != old_cap) || (hash_set->size != 0) || (HashSetGetLoadFactor(hash_set) != 0)){
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
}
