#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//sushi customer 누가 몇개씩 먹는지
#define MAX_CUSTOMERS 100
#define MAX_SUSHI_TYPES 1000
/*
At a conveyor belt sushi restaurant, there are N customers, and the chef prepares M pices of sushi in sequence. When the chef prepares a piece of sushi, it is passed in order from customer 1 to customer N. If an earlier customer eats the sushi, subsequent customers cannot eat that piece. if no one eats the sushi, it is discarded
*/

void function2(int N, int M, int orders[][1000], int* sushi_sequence, int* result) {
    // 첫 빠따부터 for문 돌리면서 하나씩 먹고 sequence에서 그걸 -1로 교체
    // 내가 먹고 싶은건 orders에서, chef가 준비한건 sushi_sequence
    // 동시에 result도 update
    int target;
    for(int i=0;i<N;i++){
        int cnt = 0;
        for(int j=0;j<1000;j++){
            if(orders[i][j]==1) target = j;
            // sushi 탐색
            for(int k=0;k<M;k++){
                if(sushi_sequence[k]==target){
                    cnt++;
                    sushi_sequence[k] = -99;
                    break;
                }
            }
        }
        result[i] = cnt;
    }
}

// Feel free to construct functions you need. 
// Submit functions.h file.

// compile command: g++ -o main main.c
// execute command: 
//             ./main "3 5" "1 6" "2 3 5" "1" "3 2 1 4 5"