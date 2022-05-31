#include "Node.h"
#include <stdio.h>

int main() {
  printf("[Test6] Running ...");
  Node *node = NULL;

  NodeFree(&node);

  NodeFree(NULL);

  ClearNode(NULL);

  ClearNode(node);

  if ((GetHashCount(node) != -1) || (GetHashCount(NULL) != -1)){
    return 1;
  }

  if (SetNodeData(node, NULL) != 0 || SetNodeData(NULL, NULL)){
    return 1;
  }
  return 0;
}
