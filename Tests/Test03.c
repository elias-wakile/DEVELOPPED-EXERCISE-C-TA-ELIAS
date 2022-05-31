#include "Node.h"
#include <stdio.h>
#include "Utils.h"

int main() {
  printf("[Test3] Running ...");
  Node *node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  if (!node) {
    return 1;
  }
  double number = 1;
  void *numberptr = (void *) &number;

  if (SetNodeData(node, numberptr) != 1){
      NodeFree(&node);
      return 1;
  }

  if (CheckNode(node, numberptr) != 1){
      NodeFree(&node);
      return 1;
  }

  NodeFree(&node);
  return 0;
}
