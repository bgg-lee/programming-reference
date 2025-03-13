#include <stdio.h>
#include <stdlib.h>

int P1(int n); // 함수 선언

// Implement P1 
// You can define other function, but P1 must return answer.

int P1(int n){ // 함수 정의
// write your code below
  if (n==1){
      return 1;
  }
  else {
      return 2 * P1(n-1) + 1;
  }
}


// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){ //argc: 입력된 문자열 개수, argc: 입력된 문자열
    int n = atoi(argv[1]); //atoi: 입력된 문자열을 정수로 변환
    int ans = P1(n);

    printf("%d\n", ans);

    return 0;
}