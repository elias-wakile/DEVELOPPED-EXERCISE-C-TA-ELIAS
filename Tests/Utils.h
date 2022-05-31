#ifndef PAIRDOUBLECHAR_H_
#define PAIRDOUBLECHAR_H_

#include <stdlib.h>
#include <string.h>

/**
 * Copies the double value.
 */
void *DoubleKeyCpy(const void *key) {
  double *new_d = malloc(sizeof(double));
  *new_d = *((double *) key);
  return new_d;
}

/**
 * Copies the int value.
 */
void *IntKeyCpy(const void *value) {
  int *new_int = malloc(sizeof(int));
  *new_int = *((int *) value);
  return new_int;
}

/**
 * Copies the char key.
 */
void *CharKeyCpy(const void *key) {
  char *new_char = malloc(sizeof(char));
  *new_char = *((char *) key);
  return new_char;
}

/**
 * Compares the double value.
 */
int DoubleKeyCmp(const void *val_1,const void *val_2) {
  return *(double *) val_1 == *(double *) val_2;
}

/**
 * Compares the int value.
 */
int IntKeyCmp(const void *val_1,const void *val_2) {
  return *(int *) val_1 == *(int *) val_2;
}

/**
 * Compares the char key.
 */
int CharKeyCmp(const void *val_1,const void *val_2) {
  return *(char *) val_1 == *(char *) val_2;
}

/**
 * Frees the double value.
 */
void DoubleKeyFree(void **val) {
  if (val && *val) {
    free(*val);
    *val = NULL;
  }
}

/**
 * Frees the int value.
 */
void IntKeyFree(void **val) {
  if (val && *val) {
    free(*val);
    *val = NULL;
  }
}

/**
 * Frees the char key.
 */
void CharKeyFree(void **val) {
  if (val && *val) {
    free(*val);
    *val = NULL;
  }
}

/**
 * @id the id parameter of the object
 */
typedef struct SomeObject {
  int id;
} SomeObject;

SomeObject* ObjectAlloc(int id){
  SomeObject *temp = malloc(sizeof(SomeObject));
  temp->id = id;
  return temp;
}

/**
 * Copies the object value.
 */
void *ObjectKeyCpy(const void *key) {
  SomeObject *temp = (SomeObject *) key;
  return (void *) ObjectAlloc(temp -> id);
}

/**
 * Compares the object value.
 */
int ObjectKeyCmp(const void *val_1,const void *val_2) {
  SomeObject *temp1 = (SomeObject *) val_1;
  SomeObject *temp2 = (SomeObject *) val_2;
  return ((temp1->id) == (temp2->id));
}


/**
 * Frees the object value.
 */
void ObjectKeyFree(void **val) {
  if (val && (*val)) {
    SomeObject **temp = (SomeObject **) val;
    free(*temp);
    *temp = NULL;
  }
}

/**
 * Object simple hash func.
 */
size_t HashObject(void *elem){
  size_t hash = (size_t) (((SomeObject *) elem)->id);
  return hash;
}


#endif //PAIRDOUBLECHAR_H_
