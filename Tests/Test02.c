#include "Node.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test2] Running ...");

  Node *node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  if (!node) {
    return 1;
  }

  if (node -> data != NULL){
      NodeFree(&node);
      return 1;
  }

  if (GetHashCount(node) != 0){
      NodeFree(&node);
      return 1;
  }

  NodeFree(&node);
  return 0;
}
