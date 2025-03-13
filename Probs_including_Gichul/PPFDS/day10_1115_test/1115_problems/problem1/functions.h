#include <stdlib.h>
#include <string.h>

int function1(char word1[], char word2[]) {
    //Write your code
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    int ans = 0;
    int i = 0;
    int j = 0;
    int idx; // 틀린 부분 체크용

    while(i<n1 && j<n2){
        idx = 0;
        if(word1[i]==word2[j]){
            i++;
            j++;
            continue;
        }else{ // 이 case가 문제다. //뒤에 재등장 하는지 확인
            char temp = word1[i];
            for(int k=i;k<n2;k++){
                if(temp==word2[k]){
                    idx = k-i;
                    break;}
            }
            // 뒤에 temp가 있다면
            if(idx!=0){
                ans += idx;
                i++;
                j+=idx+1;
            }// 뒤에 temp 없음
            else{
                ans+=1;
                i++;
                j++;
            }
        }
        // printf("ans:%d ",ans);
    }
    // i가 남은 경우
    if(i!=n1) ans += n1-i+1;
    else if(j!=n2) ans += n2-j+1;
    return ans;
}

// Feel free to construct functions you need. 
// Submit functions.h file.

// compile command: g++ -o main main.c
// execute command: 
//             ./main "geek" "gesek" # 1
//             ./main "cat" "cut"  # 1
//             ./main "sunday" "saturday" # 3

// https://www.geeksforgeeks.org/edit-distance-dp-5/