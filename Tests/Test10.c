#include "Node.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test10] Running ...");
  Node* node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);
  if (!node) {
    return 1;
  }

  free(node->data);

  node->data = NULL;

  double number = -1.5;
  void *numberptr = (void *) &number;

  if (SetNodeData(node, numberptr) != 1){
      NodeFree(&node);
      return 1;
  }

  ClearNode(node);

  NodeFree(&node);

  return 0;
}

