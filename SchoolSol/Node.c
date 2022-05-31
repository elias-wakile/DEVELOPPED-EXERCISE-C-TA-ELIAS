#include <stdio.h>
#include "Node.h"

/**
 * Allocates dynamically new vector element.
 * @param elem_copy_func func which copies the element stored in the vector
 * (returns dynamically allocated copy).
 * @param elem_cmp_func func which is used to compare elements.
 * @param elem_free_func func which frees elements.
 * @return pointer to dynamically allocated vector.
 * @if_fail return NULL.
 * You can assume all memory allocations will succeed;
 */
Node *NodeAlloc(NodeElemCpy elem_copy_func,
                NodeElemCmp elem_cmp_func,
                NodeElemFree elem_free_func){
  if ((!(elem_free_func)) || (!(elem_copy_func)) || (!(elem_cmp_func))){
    return NULL;
  }
  Node * curr_node = malloc(sizeof(struct Node));
  curr_node -> data = NULL;
  curr_node -> elem_cmp_func = elem_cmp_func;
  curr_node -> elem_copy_func = elem_copy_func;
  curr_node -> elem_free_func = elem_free_func;
  curr_node -> hashCount = 0;
  return curr_node;
}

/**
 * Frees a Node and the elements the Node itself allocated.
 * @param p_Node pointer to dynamically allocated pointer to Node.
 */
void NodeFree(Node **p_node){
  if ((!p_node) || (!(*p_node))){
    return;
  }
  if (((*p_node)->data)){
    (*p_node)->elem_free_func(&((*p_node)->data));
  }
  free(*p_node);
  *p_node = NULL;
}

/**
 * Gets a value and checks if the value is in the Node.
 * @param Node a pointer to Node.
 * @param value the value to look for.
 * @return 1 if the value is in the Node, 0 if there is another value in the node.
 * Returns -1 if the node is empty or if something went wrong during the check
 * You cannot assume anything about the input.
 */
int CheckNode(Node *node, void *value){
  if ((!node) || (!(node->data))){
    return -1;
  }
  return node->elem_cmp_func((node->data), value);
}

/**
 * Adds a new value to the data of the Node.
 * @param Node a pointer to Node.
 * @param value the value to be added to the Node.
 * @return 1 if the adding has been done successfully, 0 otherwise.
 * You cannot assume anything about the input.
 */
int SetNodeData(Node *node, void *value){
  if ((!node) || (!value)){
    return 0;
  }
  node -> elem_free_func (&(node -> data));
  node -> data = node -> elem_copy_func (value);
  return 1;
}


/**
 * Gets the value of the data of the Node.
 * @param Node a pointer to Node.
 * @return the value of the data of the Node.
 * You cannot assume anything about the input.
 */
Value* GetNodeData(Node *node){
  return node -> data;
}

/**
 * Deletes the data in the Node.
 * @param Node Node a pointer to Node.
 * You cannot assume anything about the input.
 */
void ClearNode(Node *node){
  if (!node){
    return;
  }
  node -> elem_free_func (&(node -> data));
  node -> data = NULL;
}

/**
 * Increments the number of the values that would have been hashed to the node
 * @param node the node to increment the number of the values.
 */
void IncHashCount(Node *node){
  if (!node){
    return;
  }
  node -> hashCount++;
}


/**
 * Decrements the number of the values that would have been hashed to the node
 * @param node the node to increment the number of the values.
 */
void DecHashCount(Node *node){
  if (!node){
    return;
  }
  node -> hashCount --;
}

/**
 * Gets the number of data values in the hashtable that would have been hashed
 * to this node
 * @param node The current node
 * @return the number of data in the hashtable that would have been hashed
 * to this node or -1 in case of illegal input;
 * You cannot assume anything about the input.
 */
int GetHashCount(Node *node){
  if (!node){
    return -1;
  }
  return node -> hashCount;
}

/**
 * Gets the number of data values in the hashtable that would have been hashed
 * to this node
 * @param node The current node
 * @param value The new value
 * You cannot assume anything about the input.
 */
void SetHashCount(Node *node, int value){
  if (!node){
    return;
  }
  node -> hashCount = value;
}

/**
 * Checks if the node is empty
 * @param node the node to be checked
 * @return 1 if empty, 0 if not;
 */
int CheckEmpty(Node *node){
  if (node -> data == NULL){
    return 1;
  }
  return 0;
}
