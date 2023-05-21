#include "linear_probing.h"

linear_probing_hashing_t create_linear_probing_hashing(int n)
{
    linear_probing_hashing_t x;

    x.v = malloc( (n) * sizeof(linear_probing_item_t) ); 
    x.total_access = 0;
    x.size = n;
    x.number_of_keys = 0;

    for(int i = 0; i < n; i++){
        x.v[i].is_empty = 1;
        x.v[i].key = -1;
    }

    return x;
}

linear_probing_hashing_t * insert_linear_probing_hashing(linear_probing_hashing_t * x, int key)
{
    if(x->size == x->number_of_keys)
    {
        printf("The file is full, cannot continue the insertion!");
        return x;
    }

    x->number_of_keys++;

    int h, i=0;

    h = key % x->size;

    if(x->v[h].is_empty)
    {
        x->v[h].is_empty = 0;
        x->v[h].key = key;
        x->total_access++;
    }
    else {
        i=h;

        while(!x->v[i].is_empty)
        {
            i++;
            if(i > x->size-1) i=0; 
            x->total_access++;
        }

        if (i != h)
        {
            x->v[i].key = key;
            x->v[i].is_empty = 0;
        }

    }
    
    return x;
}

float get_avarage_linear_probing_hashing(linear_probing_hashing_t * x){
    return (float) x->total_access / x->number_of_keys;
}


void show_data_linear_probing_hashing(linear_probing_hashing_t * x)
{
    printf("\n***** LINEAR PROBING REPORT ***\n");
    printf("total_access: %d\n", x->total_access);
    printf("size: %d\n", x->size);
    printf("number_of_keys: %d\n", x->number_of_keys);

    for(int i = 0; i < x->size; i++){
        printf("position %d: k: %d | is_empty: %d\n", i,x->v[i].key, x->v[i].is_empty);
    }

    if(x->total_access != 0)
        printf("avarage access: %.3f\n", get_avarage_linear_probing_hashing(x));
}


void menu_linear_probing_hashing()
{

}
