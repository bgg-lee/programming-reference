#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]); 
    char *time_string = argv[2];
    int times[300]; 
    int times_size = 0;

    char *token = strtok(time_string, " ");
    while (token != NULL) {
        times[times_size++] = atoi(token);
        token = strtok(NULL, " ");
    }

    long long result = function3(n, times, times_size);
    printf("%lld\n", result);

    return 0;
}