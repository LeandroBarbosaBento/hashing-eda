#include "chaining.h"

chaining_hashing_t create_chaining_hashing(int n)
{
    chaining_hashing_t x;

    x.v = malloc( (n) * sizeof(chaining_item_t) );
    x.last_empty_position = n - 1;
    x.total_access = 0;
    x.size = n;
    x.number_of_keys = 0;
    
    for(int i = 0; i < n; i++){
        x.v[i].pointer = -1;
        x.v[i].is_empty = 1;
        x.v[i].key = -1;
    }

    return x;
}

int find_last_empty_position_chaining_hashing(chaining_hashing_t * x)
{
    for(int i = x->size - 1 ; i >= 0; i--)
    {
        if (x->v[i].is_empty) return i;
    }

    return -1;
}

chaining_hashing_t * insert_chaining_hashing(chaining_hashing_t * x, int key)
{

    if(x->last_empty_position < 0)
    {
        printf("The file is full, cannot continue the insertion!");
        return x;
    }

    x->number_of_keys++;

    int h;
    int pointer;

    h = key % x->size;

    if(x->v[h].is_empty)
    {
        x->v[h].is_empty = 0;
        x->v[h].key = key;
        x->v[h].pointer = -1;

        x->total_access++;
    }
    else {
        
        if(x->v[h].pointer == -1) pointer = h;
        else pointer = x->v[h].pointer;

        x->total_access++;

        while(1)
        {            
            x->total_access++;
            if( !x->v[pointer].is_empty && x->v[pointer].pointer == -1 )
            {
                x->v[pointer].pointer = x->last_empty_position;
                
                x->v[x->last_empty_position].key = key;
                x->v[x->last_empty_position].pointer = -1;
                x->v[x->last_empty_position].is_empty = 0;

                x->last_empty_position = find_last_empty_position_chaining_hashing(x);

                break;
            } 

            pointer = x->v[pointer].pointer;
        }
    }

    return x;
}

float get_avarage_chaining_hashing(chaining_hashing_t * x)
{
    return (float) x->total_access / x->number_of_keys;
}

void show_data_chaining_hashing(chaining_hashing_t * x)
{
    printf("\n***** CHAINING HASHING REPORT ***\n");
    printf("total_access: %d\n", x->total_access);
    printf("size: %d\n", x->size);
    printf("last_empty_position: %d\n", x->last_empty_position);
    printf("number_of_keys: %d\n", x->number_of_keys);

    for(int i = 0; i < x->size; i++){
        printf("position %d: k: %d | pt: %d | is_empty: %d\n", i,x->v[i].key,  x->v[i].pointer, x->v[i].is_empty);
    }
    
    if(x->total_access != 0)
        printf("avarage access: %.3f\n", get_avarage_chaining_hashing(x));
}

void menu_chaining_hashing()
{

}