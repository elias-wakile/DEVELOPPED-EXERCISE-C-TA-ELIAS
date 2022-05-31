#ifndef Node_H_
#define Node_H_

#include <stdlib.h>

/**
 * @typedef Value
 * A generic value in the hashtable
 */
typedef void * (Value);

/**
 * @typedef NodeElemCpy
 * Function which receive an element stored in the Node
 * and returns a dynamically allocated copy of it.
 */
typedef void *(*NodeElemCpy)(const void *);

/**
 * @typedef NodeElemCmp
 * Function which receives two elements stored in the Node
 * and returns 1 if they are equal, 0 otherwise.
 */
typedef int (*NodeElemCmp)(const void *, const void *);

/**
 * @typedef NodeElemFree
 * Function which receives a pointer to element stored in the
 * Node and frees it.
 */
typedef void (*NodeElemFree)(void **);

/**
 * @struct Node - a generic Node struct.
 * @param capacity - the capacity of the Node.
 * @param size - the current size of the Node.
 * @param data - the values stored inside the Node.
 * @param elem_copy_func - a function which copies (returns
 * a dynamically allocates copy) the elements stored in the Node.
 * @param elem_cmp_func - a function which compares the elements
 * stored in the Node.
 * @param elem_free_func - a function which frees the elements stored
 * in the Node.
 */
typedef struct Node {
  Value data;
  int hashCount;
  NodeElemCpy elem_copy_func;
  NodeElemCmp elem_cmp_func;
  NodeElemFree elem_free_func;
} Node;

/**
 * Allocates dynamically new Node element.
 * @param elem_copy_func func which copies the element stored in the Node (returns
 * dynamically allocated copy).
 * @param elem_cmp_func func which is used to compare elements stored in the Node.
 * @param elem_free_func func which frees elements stored in the Node.
 * @return pointer to dynamically allocated Node.
 * @if_fail return NULL.
 */
Node *NodeAlloc(NodeElemCpy elem_copy_func, NodeElemCmp elem_cmp_func, NodeElemFree elem_free_func);

/**
 * Frees a Node and the elements the Node itself allocated.
 * @param p_Node pointer to dynamically allocated pointer to Node.
 */
void NodeFree(Node **p_Node);

/**
 * Gets a value and checks if the value is in the Node.
 * @param Node a pointer to Node.
 * @param value the value to look for.
 * @return 1 if the value is in the Node, 0 otherwise.
 * Returns -1 if no such value in the Node
 *            or if something went wrong during the check
 * You cannot assume anything about the input.
 */
int CheckNode(Node *Node, void *value);

/**
 * Adds a new value to the data of the Node.
 * @param Node a pointer to Node.
 * @param value the value to be added to the Node.
 * @return 1 if the adding has been done successfully, 0 otherwise.
 */
int SetNodeData(Node *Node, void *value);

/**
 * Deletes the data in the Node.
 * @param Node Node a pointer to Node.
 */
void ClearNode(Node *Node);

/**
 * Gets the number of data values in the hashtable that would have been hashed
 * to this node
 * @param node The current node
 * @return the number of data in the hashtable that would have been hashed
 * to this node or -1 in case of illegal input;
 * You cannot assume anything about the input.
 */
int GetHashCount(Node *node);

#endif //Node_H_