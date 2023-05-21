#ifndef __LINEAR_PROBING
#define __LINEAR_PROBING

#include <stdio.h>
#include <stdlib.h>

typedef struct linear_probing_item {
  int key;
  int is_empty;
} linear_probing_item_t;

typedef struct linear_probing_hashing {
  int total_access;
  int number_of_keys;
  int size;
  linear_probing_item_t *v;
} linear_probing_hashing_t;

linear_probing_hashing_t create_linear_probing_hashing(int n);

linear_probing_hashing_t * insert_linear_probing_hashing(linear_probing_hashing_t * x, int key);

float get_avarage_linear_probing_hashing(linear_probing_hashing_t * x);

void show_data_linear_probing_hashing(linear_probing_hashing_t * x);

#endif