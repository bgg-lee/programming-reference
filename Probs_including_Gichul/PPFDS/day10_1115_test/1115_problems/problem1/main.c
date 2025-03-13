#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char* argv[]) {

    char word1[300];
    char word2[300];
    strcpy(word1, argv[1]);
    strcpy(word2, argv[2]);

    printf("%d\n", function1(word1, word2));
    return 0;
}

// s1=geek , s2=gesek #1
// s1=cat , s2=cut #1
// s1=sunday , s2=saturday #3