#ifndef __CHAINING
#define __CHAINING

#include <stdio.h>
#include <stdlib.h>

typedef struct chaining_item {
  int key;
  int pointer;
  int is_empty;
} chaining_item_t;

typedef struct chaining_hashing {
  int total_access;
  int size;
  chaining_item_t *v;
  int last_empty_position;
} chaining_hashing_t;

chaining_hashing_t create_chaining_hashing(int n);

chaining_hashing_t * insert_chaining_hashing(chaining_hashing_t * x, int key);

chaining_hashing_t * get_avarage_chaining_hashing(chaining_hashing_t * x);

chaining_hashing_t * update_lat_empty_position_chaining_hashing(chaining_hashing_t * x);

int find_last_empty_position_chaining_hashing(chaining_hashing_t * x);

void menu_chaining_hashing();


#endif