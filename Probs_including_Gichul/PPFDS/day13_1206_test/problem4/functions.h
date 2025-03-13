#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Use structs below if you need.
typedef struct StackNode {
    char character;
    int count;
    struct StackNode* next;
} StackNode;

StackNode* push(StackNode* top, char ch, int count) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->character = ch;
    newNode->count = count;
    newNode->next = top;
    return newNode;
}

StackNode* pop(StackNode* top) {
    if (top == NULL) return NULL;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
}

char* function4(char* s, int k) {
    //Write your code
    // 돌면서 연속이 아닌 경우 pass
    // int n = strlen(s);
    // // char* ans = (char*)malloc((n+1)*sizeof(char));
    // char* ans = (char*)malloc((n+1)*sizeof(char));
    // int cnt = 0;
    // while(cnt!=n){
    //     cnt++;
    //     int m = strlen(s);
    //     for(int i=0;i<m-1;i++){
    //         if(s[i]=='&') continue;
    //         int temp = 1;
    //         while(temp != k){
    //             if(s[i+temp-1]==s[i+temp]){
    //                 temp++;
    //             }
    //             else break;
    //         }
    //         if(temp==k){// temp까지 쭈욱 지워
    //             for(int j=i;j<i+temp;j++){
    //                 s[j] = '&';
    //             }
    //         }
    //         else{//살려
    //             continue;
    //         }
    //     }
    //     int idx=0;
    //     for(int k=0;k<n;k++){
    //         if(s[k]!='&') ans[idx++] = s[k];
    //     }
    //     ans[idx]='\0';
    //     s = ans;
    // }

    // return ans;
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char)); // 결과 저장용
    bool changed = true; // 문자열이 변경되었는지 확인

    while (changed) {
        changed = false; // 변경 여부 초기화
        int writeIndex = 0; // 결과 문자열의 현재 위치
        int i = 0; // 입력 문자열의 현재 위치
        
        while (i < n) {
            int count = 1;
            // 연속된 문자 개수 세기
            while (i + count < n && s[i] == s[i + count]) {
                count++;
            }
            // 연속된 문자가 k 이상이면 건너뛰기
            if (count >= k) {
                changed = true; // 문자열이 변경되었음을 표시
                i += count; // 연속된 문자 건너뛰기
            } else {
                // 연속되지 않은 문자를 결과에 추가
                for (int j = 0; j < count; j++) {
                    result[writeIndex++] = s[i + j];
                }
                i += count; // 처리한 문자만큼 이동
            }
        }
        result[writeIndex] = '\0'; // 문자열 종료
        strcpy(s, result); // 결과를 원본에 복사
        n = strlen(s); // 새 문자열 길이 계산
    }
    free(result);
    return s; // 최종 결과 반환
}
    // int idx = 0;
    // int cnt;
    // bool cond;
    // for(int i=0;i<n;i++){
    //     cnt = 0;
    //     cond = false;
    //     //연속이 아니거나 K개 연속이 아닌 경우
    //     for(int j=i;j<i+k;j++){
    //         if(s[j]!=s[j+1]){
    //             cond = true;
    //             break;
    //         }
    //     }
    //     if(cond){
    //         ans[idx++] = s[i];
    //     }
    // }
    // ans[idx] = '\0';


    // 마지막에 \0 해주기
// Feel free to construct functions you need. 
// Submit functions.h file.

// compile command: g++ -o main main.c
// execute command: 
//             ./main "accassl" 2 # answer: l