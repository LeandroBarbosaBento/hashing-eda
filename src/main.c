#include "chaining.h"
#include "double_hashing.h"
#include "linear_probing.h"



int main() {

    chaining_hashing_t chaining_hashing;

    int n = 11;

    chaining_hashing = create_chaining_hashing(n);

    printf("total_access: %d\n", chaining_hashing.total_access);
    printf("size: %d\n", chaining_hashing.size);
    printf("last_empty_position: %d\n", chaining_hashing.last_empty_position);
    printf("number_of_keys: %d\n", chaining_hashing.number_of_keys);

    for(int i = 0; i < n; i++){
        printf("position %d: k: %d | pt: %d | is_empty: %d\n", i,chaining_hashing.v[i].key,  chaining_hashing.v[i].pointer, chaining_hashing.v[i].is_empty);
    }

    printf("\n\nAPÓS INSERIR 5, 16 e 27: \n\n");

    insert_chaining_hashing(&chaining_hashing, 5);
    insert_chaining_hashing(&chaining_hashing, 16);
    insert_chaining_hashing(&chaining_hashing, 27);

    printf("total_access: %d\n", chaining_hashing.total_access);
    printf("size: %d\n", chaining_hashing.size);
    printf("last_empty_position: %d\n", chaining_hashing.last_empty_position);
    printf("number_of_keys: %d\n", chaining_hashing.number_of_keys);

    for(int i = 0; i < n; i++){
        printf("position %d: k: %d | pt: %d | is_empty: %d\n", i,chaining_hashing.v[i].key,  chaining_hashing.v[i].pointer, chaining_hashing.v[i].is_empty);
    }
    printf("\n");
}