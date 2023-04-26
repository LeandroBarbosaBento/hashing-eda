#include "double_hashing.h"

// Open the log-file in append mode and return it
double_hashing_t create_double_hashing(int n)
{
    double_hashing_t x;

    x.v = malloc( (n) * sizeof(double_item_t) );
    x.total_access = 0;
    x.size = n;
    x.number_of_keys = 0;
    
    printf("Teste n   : %d\n", n);

    for(int i = 0; i <= n; i++){
        x.v[i].is_empty = 1;
        x.v[i].key = -1;
    }

    return x;
}

void show_data_double_hashing(double_hashing_t * x)
{
    printf("total_access: %d\n", x->total_access);
    printf("size: %d\n", x->size);
    printf("number_of_keys: %d\n", x->number_of_keys);

    for(int i = 0; i < x->size; i++){
        printf("position %d: k: %d | is_empty: %d\n", i,x->v[i].key, x->v[i].is_empty);
    }
}