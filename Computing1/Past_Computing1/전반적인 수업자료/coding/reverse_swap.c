#include <stdio.h>
#include <math.h>
void reverse_dig(int* a);
void Swap(int* Aptr, int* Bptr);

int main(void){

    int a, b;
    printf("Enter a:");
    scanf("%d", &a);
    printf("Enter b:");
    scanf("%d", &b);

    int* Aptr = &a;
    int* Bptr = &b;
    printf("Aptr:%d, Bptr:%d\n\n", *Aptr, *Bptr);

    reverse_dig(Aptr);
    reverse_dig(Bptr);
    printf("Aptr:%d, Bptr:%d\n", *Aptr, *Bptr);

    Swap(Aptr, Bptr);
    printf("Aptr:%d, Bptr:%d\n", *Aptr, *Bptr);



    return 0;
}

void Swap(int* Aptr, int* Bptr){
    int temp = *Aptr;
    *Aptr = *Bptr;
    *Bptr = temp;
}

void reverse_dig(int *a){
    int temp = *a;
    int r = 0;
    int result = 0;

    while (temp > 0){
        r = temp % 10;
        result = 10*result + r;
        temp = temp/10;
    }
    *a = result;
}