#ifndef __HASHING_PERFEITO
#define __HASHING_PERFEITO

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct hashP_item hashP_item_t;

struct hashP_item {
    int *key;
    int a, b, m;
    int is_empty;
    hashP_item_t *vetor;
    int size;
} ;

//celula da tabela
//a, b, m, vetor com as celulas onde tera a, b e m de cada celula
//cada celula sera um vetor
//cada posicso da tabela hash tera um ponteiro indicando esse vetor 
//se houver colisoes, aikenta o m e copia os elementos pra um novo vetor
  

//achar a, b, npumeros aleatórios

typedef struct hashP {
    int a, b, m, primo;
    int total_access;
    int size;
    hashP_item_t *v;
    int last_empty_position;
    int number_of_keys;
} hashing_perfeito_t;

hashing_perfeito_t create_hashing_perfeito(int n, int maiorChave);

hashing_perfeito_t *insert_hashing_perfeito(hashing_perfeito_t *x, int key);

hashing_perfeito_t *get_avarage_hashing_perfeito(hashing_perfeito_t *x);

hashing_perfeito_t * update_lat_empty_position_hashing_perfeito(hashing_perfeito_t *x);

void show_data_hashing_perfeito(hashing_perfeito_t *x);

int numeroB(int numElem);

int numero(int numElem);

#endif