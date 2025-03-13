#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    // YOUR CODE HERE
    if (N == 1){printf("*");}
    else if (N == 2){printf(" * \n***");}
    else {
        int i, j;

        for (i=1;i<=(N-1); i++){printf(" ");}
        printf("*"); // 0, 1, 1+2, 1+2+2, 1+2+2+2,
        for (i=1;i<=(N-1); i++){printf(" ");}
        printf("\n");
        
        for (j=2; j<N; j++){
            for (i=N-j; i>=1; i--){printf(" ");} // N-2 N-3 --- 1
            printf("*");
            for (i=2*N-(1+2*j); i<=(2*N-5); i++){printf(" ");} // 2N-19, 2N-17, 2N-15,..., 2N-5
            printf("*");
            printf("\n");
        }

        for (i=0;i<(2*N-1); i++){printf("*");}
    }
    return 0;
}
