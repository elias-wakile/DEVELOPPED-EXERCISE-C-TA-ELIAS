#include <stdio.h>
#include <assert.h>
#include "Utils.h"
#include "Node.h"
#include "Hash.h"
#include "HashSet.h"


void *ElemCpy(const void *elem) {
  int *a = malloc(sizeof(int));
  *a = *((int *) elem);
  return a;
}

int ElemCmp(const void *elem_1, const void *elem_2) {
  return *((const int *) elem_1) == *((const int *) elem_2);
}

void ElemFree(void **elem) {
  free(*elem);
}


int main() {
  printf("[Pre-Submission] 3 ...\n");
  printf("[Pre-Submission] 2 ...\n");
  printf("[Pre-Submission] 1 ...\n");
  printf("[Pre-Submission] Ignition ...\n");

  printf("[Pre-Submission] Creating Node of Ints ...\n");
  Node *node = NodeAlloc(ElemCpy, ElemCmp, ElemFree);

  printf("[Pre-Submission] Free Node ...\n");
  NodeFree(&node);


  printf("[Pre-Submission] Creating HashSet of {Char : Int} ...\n");
  HashSet *hash_set = HashSetAlloc(HashDouble, DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  printf("[Pre-Submission] Inserting Pairs to HashSet ...\n");
  for (double kI = 0; kI < 8; ++kI) {
    HashSetInsert(hash_set, &kI);
  }

  printf("[Pre-Submission] Check hash-map size with assert ...\n");
  assert(hash_set->size == 8 && "Incorrect size of hash-map.");
  assert(hash_set->capacity == 16 && "Incorrect capacity of hash-map.");


  printf("[Pre-Submission] Free hash map ...\n");
  HashSetFree(&hash_set);

  printf("[Pre-Submission] all tests ended.\n");

  return 0;
}