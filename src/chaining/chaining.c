#include "chaining.h"

// Open the log-file in append mode and return it
FILE * nomeDaFuncaoChaining(char * file_path) {
    FILE * fp = fopen(file_path, "a");
    return fp;
}
