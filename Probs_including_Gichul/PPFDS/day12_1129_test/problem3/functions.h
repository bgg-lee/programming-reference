#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
/*
A group of n people is waiting in line for immigration inspection, Each immigration officer at an inspection station take a different amount of time to process a person.

Initilaiily, all inspection stations are empty. each station can only process one person at a time...

number of people waiting for insperction N and an array time
*/
long long function3(int n, int times[], int size) {
    //일단 time을 sorting한다 -> 필요 없다
    // 0으로 이루어진 arr 초기화
    int ans[size] = {0};
    // for(int i=0;i<size;i++) ans[i]=0;
    
    int cnt = 0;
    while(cnt!=n){
        int idx;
        int target = INT_MAX;
        for(int k=0;k<size;k++){
            if(ans[k]+times[k]<target){
                target = ans[k]+times[k];
                idx = k;
            }
        }
        cnt++;
        ans[idx] += times[idx];
    }
    long long result = INT_MIN;
    for(int j=0;j<size;j++){
        if(ans[j]>result) result = ans[j];
    }
    return result;
}   
//immigration inspection

// arr 내에서 최소값인지 확인 -> 안 씀
// bool min(int target,int arr[],int arrsize){
//     for(int j=0;j<arrsize;j++){
//         if(arr[j]>target) return false;
//     }
//     return true;
// }

// Feel free to construct functions you need. 
// Submit functions.h file.

// compile command: g++ -o main main.c
// execute command: 
//             ./main n "times"
//             ./main 6 "7 10" # answer: 28


/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long count_people(int time_limit, int times[], int size) {
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += time_limit / times[i];
    }
    return total;
}

long long function3(int n, int times[], int size) {
    long long left = 1;
    long long right = (long long)n * times[0]; // 가장 긴 시간으로 초기화
    for (int i = 1; i < size; i++) {
        if (times[i] > right / n) right = (long long)n * times[i];
    }

    long long result = right;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long people_processed = count_people(mid, times, size);

        if (people_processed >= n) {
            result = mid; // 가능한 최소 시간 갱신
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./main n \"times\"\n");
        return 1;
    }

    int n = atoi(argv[1]);
    char* token;
    int times[100]; // 최대 100개의 검사관
    int size = 0;

    token = strtok(argv[2], " ");
    while (token != NULL) {
        times[size++] = atoi(token);
        token = strtok(NULL, " ");
    }

    long long result = function3(n, times, size);
    printf("Minimum time: %lld\n", result);

    return 0;
}

*/


/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    // 이진 탐색 범위를 설정
    long long left = 1;
    long long right = (long long)n * *max_element(times.begin(), times.end()); // 가장 긴 시간으로 초기화
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long people_processed = 0;

        // mid 시간 안에 처리 가능한 사람의 수 계산
        for (int time : times) {
            people_processed += mid / time;
            if (people_processed >= n) break; // 불필요한 계산을 줄이기 위해 조기 종료
        }

        if (people_processed >= n) {
            // 더 짧은 시간에서 가능한지 확인
            answer = mid;
            right = mid - 1;
        } else {
            // 더 많은 시간이 필요
            left = mid + 1;
        }
    }

    return answer;
}
*/