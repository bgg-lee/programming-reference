#include <stdio.h>
#include <stdlib.h>

// Declare & implement the function gcd() that calculates the greatest common divisor of two integers a and b.
int gcd(int a, int b){
    /*Write your code here*/
    if(b==0) return a;
    return gcd(b,a%b);
    ////////////////////////
}

// Declare & implement the function lcm() that calculates the least common multiple of two integers a and b.
int lcm(int a, int b){
    /*Write your code here*/
    return (a*b)/gcd(a,b);
    ////////////////////////
}


/*Do not modify below*/
int main(int argc, char * argv[]){
    if(argc!=3){
        printf("Invalid input!");
    } else {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        printf("%d", lcm(a,b));
    }
    return 0;
}