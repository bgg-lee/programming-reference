#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
functions

- isPalindrome : ���ڷ� string, start, end �ε����� ����
- isPalindrome_ : ���ڷ� string�� ����. 
- getAllSubstr : (duplicate ������) ��� substring ���س��� ��. 
            *****(duplicate �����ϴ� ���� all_subseq_all_palsubseq.c�� getLengthSubseq, getAllSubseq �Լ����� qsort ���� �κ��� �������ּ���!)
- PalindromeSubstr : palindrome�� ��� Subsequence�� ���س��� ��. getAllSubstr���� �޾ƿ� char** array�� �־���� ��!

struct
MaxMinPalindrome : minimum, maximum palindrome ������ �����ϴ� struct

main �Լ� (line 135) �� ��°�� :
Enter a string: abbasdba
a b b a s d b a ab bb ba as sd db ba abb bba bas asd sdb dba abba bbas basd asdb sdba abbas bbasd basdb asdba abbasd bbasdb basdba abbasdb bbasdba abbasdba 
Palindromic Substrings:
a b b a s d b a bb abba 
Maximum Palindrome: abba
Minimum Palindrome: a

*/


typedef struct {
    char* maxPalindrome;
    char* minPalindrome;
} MaxMinPalindrome;


char** getAllSubstr(char* str, int* count) {
    int length = strlen(str);
    int totalSubstr = length * (length + 1) / 2; 

    char** substrArray = (char**)malloc(totalSubstr * sizeof(char*));
    *count = 0; 

    for (int len = 1; len <= length; ++len) { 
        for (int i = 0; i <= length - len; ++i) { 
            substrArray[*count] = (char*)malloc((len + 1) * sizeof(char));
            strncpy(substrArray[*count], str + i, len);
            substrArray[*count][len] = '\0'; 
            (*count)++;
        }
    }

    return substrArray;
}

void printArray(char** arr, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void freeArray(char** arr, int count) {
    for (int i = 0; i < count; ++i) {
        free(arr[i]); 
    }
    free(arr); 
}


int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

bool isPalindrome_(char* s) {
    int start = 0;
    int end = strlen(s) - 1;
    while (start < end){
        if (s[start] != s[end]) {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}


char** PalindromeSubstr(char** allsubstrs, int count, int* palcount){
    char** allpals = (char**)malloc(count * sizeof(char*)); 
    *palcount = 0;
    for (int i = 0; i < count; i++){
        if (isPalindrome_(allsubstrs[i])) {
            int stlen = strlen(allsubstrs[i]); 
            allpals[*palcount] = (char*)malloc((stlen + 1) * sizeof(char)); 
            strncpy(allpals[*palcount], allsubstrs[i], stlen + 1); 
            (*palcount)++;
        }
    }
    if (*palcount < count){
        allpals = (char**)realloc(allpals, (*palcount) * sizeof(char*)); 
    }
    return allpals;
}



MaxMinPalindrome findMaxMinPalindrome(char** palArray, int palcount) {
    MaxMinPalindrome result = {NULL, NULL};
    if (palcount == 0) return result; 

    int maxLength = 0, minLength = strlen(palArray[0]);
    result.maxPalindrome = palArray[0];
    result.minPalindrome = palArray[0];

    for (int i = 0; i < palcount; i++) {
        int currLength = strlen(palArray[i]);
        if (currLength > maxLength) {
            maxLength = currLength;
            result.maxPalindrome = palArray[i];
        }
        if (currLength < minLength) {
            minLength = currLength;
            result.minPalindrome = palArray[i];
        }
    }

    return result;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);

    int count, palcount;
    char** substrArray = getAllSubstr(str, &count);
    char** palArray = PalindromeSubstr(substrArray, count, &palcount);
    printArray(substrArray, count);

    printf("Palindromic Substrings:\n");
    printArray(palArray, palcount);

    MaxMinPalindrome maxmin = findMaxMinPalindrome(palArray, palcount);
    printf("Maximum Palindrome: %s\n", maxmin.maxPalindrome ? maxmin.maxPalindrome : "None");
    printf("Minimum Palindrome: %s\n", maxmin.minPalindrome ? maxmin.minPalindrome : "None");

    freeArray(substrArray, count);
    freeArray(palArray, palcount);
    return 0;
}
