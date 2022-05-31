#include "Node.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test9] Running ...");
  Node* node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);
  if (!node) {
    return 1;
  }

  free(node->data);

  node->data = NULL;

  ClearNode(node);

  NodeFree(&node);

  return 0;
}

