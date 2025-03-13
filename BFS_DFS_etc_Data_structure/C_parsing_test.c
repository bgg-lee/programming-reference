/*
가끔 C에서 문자열 String을 Parsing pasre 해야하는 일이 있어서 적어 놓는 것

-- python
test = 'abcde'
test = test[1:] + test[3:]  # 'bcdede'

-- C
1. 포인터 연산(Pointer Arithmetic)과 표준 라이브러리 함수 사용
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char test[] = "abcde";

    // 필요한 길이를 계산
    // test[1:] 길이: strlen(test) - 1
    // test[3:] 길이: strlen(test) - 3
    // 널 문자까지 고려하면 전체 길이는 (strlen(test) - 1) + (strlen(test) - 3) + 1
    size_t len = (strlen(test) - 1) + (strlen(test) - 3) + 1;

    // 결과를 저장할 공간 동적 할당
    char *result = (char *)malloc(len);
    if (result == NULL) {
        perror("malloc");
        return 1;
    }

    // 첫 번째 부분 복사: test[1:] -> "bcde"
    strcpy(result, test + 1);
    // 두 번째 부분 이어 붙이기: test[3:] -> "de"
    strcat(result, test + 3);

    printf("%s\n", result);  // "bcdede"

    free(result);
    return 0;
}

or

#include <stdio.h>
#include <string.h>

int main() {
    char test[] = "abcde";
    char result[100];  // 넉넉하게

    strcpy(result, test + 1);  // "bcde"
    strcat(result, test + 3);  // "bcdede"

    printf("%s\ng", result);

    return 0;
}
or

2. 부분 문자열 복사(Substring) 함수 직접 구현
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// start 인덱스부터 end-1 인덱스까지 복사하여 동적 할당된 문자열 포인터 반환
char* substring(const char* src, int start, int end) {
    if (start < 0 || end <= start) {
        return NULL;
    }
    int len = end - start;
    char *dest = malloc(len + 1); // 끝에 널 문자 공간 1개 필요
    if (!dest) return NULL;

    // src + start부터 len개만큼 복사
    strncpy(dest, src + start, len);
    dest[len] = '\0';
    return dest;
}

int main() {
    const char* test = "abcde";
    // test[1:len(test)] = "bcde"
    char* sub1 = substring(test, 1, strlen(test));
    // test[3:len(test)] = "de"
    char* sub2 = substring(test, 3, strlen(test));

    // 최종 결과 저장할 공간 확보
    char* result = malloc(strlen(sub1) + strlen(sub2) + 1);
    if (!result) return 1;

    strcpy(result, sub1);
    strcat(result, sub2);

    printf("%s\n", result); // "bcdede"

    // 동적 할당 해제
    free(sub1);
    free(sub2);
    free(result);

    return 0;

3. memmove나 strncpy 등을 이용한 문자열 조작
#include <stdio.h>
#include <string.h>

int main() {
    char test[100] = "abcde";  // 크기를 넉넉히 잡음
    
    // 'a'를 제거하고 싶다면 (index 0의 글자)
    memmove(test, test + 1, strlen(test)); 
    // test: "bcde"

    // 다시 'd'와 'e'를 제거하고 싶다면 (현재 "bcde"에서 index 2부터)
    // 'd'(2), 'e'(3) 제거 -> index 4 (널 문자 위치)까지 당겨옴
    memmove(test + 2, test + 4, strlen(test + 4) + 1);
    // test: "bc"

    printf("%s\n", test); // "bc"
    return 0;
}

*/
#include <stdio.h>
#include <string.h>
int main(){
    char test[] = "abcdefg";
    char slice[3]; // '\0' 까지 포함
    char strcpy_[100];
    // test의 인덱스 3부터 2바이트만 복사("de")
    strncpy(slice,test+3,2); // strncpy는 정해진 길이만 복사하기때문에 NULL이 복사되지 않을 수 있다..!
    slice[2] = '\0';
    strcpy(strcpy_,test+2); // strcpy는 그대로 string복사
    // strncpy는 복사할 길이만큼만 옮기니까 종료문자 직접 넣어야함.

    printf("slice = %s\n",slice);
    printf("strcpy = %s\n",strcpy_);

    /*
    char a[] = "Hello, ";
    char b[] = "World!";
    char result[50]; // 넉넉히 잡음

    strcpy(result, a);  // result = "Hello, "
    strcat(result, b);  // result = "Hello, World!"

    printf("%s\n", result); // "Hello, World!"
    */
}



