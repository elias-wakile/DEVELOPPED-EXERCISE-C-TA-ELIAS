#include "Hash.h"
#include "HashSet.h"
#include "Utils.h"

#define ELEMENTS 100
#include <stdio.h>

int main() {
  printf("[Test44] Running ...");

  // HashMap alloc.
  HashSet *hash_set = HashSetAlloc(HashObject, ObjectKeyCpy, ObjectKeyCmp, ObjectKeyFree);

  SomeObject* objectList[ELEMENTS];
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    objectList[k_i] = ObjectAlloc(k_i);
  }

  for (int k_i = 0; k_i < ELEMENTS; k_i++) {
    HashSetInsert(hash_set, objectList[k_i]);
  }

  int good = 99;
  int bad = 198;
  SomeObject *at_true = HashSetAt(hash_set, good);
  SomeObject *at_false = HashSetAt(hash_set, bad);

  if ((at_true->id != 99) || (at_false != NULL)) {
    for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
      ObjectKeyFree((void **) &objectList[k_i]);
    }
    return 1;
  }

  // HashMap free.
  for (int k_i = 0; k_i < ELEMENTS; ++k_i) {
    ObjectKeyFree((void **) &objectList[k_i]);
  }
  HashSetFree(&hash_set);

  return 0;
}