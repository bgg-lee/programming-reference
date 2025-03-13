#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int P3(int n);
int no_self_number(int n);

// Implement P4 
// You can define other function, but P4 must return answer.
int P3(int n){
    // write your code below
    int answer = 0;
    const int max = 8367868;
    
    for (int i = 1; i < max; i++) {
       int sn;
       sn = no_self_number(i);
       if (sn <=  max) {
           selfn[sn] = true;
       }
    }

    int n_ = n+1;
    while (selfn[n_]){
        answer = n_+1;
        n_ ++;
    }
    return answer;
    no_self_number()
}

bool selfn(int n){
    int i;
    for (i=1; i<=n; i++) {
        if (no_self_number(i) == n){
            return false;
        }
    return true;
    }

    }


int no_self_number(int n){ 
 // write your code below
 int mod = 0;
 int copy = n;
 while (n>0) {
    mod = n % 10;
    copy += mod;
    n = n / 10;
 }
return copy;
}


// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = P3(n);

    printf("%d\n", ans);

    return 0;
}