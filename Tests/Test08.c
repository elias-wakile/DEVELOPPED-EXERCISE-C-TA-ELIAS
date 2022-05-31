#include "Node.h"
#include "Utils.h"
#include <stdio.h>

int main() {
  printf("[Test8] Running ...");
  Node* node = NodeAlloc(CharKeyCpy, CharKeyCmp, CharKeyFree);
  if (!node) {
      NodeFree(&node);
      return 1;
  }

  char character = 'a';
  void *characterptr = (void *) &character;

  if (SetNodeData(node, characterptr) != 1){
      NodeFree(&node);
      return 1;
  }

  if (CheckNode(node, characterptr) != 1){
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
