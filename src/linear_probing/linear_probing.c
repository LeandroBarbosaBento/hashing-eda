#include "linear_probing.h"

// Open the log-file in append mode and return it
FILE * nomeDaFuncaoLinear(char * file_path) {
    FILE * fp = fopen(file_path, "a");
    return fp;
}
