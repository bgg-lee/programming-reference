#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
// #include <cstdio>
int main(){
    int arr[3];
    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 100;
    sorted(arr.begein(),arr.end());
    for(int i=0;i<3;i++){
        printf("%d ",arr[i]);
    }
}