#include <stdio.h>


int is_prime(int N){
    for (int i=2; i<N; i++){
        if (N%i==0){
            return 0;
        }
    }
    return 1;
}

int divisor_num_count(int N, int p){
    int count = 0;
    int tempN = N;
    while (tempN%p==0){
        tempN = tempN/p;
        count +=1;
        // printf("N:%d, tempN:%d, count:%d\n", N, tempN, count);

    }
    return count;
}

int main(void){

    int Num;
    int isprime;
    int count;
    printf("Please Enter an integer: ");
    scanf("%d", &Num);
    printf("\nEntered Num: %d\n", Num);
    
    for (int i=2; i<=Num; i++){
        count = divisor_num_count(Num, i);
        if (count>0 && is_prime(i)==1){
            printf("(%d, %d)", i, count);
        }

    }
    printf("\n");
    return 0;
}