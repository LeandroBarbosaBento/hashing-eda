#ifndef __DOUBLE_HASHING
#define __DOUBLE_HASHING

#include <stdio.h>
#include <stdlib.h>

typedef struct double_item {
  int key;
  int is_empty;
} double_item_t;

typedef struct double_hashing {
  int total_access;
  int size;
  double_item_t *v;
  int number_of_keys;
} double_hashing_t;

double_hashing_t create_double_hashing(int n);

double_hashing_t * insert_double_hashing(double_hashing_t * x, int key);

double_hashing_t * get_avarage_double_hashing(double_hashing_t * x);

void show_data_double_hashing(double_hashing_t * x);

#endif