#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int P3(int n);
int CheckSelfNumber(int num) ;
int GenerateNumber(int num) ;

// Implement P4 
// You can define other function, but P4 must return answer.
int P3(int n){
    // write your code below
     int ans;
    for (ans = n + 1; ; ans++) {
        if (CheckSelfNumber(ans)) return ans;
    }

}

int CheckSelfNumber(int num) {
    int n;
    for (n = 1; n <= num; n++) {
        if (GenerateNumber(n) == num) return 0;
    }
    return 1;
}

int GenerateNumber(int num) {
    int sum = num;
    while (num > 0) {
        sum = sum + num % 10;
        num /= 10;
    }
    return sum;
}



// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = P3(n);

    printf("%d\n", ans);

    return 0;
}