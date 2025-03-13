#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char str1[] = "abcdef"; // str1[0]='z' 이렇게 수정가능
    char* str2 = "ABCDEF"; // Read - Only Mode
    str1[0] = 'z';
    // str2[0] = 'Z'; // Segmentation fault

// String Copy하기
    char result[100]; // 넉넉하게
    strcpy(result,str1); // 그대로 copy
    strcpy(result,str1+2); // +2부터 copy
    // printf("%s\n",result); //cdef
// index 2~4자르기 -> 수동 '\0' 더해줘야 함!!!
    strncpy(result,str1+1,3); // strNcpy임!!!
    result[3] = '\0';
    // if(strcmp(result,"bcd") ==0) printf("%s\n",result);

    char* result2 = (char*)malloc(sizeof(char)*10);
    strncpy(result2,str2+1,4);
    result2[4] = '\0';
    // printf("result2:%s\n",result2);

/* 문자복사 strcpy->NULL까지 복사, strncpy-> 딱 n바이트만 복사(\0지정 필요할 수도)*/

// String끼리 같은지 비교, 같으면 strcmp == 0
    // if(strcmp(str1,result)!=0) printf("--PASS1\n");
    // if(strcmp(str1,str1)==0) printf("--PASS2\n");
// 특정 char의 index 구하기
    // printf("%s\n",str1);
    // char* p = strchr(str1,'d');
    // if(!p) printf("NOT FOUND\n");
    // else{
    //     int idx = p - str1; // index 반환
    //     printf("find : %c, idx: %d\n",str1[idx],idx);
    // }

// 문자열 더하기, python의 string += 'a' 처럼
    // strcat 등의 함수를 이용하기
    // strcat(str1," add this \n");
    // printf("%s\n",str1);
    // strcat(str1,str2); // 공간 충분히 있는지 확인 필요
    // strcat(result,str1);
    // strcat(result,str1);
    // strcat(result,str1);
    // strcat(result,str1);
    // printf("%s\n",result);

// 문자 / 숫자 / 문자열 변환법
    // 1. char -> int
    // char c = '5';
    // int x = c -'0';
    // printf("%d\n",x); // 5
    
    // 2. 'a' ~ 'z' 는 0~25 inr다
    // char c = 'f';
    // int idx = c - 'a';
    // printf("%d\n",idx); // 5

    // 3. 숫자 -> 문자 : '0' + num
    // int n = 3;
    // char c = '0' + n;
    // printf("%c\n",c); // 3

    // 4. string -> 숫자
    // 4-1 atoi
    // char str[10] = "1234";
    // int num = atoi(str);
    // printf("%d\n",num); // 1234
    // 4-2 strtol
    // char* s2 = "981a7";
    // char* end;
    // long v2 = strtol(s2, &end, 10); 
    // // v2 = 987, end -> "abc"
    // // base=10 진수로 변환, 변환 실패나 범위 초과 등 체크 가능
    // printf("v2=%ld, leftover=%s\n", v2, end);

    // 숫자 -> 문자열
    // // 1 - sprintf 이용
    // char buf[50];
    // int num = 42;
    // float num2 = 3.14;
    // sprintf(buf,"%d",num);
    // printf("%s\n",buf);
    // sprintf(buf,"%.2f",num2);
    // // printf("%s\n",buf);
    // // 2 - snprintf 이용
    // snprintf(buf,sizeof(buf),"%.3f",12.34567);
    // printf("%s\n",buf);
    // snprintf(buf,sizeof(buf),"%.1f",num2);
    // printf("%s\n",buf);
    
}