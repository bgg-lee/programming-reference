#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int P4(int n);


int P4(int n){
    // write your code below
    int max = 1;
    int ans = 1;
    bool mod = true;

    for (int i = 1; i <= n; i++) {
        max *= i;
    }

    for (int i = n; i <= max; i++){
    // while (mod){
        for (int j = 1; j <=n; j++) {
            if (i % j != 0) {
                mod = false;
            }
            }
        if (mod == true) {
            ans = i;
            break;
        }    
        else {
            mod = true;
        }
        }
    
    return ans;
}

// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = P4(n);

    printf("%d\n", ans);

    return 0;
}