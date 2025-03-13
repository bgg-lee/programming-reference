/* 개어렵다..
**[문제 설명: makingPalindrome]**

어떤 문자열이 주어졌을 때, 우리는 일부 문자를 제거하는 방법을 통해서 palindrome을 만들 수 있다.

예를 들어서 "unique"라는 문자열이 주어진다면,
'n', 'q', 'e' 총 3개의 문자를 제거하여 "uiu" 라는 palindrome을 만들 수 있을 것이다.
또는, 'n', 'i', 'q', 'e' 총 4개의 문자를 제거하여 "uu"라는 palindrome도 만들 수 있다.

다른 예시로 만약 "radar"라는 문자열이 주어진다면,
그 자체로도 이미 palindrome이므로 0개의 문자를 제거하여 palindrome을 반환할 수 있다.

10자 이내, 그리고 알파벳 소문자로만 구성된 문자열에 대해,
최소 개수의 문자를 제거한 palindrome을 반환하는 함수를 구현하라.
만약 조건을 충족하는 palindrome이 여러 개라면 아무것이나 하나를 반환하면 된다.

**[문제 요약]**

- 사용자로부터 10자 이내의 문자열을 입력 받아라. // 유저한테 input을 받기;;;
- 문자열은 모두 알파벳 소문자로 구성되어 있다.
- 입력받은 문자열에 대해 최소 개수의 문자를 제거하여, palindrome을 반환하는 함수를 구현하라.
- 제거한 문자의 개수를 출력하라.
- palindrome을 반환하라. (한 개만 반환하면 된다.)

**[출력 예시]**

C:\User\... > ./QE_prob2

unique
3
uiu

C:\User\... > ./QE_prob2

radar
0
radar


*/

// C로 LPS 푸는 것..
// #include <stdio.h>
// #include <string.h>

// // dp[i][j]: substring s[i..j] 내 LPS 길이
// int dp[11][11];

// int main() {
//     char str[11];
//     scanf("%s", str);
//     int n = strlen(str);

//     // 1) DP 초기화
//     memset(dp, 0, sizeof(dp));
//     for(int i = 0; i < n; i++){
//         dp[i][i] = 1; // 길이 1 구간
//     }

//     // 2) 점화식
//     for(int length = 2; length <= n; length++){
//         for(int i = 0; i + length - 1 < n; i++){
//             int j = i + length - 1;
//             if(str[i] == str[j]) {
//                 if(length == 2) dp[i][j] = 2;
//                 else dp[i][j] = dp[i+1][j-1] + 2;
//             } else {
//                 if(dp[i+1][j] > dp[i][j-1]) dp[i][j] = dp[i+1][j];
//                 else dp[i][j] = dp[i][j-1];
//             }
//         }
//     }

//     int LPS_len = dp[0][n-1];
//     int deleted_count = n - LPS_len;

//     // 3) LPS 복원
//     char palindrome[11]; // 복원 후의 팰린드롬
//     int left = 0;
//     int right = LPS_len - 1;
//     int i = 0, j = n - 1;
//     while(i <= j){
//         if(str[i] == str[j]){
//             palindrome[left] = str[i];
//             palindrome[right] = str[j];
//             left++;
//             right--;
//             i++;
//             j--;
//         } else {
//             // dp 값이 큰 쪽으로 이동
//             if(dp[i+1][j] > dp[i][j-1]) {
//                 i++;
//             } else {
//                 j--;
//             }
//         }
//     }
//     palindrome[LPS_len] = '\0';

//     // 4) 출력
//     printf("%d\n", deleted_count);
//     printf("%s\n", palindrome);

//     return 0;
// }

//코드 (DP + LPS 복원 with 사전순 고려)

#include <stdio.h>
#include <string.h>

// dp[i][j]: s[i..j]에서 LPS의 길이 저장
int dp[11][11];
char memo[11][11][12];  // 사전순 LPS 복원을 위한 메모이제이션

// i~j 구간에서 사전순으로 가장 빠른 LPS를 반환하는 함수
char* buildLPS(char *s, int i, int j) {
    // 이미 저장된 결과가 있다면 반환
    if (memo[i][j][0] != '\0') {
        return memo[i][j];
    }

    // Base case: 빈 구간이면 빈 문자열 반환
    if (i > j) {
        memo[i][j][0] = '\0';
        return memo[i][j];
    }

    // Base case: 한 글자짜리 구간이면 그 글자 자체가 팰린드롬
    if (i == j) {
        memo[i][j][0] = s[i];
        memo[i][j][1] = '\0';
        return memo[i][j];
    }

    // Case 1: 양 끝 문자가 같다면, 가운데 구간의 LPS를 가져오고 앞뒤에 추가
    if (s[i] == s[j]) {
        char *mid = buildLPS(s, i + 1, j - 1);
        sprintf(memo[i][j], "%c%s%c", s[i], mid, s[j]);
    }
    // Case 2: 양 끝 문자가 다르면, 더 긴 LPS를 선택
    else {
        char *leftPath = buildLPS(s, i + 1, j);
        char *rightPath = buildLPS(s, i, j - 1);

        // 더 긴 부분을 선택
        if (dp[i+1][j] > dp[i][j-1]) {
            strcpy(memo[i][j], leftPath);
        } 
        else if (dp[i+1][j] < dp[i][j-1]) {
            strcpy(memo[i][j], rightPath);
        } 
        else {
            // 길이가 같다면 사전순 비교
            if (strcmp(leftPath, rightPath) < 0) {
                strcpy(memo[i][j], leftPath);
            } else {
                strcpy(memo[i][j], rightPath);
            }
        }
    }
    return memo[i][j];
}

int main() {
    char str[11];
    scanf("%s", str);
    int n = strlen(str);

    // 1) DP 초기화
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1; // 길이 1인 문자열은 자기 자신이 팰린드롬
    }

    // 2) DP 점화식
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i + length - 1 < n; i++) {
            int j = i + length - 1;
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }

    int LPS_len = dp[0][n-1];
    int deleted_count = n - LPS_len;

    // 3) LPS 복원 (가장 사전순 앞선 것)
    char *palindrome = buildLPS(str, 0, n - 1);

    // 4) 결과 출력
    printf("%d\n", deleted_count);
    printf("%s\n", palindrome);

    return 0;
}




// #include <stdio.h>
// #include <string.h>
// #include <string.h>

// int isPalindrome(char* s){
//     int n = strlen(s);
//     if(n<2) return 1;
//     int left = 0;
//     int right = n-1;
//     while(left<right){
//         if(s[left]!=s[right]) return 0;
//         else{
//             left++;
//             right--;
//         }
//     }
//     return 1;
// }

// int main(){
//     char str[11];
//     scanf("%s", str);
//     int n = strlen(str);

//     int maxLen = 0;
//     char bestSubseq[11] = "";

//     int total = 1 << n; // == 2^n 신기하네 비트 연산...

//     for (int mask = 0; mask < total; mask++){
//         // 부분수열 만들기
//         char candidate[11];
//         int idx = 0;
//         for(int i=0; i<n; i++){
//             if(mask & (1 << i)){
//                 candidate[idx++] = str[i];
//             }
//         }
//         candidate[idx] = '\0';

//         // 팰린드롬 검사
//         if(isPalindrome(candidate)){
//             int length = strlen(candidate);
//             if(length > maxLen){
//                 maxLen = length;
//                 strcpy(bestSubseq, candidate);
//             }
//             else if(length == maxLen){
//                 // [추가 부분] 동일 길이일 때, 사전순 비교 *strcmp**로 문자열을 사전순 비교하는 로직
//                 if(strcmp(candidate, bestSubseq) < 0){
//                     strcpy(bestSubseq, candidate);
//                 }
//             }            
//         }
//     }

//     // 결과
//     printf("%d\n", (n - maxLen));
//     printf("%s\n", bestSubseq);
// }


