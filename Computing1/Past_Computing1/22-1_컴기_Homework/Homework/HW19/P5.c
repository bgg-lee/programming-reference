#include <stdio.h>
#include <stdlib.h>

/* Correct below function to swap two characters pointed by x and y 
  Then return the first pointer */
char* swap_pointers(char *x, char *y)
{
  /* Write your code here */
  char x_bef = *x;
  char y_bef = *y;
  *x = y_bef;
  *y = x_bef;

  return x;

 /* Do no modify below */
}


int main(int argc, char* argv[])
{  
  if (argc != 3){       /* When the number of inputs is not 2 */
    printf("Please input 2 characters\n");
    return -1;
  }     

  char* s1 = argv[1];
  char* s2 = argv[2];   

  char* t1;  
  
  t1 = swap_pointers(s1,s2);  
  printf("%s,%s,%s\n", s1,s2,t1);  
  return 0;
}