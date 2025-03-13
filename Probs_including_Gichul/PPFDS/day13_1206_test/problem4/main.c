#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    char* s = argv[1];
    int k = atoi(argv[2]);

    char* answer = function4(s, k);
    printf("%s\n", answer);

    free(answer);
    return 0;
}