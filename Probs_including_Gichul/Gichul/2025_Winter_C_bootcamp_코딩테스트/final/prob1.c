#include <stdio.h>
#include <stdlib.h>


// Implement the function numOf1s() 
// that counts the number of 1s in the binary representation of the input n.
int numOf0s(int n){
    /*Write your code here*/
    int cnt = 0;
    while(n > 0){
        if((n&1)==0) cnt++;
        n = n >> 1;
    }

    return cnt;
    ////////////////////////
}

/*Do not modify below*/
int main(int argc, char * argv[]){
    if(argc <= 1){
        printf("Invalid input!");
    }else{
        for (int i=0; i < (argc-1); i++) {
            int a = atoi(argv[i+1]);
            printf("%d ",numOf0s(a));
        }
        printf("\n");
    }
    return 0;
}