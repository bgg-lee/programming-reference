#include "stdio.h"
#include "stdlib.h"

int max(int a, int b){
    if(a>=b) return a;
    else return b;
}

int main(){
    int c = 3;
    int d = 5;
    printf("%d\n",max(c,d));
}