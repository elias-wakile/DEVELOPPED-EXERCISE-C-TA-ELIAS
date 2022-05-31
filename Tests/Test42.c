#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test42] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    if (HashSetInsert(hash_set, objectList[k_i]) != 1){
        HashSetFree(&hash_set);
        for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
          ObjectKeyFree((void **) &objectList[k_i]);
        }
        return 1;
    }
  }

  SomeObject* value_not_exist = ObjectAlloc(ELEMENTS);
  int contains_val_1 = HashSetContainsValue(hash_set, objectList[0]);
  int contains_val_2 = HashSetContainsValue(hash_set, value_not_exist);

  if (!(contains_val_1 == 1 && contains_val_2 == 0)) {
      HashSetFree(&hash_set);
      for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
        ObjectKeyFree((void **) &objectList[k_i]);
      }
      return 1;
  }

  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    ObjectKeyFree((void **) &objectList[k_i]);
  }

  // HashMap free.
  HashSetFree(&hash_set);
  return 0;
}