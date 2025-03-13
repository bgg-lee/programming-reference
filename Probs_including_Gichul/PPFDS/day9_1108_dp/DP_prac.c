#include <stdio.h>
#include <string.h>
// DP: Longest Palindromic Subsequence (LPS) 어렵다.. 그치만 함 풀어보자
// 요런건 C로도 할 수 있어야 할듯 -> 일단 Python으로 코드연습은 하자

#define MAX_SIZE 1000
int memo[MAX_SIZE][MAX_SIZE];

int max(int x, int y) {
    return (x > y) ? x : y;
}

int lcs(char *s1, char *s2, int l1, int l2) {
// Memoization 으로 풀기
    if(l1==0 || l2==0) return 0;
    
    if(memo[l1][l2] != -1){
        printf("get\n");
        return memo[l1][l2]; // 저장값이 있다.
    }
    else{
        if(s1[l1-1]==s2[l2-1]) memo[l1][l2] = 1+lcs(s1,s2,l1-1,l2-1);
        else memo[l1][l2] = max(lcs(s1,s2,l1-1,l2),lcs(s1,s2,l1,l2-1));
    }
    return memo[l1][l2];

// //DP로 풀어보기
//     // base case(one of them is empty)
// if(l1==0 || l2==0) return 0;

// if(s1[l1-1]==s2[l2-1]) return 1+lcs(s1,s2,l1-1,l2-1);
// else return max(lcs(s1,s2,l1-1,l2),lcs(s1,s2,l1,l2-1));

// 내가 푼 노가다 방법
/*  int cnt = 0;
    int idx = l2;
    for(int i=l1-1;i>=0;i--){
        for(int j=l2-1;j>=0;j--){
            if(s1[i]==s2[j] && j<idx){
                cnt++;
                idx=j;
                printf("%c ",s1[i]);
            }
        }
    }
    return cnt;
*/
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            memo[i][j] = -1;
        }
    }

    printf("%d\n", lcs(s1, s2, l1, l2));
    //GTAB -> 4
    return 0;
}