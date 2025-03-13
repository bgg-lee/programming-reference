#include <stdio.h>
#define LETTER '1'
#define STOP 0
#define ZERO 0
#define NUMBER 123

int main(void) {
  printf("----------Question 2----------\n");
  int counter;
  int startPoint;

  printf("====Countdown Program====\n");
  printf("Enter a positive integer: ");
  scanf("%d", &startPoint); // int scanf("입력받을 문자의 서식", 변수의 주소)

  for (counter = startPoint; counter >= STOP; counter--){
    printf("%c\n", counter + 'A'); // %c 문자
  }

  printf("----------Question 3----------\n");
  // counter = ;
  // int startPoint;

  printf("====Countdown Program====\n");
  printf("Enter a positive integer: ");
  scanf("%d", &startPoint); // int scanf("입력받을 문자의 서식", 변수의 주소)

  for (counter = startPoint; counter >= STOP; counter--){
    printf("%d\n%d\n", counter, startPoint + counter); // %d 10진수 부호 있는 정수
  }

  printf("----------Question 4----------\n");
  // counter = ;
  // int startPoint;

  printf("====Countdown Program====\n");
  printf("Enter a positive integer: ");
  scanf("%d", &startPoint); // int scanf("입력받을 문자의 서식", 변수의 주소)

  for (counter = startPoint; counter >= STOP; counter--){
    printf("%x\n", counter);  // %x 16진수 정수 소문자 (0~9,a,b,c,d,e,f)
  }

  printf("----------Question 5----------\n");
  printf("%c", 'a'); // a
  printf("x%x", 12288);  // x3000
  printf("$%d.%c%d n", NUMBER, LETTER, ZERO); // $123.10 n

  printf("----------Question 7----------\n");
  int t = 2;
  { 
    printf("%d\n", t);  // 2
    {
      printf("%d\n", t); // 2
      t= 3;
    }
    printf("%d\n", t); // 3
  }
  {
    printf("%d\n", t); // 3
  }
  printf("%d\n", t); // 3

  printf("----------Question 8----------\n");
  char letter = 'f';
  letter = ((letter >= 'a' && letter <= 'z')? '!' : letter);
  // variable = (condition)? if true : if false;
  printf("%c\n", letter);
  
  printf("----------Question 9----------\n");
  int i = 10;
  int j;
  j = ++i;
  printf("%d\n", j); // 11
  i = 10;
  j = i++;
  printf("%d\n", j); // 10
  i = 10;
  j = i+1;
  printf("%d\n", j); // 11
  i = 10;
  j = i+= 1;
  printf("%d\n", j); // 11
  i = 10;
  i+= 1;
  j= i;
  printf("%d\n", j);   // 11

  
  printf("----------Question 10----------\n");
  int a = 1;
  int b = 1;
  int c = 3;
  int result = 999;

  result = b+1 | c+a; // 2 or 2 = 2
  // | : 비트단위로 OR 연산을 한다.
  printf("%d\n", result);
  }