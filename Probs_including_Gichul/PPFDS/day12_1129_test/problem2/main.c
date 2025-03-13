#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int main(int argc, char* argv[]) {
    int N, M;
    sscanf(argv[1], "%d %d", &N, &M);

    int orders[MAX_CUSTOMERS][MAX_SUSHI_TYPES] = {0};
    int sushi_sequence[MAX_SUSHI_TYPES];
    int sushi_eaten[MAX_CUSTOMERS] = {0};

    int arg_index = 2;
    for (int i = 0; i < N; i++) {
        char* token = strtok(argv[arg_index], " ");
        while (token != NULL) {
            int sushi_type = atoi(token);
            orders[i][sushi_type] = 1; //  이 놈 집중
            token = strtok(NULL, " ");
        }
        arg_index++;
    }

    char* token = strtok(argv[arg_index], " ");
    int index = 0;
    while (token != NULL) {
        sushi_sequence[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    function2(N, M, orders, sushi_sequence, sushi_eaten);

    for (int i = 0; i < N; i++) {
        printf("%d ", sushi_eaten[i]);
    }

    return 0;
}