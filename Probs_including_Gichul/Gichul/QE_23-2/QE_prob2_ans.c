#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_strings = 0;
char* strings[1000000]; 
char temp[1000000];
int vis[1000000];
int length = 0;

void backtracking(char* s, int curr, int maintain, int st){
    if (curr == maintain){
        temp[curr] = '\0'; 
        strings[num_strings] = (char*)malloc(strlen(temp) + 1);
        strcpy(strings[num_strings], temp);
        num_strings++;
        return;        
    }
    char prev = '\0';
    for (int i=st; i<length; i++){
        if (vis[i] == 1) continue;
        if (s[i] == prev) continue;
        vis[i] = 1;
        temp[curr] = s[i];
        prev = temp[curr];
        backtracking(s, curr+1, maintain, i+1);
        vis[i] = 0;
    }
}

char** str_perm(char* s, int delete){
    int maintain = strlen(s)-delete;
    backtracking(s, 0, maintain, 0);
    return strings;
}

int isPalindrome(char* word){
    int word_len = strlen(word);
    for (int i=0; i<word_len/2; i++){
        if (word[i] == word[word_len-i-1]){
            continue;
        }
        else return 0;
    }
    return 1;
}

int main(){
    char input[20];
    scanf("%s", input);
    length = strlen(input); 

    char output[20];
    for (int d=0; d<length; d++){
        num_strings = 0;
        char** ans = str_perm(input, d);
        for (int i=0; i<num_strings; i++){
            if (isPalindrome(ans[i])==1){
                strcpy(output, ans[i]); 
                printf("%d\n", d);
                printf("%s", output);
                return 0;
            }
            free(ans[i]);
        }
    }
    printf("%d\n", length);

    return 0;
}