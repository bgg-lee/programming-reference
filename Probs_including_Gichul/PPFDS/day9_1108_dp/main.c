#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("사용법: %s <정수>\n", argv[0]);
        return 1;
    }

    int nums = atoi(argv[1]);

    printf("%d\n", climbStairs(nums));
    return 0;
}