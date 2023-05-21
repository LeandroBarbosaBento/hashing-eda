#include "double_hashing.h"

// Open the log-file in append mode and return it
double_hashing_t create_double_hashing(int n)
{
    double_hashing_t x;

    x.v = malloc( (n) * sizeof(double_item_t) );
    x.total_access = 0;
    x.size = n;
    x.number_of_keys = 0;
    
    for(int i = 0; i < n; i++){
        x.v[i].is_empty = 1;
        x.v[i].key = -1;
    }

    return x;
}

double_hashing_t * insert_double_hashing(double_hashing_t * x, int key)
{
    if(x->size == x->number_of_keys)
    {
        printf("The file is full, cannot continue the insertion!");
        return x;
    }

    x->number_of_keys++;

    int i;
    i = 0;

    int h_one;
    h_one = key % x->size;

    int h_two;
    h_two = key / x->size;
    if (key < x->size) h_two = 1;

    if(x->v[h_one].is_empty)
    {
        x->v[h_one].is_empty = 0;
        x->v[h_one].key = key;

        x->total_access++;
    }
    else
    {
        i = h_one;
        while(!x->v[i].is_empty)
        {
            i += h_two;
            if(i > x->size-1) i = i - x->size; 
            x->total_access++;

            if (i == h_one) break; 
        }

        if (i != h_one)
        {
            x->v[i].key = key;
            x->v[i].is_empty = 0;
        }

        
    }
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