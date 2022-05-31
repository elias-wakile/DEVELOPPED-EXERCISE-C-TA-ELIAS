#include "Node.h"
#include <stdio.h>
#include "Utils.h"


int main() {
  printf("[Test5] Running ...");
  Node *first_try = NodeAlloc(NULL, NULL, NULL);

  Node *second_try = NodeAlloc(NULL, DoubleKeyCmp, DoubleKeyFree);

  Node *third_try = NodeAlloc(DoubleKeyCpy, NULL, DoubleKeyFree);

  Node *fourth_try = NodeAlloc(DoubleKeyCpy, DoubleKeyCmp, NULL);

  if ((first_try != NULL) || (second_try != NULL) || (third_try != NULL) || (fourth_try != NULL)){
      return 1;
  }

    return 0;
}
