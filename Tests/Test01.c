#include "Node.h"
#include <stdio.h>
#include "Utils.h"

int main() {
  printf("[Test1] Running ...");
  Node *node = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, DoubleKeyFree);

  if (!node) {
    return 1;
  }

  NodeFree(&node);
  return 0;
}
