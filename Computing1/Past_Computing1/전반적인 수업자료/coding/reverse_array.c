#include <stdio.h>

// array의 순서 자체를 reverse시켜라.

void swap_array(int * arrptr, int arrsize);

int main(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* arrptr = array;
    int arrsize = sizeof(array)/sizeof(int);

    for (int i=0; i<arrsize; i++){
        printf("%d", array[i]);
    }
    printf("\n");

    swap_array(arrptr, arrsize);   
    printf("swapped:\n"); 
    for (int i=0; i<arrsize; i++){
        printf("%d", array[i]);
    }
    printf("\n");

    return 0;
}

void swap_array(int*arrptr, int arrsize){
    int swapnum = arrsize/2;
    int*p1 = arrptr;
    int*p2 = arrptr + arrsize-1;

    printf("p1, *p1: %d, %d\n", p1, *p1);
    printf("p2, *p2: %d, %d\n", p2, *p2);

    int temp;
    for (int i=0; i<swapnum; i++){
        printf("*p1, *p2:%d, %d\n", *p1, *p2);
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        p1 +=1;
        p2 -=1;
        
    }

}