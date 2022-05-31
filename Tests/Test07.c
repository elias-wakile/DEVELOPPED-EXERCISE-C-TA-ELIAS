#include "Node.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test7] Running ...");
  Node* node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);
  if (!node) {
    return 1;
  }

  double number = -1.5;
  void *numberptr = (void *) &number;

  if (SetNodeData(node, numberptr) != 1){
      NodeFree(&node);
      return 1;
  }

  if (CheckNode(node, numberptr) != 1){
      NodeFree(&node);
      return 1;
  }

  ClearNode(node);

  if (node->data != NULL){
      NodeFree(&node);
      return 1;
  }

  NodeFree(&node);
  return 0;
}
