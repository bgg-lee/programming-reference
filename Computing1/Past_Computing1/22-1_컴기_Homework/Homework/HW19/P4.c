#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 10

void print_dup_numbers(int* numbers, int n_integers);

int main(int argc, char* argv[]) {
    if (argc == 1) {
      printf("Please input at least 1 integer.\n");
    }

    int numbers[MAX_LEN];
    for (int i = 1; i < argc; ++i) {
        int tmp = atoi(argv[i]);
        numbers[i-1] = tmp;
    }
    print_dup_numbers(numbers, argc-1);

    return 0;
}
/* Do not modify above*/

void print_dup_numbers(int* numbers, int n_integers) {
    /*
    numbers: input integer array
    n_integers: length of 'numbers'
    */
    /* Write your code here */	
    bool ans = false;

    for (int i=0; i<n_integers; i++){
        int cnt =0;
        for (int j=0;j<i;j++){
            if (numbers[i]==numbers[j]){
                cnt ++;
            }}
        if (cnt>0) {continue;}
            
        for (int j=i+1; j<n_integers; j++){
            if (numbers[i]==numbers[j]){
                cnt ++; 
            }}
        if (cnt>0) {
            printf("%d ", numbers[i]);
            ans = true;
        }}
    
    if (ans == false){
        printf("%d", -1);
    }
}