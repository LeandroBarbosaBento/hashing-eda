#include "chaining.h"
#include "double_hashing.h"
#include "linear_probing.h"
#include "hashing_perfeito.h"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Use: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file;
    char *data = NULL;
    size_t size = 0;
    ssize_t charRead;
    int isFirst = 1;
    int hashing_file_size = 0;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("File oppening error.\n");
        return 1;
    }

    chaining_hashing_t chaining_hashing;
    double_hashing_t double_hashing;
    linear_probing_hashing_t linear_probing_hashing;
    hashing_perfeito_t hashing_perfeito;

    while ((charRead = getline(&data, &size, file)) != -1) {
        int number = (int) strtol(data, NULL, 10);
        if (isFirst)
        {
            hashing_file_size = number;
            isFirst = 0;
            break;
        }
    }

    chaining_hashing = create_chaining_hashing(hashing_file_size);
    double_hashing = create_double_hashing(hashing_file_size);
    linear_probing_hashing = create_linear_probing_hashing(hashing_file_size);
    hashing_perfeito =  create_hashing_perfeito(hashing_file_size, 100000);

    while ((charRead = getline(&data, &size, file)) != -1) {
        int number = (int) strtol(data, NULL, 10);
        insert_chaining_hashing(&chaining_hashing, number);
        insert_linear_probing_hashing(&linear_probing_hashing, number);
        insert_double_hashing(&double_hashing, number);
        insert_hashing_perfeito(&hashing_perfeito, number);
    }

    show_data_chaining_hashing(&chaining_hashing);
    show_data_linear_probing_hashing(&linear_probing_hashing);
    show_data_double_hashing(&double_hashing);
    show_data_hashing_perfeito(&hashing_perfeito);

    return 0;
}