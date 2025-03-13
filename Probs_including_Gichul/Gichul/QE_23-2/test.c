#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char test[10] = "abcdefg";
    char test2[10];
    strncpy(test2,test+2,4);
    test2[4] = '\0';
    printf("%s\n",test2);
    char test3[] = "z";
    // test3[1] = '\0';
    // char test4[13] = test2+test3;
    strcat(test2,test3);
    printf("%s\n",test2);

}