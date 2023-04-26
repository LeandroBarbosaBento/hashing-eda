#include "chaining.h"
#include "double_hashing.h"
#include "linear_probing.h"



int main() {

    /***********CHAINING HASHING*********/

    /* chaining_hashing_t chaining_hashing;

    int n = 11;

    chaining_hashing = create_chaining_hashing(n);

    show_data_chaining_hashing(&chaining_hashing);

    insert_chaining_hashing(&chaining_hashing, 5);
    insert_chaining_hashing(&chaining_hashing, 16);
    insert_chaining_hashing(&chaining_hashing, 27);

    printf("\n\nAPÓS INSERIR 5, 16 e 27: \n\n");

    show_data_chaining_hashing(&chaining_hashing);

    printf("\n"); */



    

    /* double_hashing_t double_hashing;

    int n = 11;

    double_hashing = create_double_hashing(n);

    show_data_double_hashing(&double_hashing);

    insert_double_hashing(&double_hashing, 5);
    //insert_double_hashing(&double_hashing, 16);
    insert_double_hashing(&double_hashing, 27);

    printf("\n\nAPÓS INSERIR 5, 16 e 27: \n\n");

    show_data_double_hashing(&double_hashing);

    printf("\n"); */

    /***********LINEAR PROBING HASHING*********/

    int n = 11;
    linear_probing_hashing_t linear_probing_hashing;

    printf("Criando linear hashing...\n");

    linear_probing_hashing = create_linear_probing_hashing(n);

    show_data_linear_probing_hashing(&linear_probing_hashing);

    insert_linear_probing_hashing(&linear_probing_hashing, 5);
    insert_linear_probing_hashing(&linear_probing_hashing, 8);
    insert_linear_probing_hashing(&linear_probing_hashing, 19);
    insert_linear_probing_hashing(&linear_probing_hashing, 30);
    insert_linear_probing_hashing(&linear_probing_hashing, 52);

    printf("\nInseriu 5, 8, 19, 30, 52 \n");

    show_data_linear_probing_hashing(&linear_probing_hashing);
}