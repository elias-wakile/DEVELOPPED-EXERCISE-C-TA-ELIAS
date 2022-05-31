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
#endif //PAIRDOUBLECHAR_H_
