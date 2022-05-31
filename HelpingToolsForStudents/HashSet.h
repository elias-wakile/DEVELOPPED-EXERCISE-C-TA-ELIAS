#ifndef HASHSET_H_
#define HASHSET_H_

#include <stdlib.h>
#include "Node.h"

/**
 * @def HASH_SET_INITIAL_CAP
 * The initial capacity of the hash set.
 * It means, the initial number of <b> Nodes </b> the hash set has.
 */
#define HASH_SET_INITIAL_CAP 16

/**
 * @def HASH_SET_GROWTH_FACTOR
 * The growth factor of the hash set.
 * Example: hash_set(size=16),
 *          hash_set.add([16 elements]) ->
 *          hash_set(size=32)
 */
#define HASH_SET_GROWTH_FACTOR 2

/**
 * @def hash_set_MIN_LOAD_FACTOR
 * The minimal load factor the hash set can be in.
 * Example: if the hash_set capacity is 16,
 * and it has 4 elements in it (size is 4),
 * if an element is erased, the load factor drops below 0.25,
 * so the hash set should be minimized (to 8 Nodes).
 */
#define HASH_SET_MIN_LOAD_FACTOR 0.25

/**
 * @def hash_set_MAX_LOAD_FACTOR
 * The maximal load factor the hash set can be in.
 * Example: if the hash_set capacity is 16,
 * and it has 12 elements in it (size is 12),
 * if another element is added, the load factor goes above 0.75,
 * so the hash set should be extended (to 32 Nodes).
 */
#define HASH_SET_MAX_LOAD_FACTOR 0.75

/**
 * @typedef HashFunc
 * This type of function receives a KeyT and returns
 * a representational number of it.
 * Example: lets say we have a Value ('Joe', 78) that we want to store in the hash set,
 * the key is 'Joe' so it determines the Node List in the hash set,
 * his index would be:  size_t ind = HashFunc('Joe') & (capacity - 1);
 */
typedef size_t (*HashFunc)(Value);

/**
 * @typedef HashSetValueCpy
 * A copy function for the Values stored in the Nodes (which are stored in the hash set).
 */
typedef void *(*HashSetValueCpy)(const void *);

/**
 * @typedef HashSetValueCmp
 * A compare function for the Values stored in the Nodes (which are stored in the hash set).
 */
typedef int (*HashSetValueCmp)(const void *, const void *);

/**
 * @typedef HashSetValueFree
 * A free function for the Values stored in Nodes (which are stored in the hash set).
 */
typedef void (*HashSetValueFree)(void **);

/**
 * @struct HashSet
 * @param NodeList dynamic array of Nodes which stores the values.
 * @param size the number of elements (Values) stored in the hash set.
 * @param capacity the number of Node Lists in the hash set.
 * @param hash_func a function which "hashes" keys.
 * @param Value_cpy a function which copies Values.
 * @param Value_cmp a function which compares Values.
 * @param Value_free a function which frees Values.
 */
typedef struct HashSet {
  Node **NodesList;
  unsigned int size;
  unsigned int capacity; // num of nodes.
  HashFunc hash_func;
  HashSetValueCpy value_cpy;
  HashSetValueCmp value_cmp;
  HashSetValueFree value_free;
} HashSet;

/**
 * Allocates dynamically new hash set element.
 * @param hash_func a function which "hashes" keys.
 * @param Value_cpy a function which copies Values.
 * @param Value_cmp a function which compares Values.
 * @param Value_free a function which frees Values.
 * @return pointer to dynamically allocated HashSet.
 * @if_fail return NULL.
 * You can assume memory allocations will succeed
 */
HashSet *HashSetAlloc(
    HashFunc hash_func, HashSetValueCpy value_cpy,
    HashSetValueCmp value_cmp, HashSetValueFree value_free);

/**
 * Frees a Node and the elements the Node itself allocated.
 * @param p_hash_set pointer to dynamically allocated pointer to hash_set.
 * You cannot assume anything
 */
void HashSetFree(HashSet **p_hash_set);

/**
 * Inserts a new Value to the hash set.
 * The function inserts *new*, *copied*, *dynamically allocated* Value,
 * NOT the Value it receives as a parameter.
 * @param hash_set the hash set to be inserted with new element.
 * @param Value a Value the hash set would contain.
 * @return returns 1 for successful insertion, 0 otherwise.
 */
int HashSetInsert(HashSet *hash_set, Value Value);

/**
 * The function checks if the given value exists in the hash set.
 * @param hash_set a hash set.
 * @param value the value to be checked.
 * @return 1 if the value is in the hash set, 0 otherwise.
 */
int HashSetContainsValue(HashSet *hash_set, Value value);

/**
 * The function erases the Value associated with key.
 * @param hash_set a hash set.
 * @param key a key of the Value to be erased.
 * @return 1 if the erasing was done successfully, 0 otherwise.
 */
int HashSetErase(HashSet *hash_set, Value value);

/**
 * This function returns the load factor of the hash set.
 * @param hash_set a hash set.
 * @return the hash set's load factor, -1 if the function failed.
 */
double HashSetGetLoadFactor(HashSet *hash_set);

/**
 * This function deletes all the elements in the hash set.
 * @param hash_set a hash set to be cleared.
 * Capacity ought be conserved
 */
void HashSetClear(HashSet *hash_set);

/**
 * This function gets the element in the hashset hashed to the indexed value
 * @param hash_set the hashset
 * @param value the value for whose value we look for
 * @return the element in the hashset hashed to the indexed value
 * NULL in case of an error or an empty node or an unexpected value
 */
Value HashSetAt(HashSet *hash_set, int value);

#endif //HASHSET_H_
