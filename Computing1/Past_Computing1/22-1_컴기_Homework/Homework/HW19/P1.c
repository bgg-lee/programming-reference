#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  if (argc < 4){
    printf("Please input at least 4 integers\n");
  }

  int i = atoi(argv[1]);
  int j = atoi(argv[2]);
  int k = atoi(argv[3]);
  int l = atoi(argv[4]);

  char *alphabet[] = {"ABCD", "EFGH", "IJKL", "MNOP"};  
  // char *alphabet[] = {{'A','B','C','D','\0'},{'E','F','G','H','\0'},{'M','N','O','P','\0'}};
  // char *alphabet[3][5] = {{'A','B','C','D','\0'},{'E','F','G','H','\0'},{'M','N','O','P','\0'}};

  char a, b, c, d;
    
  /* Write your code here */	

  // ---- method 1 ---- // 
  // char *A = &(alphabet[i][0]);
  // char *B = &(alphabet[j][0]);
  // char *C = &(alphabet[k][0]);
  // char *D = &(alphabet[l][0]);
  // a = A[0];
  // b = B[1];
  // c = C[2];
  // d = D[3];

  // ---- method 2 ---- // 
  char *A = alphabet[i];
  char *B = alphabet[j];
  char *C = alphabet[k];
  char *D = alphabet[l];
  a = A[0];
  b = B[1];
  c = C[2];
  d = D[3];

  /*do not modify below*/

  printf("%c%c%c%c\n", a,b,c,d);

  return 0;
}
