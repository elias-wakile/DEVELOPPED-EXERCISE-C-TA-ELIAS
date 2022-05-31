#include "HashSet.h"
#include "Node.c"
#define FAIL 0
#define SUCCESS 1
#define ILLEGAL_VALUE -1


/**
 * This function gets all the values from the vector curr_vec and places them
 * inside the HashSet and frees the vector
 * @param hash_set The HashSet in which we insert the Values from the vector
 * @param curr_vec The vector containing the Values we wish to move to the set
 */
void ReHashSet(HashSet * hash_set, unsigned int new_capacity){
  hash_set->size = 0;
  unsigned int oldCap = hash_set -> capacity;
  hash_set -> capacity = new_capacity;
  Node** tempList = hash_set -> NodesList;
  hash_set -> NodesList = malloc(hash_set -> capacity * sizeof(struct Node *));
  for (unsigned int i = 0; i < hash_set -> capacity; i++){
    hash_set -> NodesList[i] = NodeAlloc(hash_set -> value_cpy,
                                         hash_set -> value_cmp,
                                         hash_set -> value_free);
  }
  for (unsigned int i = 0 ; i < oldCap ; i++){
      if (CheckEmpty(tempList[i]) == FAIL){
          HashSetInsert(hash_set, GetNodeData(tempList[i]));
          NodeFree(&tempList[i]);
      }
  }
  free(tempList);
}

/**
 * This function increases the HashSet capacity once the maximum load factor has
 * exceeded the maximum load factor and rehashes the HashSet By moving the values
 * into a vector, expanding the HashSet, and then moving back the values back to
 * the HashSet
 * @param hash_set : the set to increase capacity
 */
void UpdateHashSetSizeDiminue(HashSet* hash_set){
  if ((HashSetGetLoadFactor(hash_set) > HASH_SET_MIN_LOAD_FACTOR) ||
      (hash_set -> capacity == SUCCESS)){
    return;
  }
  ReHashSet(hash_set, hash_set -> capacity / HASH_SET_GROWTH_FACTOR);
}
/**
 * This function increases the HashSet capacity once the maximum load factor has
 * receded the maximum load factor and rehashes the HashSet By moving the values
 * into a vector, expanding the HashSet, and then moving back the values back to
 * the HashSet
 * @param hash_set : the set to increase capacity
 */
void UpdateHashSetSizeAugment(HashSet* hash_set) {
  if (HashSetGetLoadFactor(hash_set) < HASH_SET_MAX_LOAD_FACTOR){
    return;
  }
  ReHashSet(hash_set, hash_set -> capacity * HASH_SET_GROWTH_FACTOR);
}


/**
 * Allocates dynamically new hash set element.
 * @param hash_func a function which "hashes" keys.
 * @param Value_cpy a function which copies Values.
 * @param Value_cmp a function which compares Values.
 * @param Value_free a function which frees Values.
 * @return pointer to dynamically allocated HashSet.
 * @if_fail return NULL.
 * You can assume all memory allocations will succeed and that if the functions
 * will be provided they will function correctly but you cannot assume you will
 * be provided with all the functions.
 */
HashSet *HashSetAlloc(
    HashFunc hash_func, HashSetValueCpy Value_cpy,
    HashSetValueCmp Value_cmp, HashSetValueFree Value_free){
  if ((!hash_func) || (!Value_cpy) || (!Value_cmp) ||(!Value_free)){
    return NULL;
  }
  HashSet * curr_set = malloc(sizeof(struct HashSet));
  curr_set -> capacity = HASH_SET_INITIAL_CAP;
  curr_set -> size = 0;
  curr_set -> NodesList = calloc(curr_set -> capacity , sizeof(struct Node *));
  for (unsigned int i = 0; i < curr_set -> capacity; i++){
    curr_set -> NodesList[i] = NodeAlloc(Value_cpy, Value_cmp, Value_free);
  }
  curr_set -> hash_func = hash_func;
  curr_set -> value_cpy = Value_cpy;
  curr_set -> value_cmp = Value_cmp;
  curr_set -> value_free = Value_free;
  return curr_set;
}

/**
 * Frees a vector and the elements the vector itself allocated.
 * @param p_hash_set pointer to dynamically allocated pointer to hash_set.
 * You cannot assume anything.
 */
void HashSetFree(HashSet **p_hash_set){
  for (unsigned int i = 0; i < (*p_hash_set)->capacity; i++){
    if ((*p_hash_set)->NodesList[i]) {
      NodeFree(&((*p_hash_set)->NodesList[i]));
    }
  }
  if ((*p_hash_set)->NodesList != NULL) {
    free((*p_hash_set)->NodesList);
  }
  free(*p_hash_set);
  *p_hash_set = NULL;
}

/**
 * Inserts a new Value to the hash set if the value is not in the hash set.
 * The function inserts *new*, *copied*, *dynamically allocated* Value,
 * NOT the Value it receives as a parameter.
 * @param hash_set the hash set to be inserted with new element.
 * @param Value a Value the hash set would contain.
 * @return returns 1 for successful insertion, 0 otherwise.
 */
int HashSetInsert(HashSet *hash_set, Value value) {
  if (HashSetContainsValue(hash_set, value) == SUCCESS){
    return FAIL;
  }
  unsigned int hash_index = (hash_set -> hash_func (value)) % hash_set->capacity;
  unsigned int curr_hash_index;
  for (unsigned int i = 0; i < hash_set->capacity ; i++){
    curr_hash_index = (hash_index + ((i + (i * i)) / 2)) % hash_set->capacity;
    if (CheckEmpty((hash_set -> NodesList[curr_hash_index])) == SUCCESS){
      SetNodeData(hash_set -> NodesList[curr_hash_index],value);
      IncHashCount((hash_set -> NodesList[hash_index]));
      hash_set->size++;
      UpdateHashSetSizeAugment(hash_set);
      return SUCCESS;
    }
  }
  return FAIL;
}

/**
 * The function checks if the given value exists in the hash set.
 * @param hash_set a hash set.
 * @param value the value to be checked.
 * @return 1 if the value is in the hash set, 0 otherwise.
 */
int HashSetContainsValue(HashSet *hash_set, Value value) {
  unsigned int hash_index = (hash_set -> hash_func (value)) % hash_set->capacity;
  if (GetHashCount(hash_set -> NodesList[hash_index % (hash_set -> capacity)]) == FAIL){
    return FAIL;
  }
  unsigned int curr_hash_index;
  for (unsigned int i = 0; i < hash_set->capacity ; i++){
    curr_hash_index = (hash_index + ((i + (i * i)) / 2)) % hash_set->capacity;
    if (CheckNode((hash_set -> NodesList[curr_hash_index]), value) == SUCCESS){
      return SUCCESS;
    }
  }
  return FAIL;
}

/**
 * The function erases the Value.
 * @param hash_set a hash set.
 * @param key a key of the Value to be erased.
 * @return 1 if the erasing was done successfully, 0 otherwise.
 */
int HashSetErase(HashSet *hash_set, Value value){
  if (HashSetContainsValue(hash_set, value) == FAIL){
    return FAIL;
  }
  hash_set->size--;
  unsigned int hash_index = (hash_set -> hash_func (value)) % hash_set->capacity;
  DecHashCount(hash_set -> NodesList[hash_index % hash_set->capacity]);
  unsigned int curr_hash_index;
  for (unsigned int i = 0; i < hash_set->capacity ; i++){
    curr_hash_index = (hash_index + ((i + (i * i)) / 2)) % hash_set->capacity;
    if (CheckNode((hash_set -> NodesList[curr_hash_index]), value) == SUCCESS){
      ClearNode((hash_set -> NodesList[curr_hash_index]));
      DecHashCount(hash_set -> NodesList[curr_hash_index]);
      UpdateHashSetSizeDiminue(hash_set);
      return SUCCESS;
    }
  }
  return FAIL;
}

/**
 * This function returns the load factor of the hash set.
 * @param hash_set a hash set.
 * @return the hash set's load factor, -1 if the function failed.
 */
double HashSetGetLoadFactor(HashSet *hash_set){
  if ((!hash_set) || ((hash_set -> capacity) == 0)){
    return ILLEGAL_VALUE;
  }
  double load_fac = (double) ( ((double) hash_set -> size) /
      ((double) (hash_set->capacity)));
  return load_fac;
}


/**
 * This function deletes all the elements in the hash set.
 * The hash set capacity ought be conserved
 * @param hash_set a hash set to be cleared.
 */
void HashSetClear(HashSet *hash_set){
  for (unsigned int index = 0; index < hash_set->capacity ; index++){
    ClearNode(hash_set -> NodesList[index]);
    SetHashCount(hash_set -> NodesList[index], 0);
  }
  hash_set -> size = 0;
}

/**
 * This function gets the element in the hashset hashed to the indexed value
 * @param hash_set the hashset
 * @param value the value for whose value we look for
 * @return the element in the hashset hashed to the indexed value
 * NULL in case of an error or an empty node or an unexpected value
 */
Value HashSetAt(HashSet *hash_set, int value){
  if ((!hash_set) || (value < 0) || ((unsigned int) value >= hash_set->capacity) || (!hash_set->NodesList)){
    return NULL;
  }
  return GetNodeData(hash_set->NodesList[value]);
}

