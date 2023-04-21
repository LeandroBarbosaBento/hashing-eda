#include "double_hashing.h"

// Open the log-file in append mode and return it
FILE * nomeDaFuncaoDouble(char * file_path) {
    FILE * fp = fopen(file_path, "a");
    return fp;
}
