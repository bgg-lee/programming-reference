#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMS 10

void InsertionSortReverse(char list[]);
int find_index(char a);

int main(int argc, char* argv[])
{
  char chars[MAX_NUMS]; //List of characters to be sorted

  if (argc < MAX_NUMS){
    printf("Please give %d inputs\n", MAX_NUMS);
    return -1;
  }
  

  for (int index=0; index < MAX_NUMS; index++)
  {
    chars[index] = argv[index + 1][0];    
  }

  InsertionSortReverse(chars); //Call sorting routine

  //Print sorted list  
  for (int index = 0; index < MAX_NUMS; index++)
    printf("%c", chars[index]);

  return 0;
}
/* Do not modify above*/

void InsertionSortReverse(char list[])
{
  /* Write your code here */	
  int i, j, thres_no;
  char thres;

  for (i = 1; i < MAX_NUMS; i++) {
    thres = list[i]; 
    thres_no = find_index(thres);
    for (j = i-1; thres_no > find_index(list[j]) && j>=0; j--){
        list[j+1] = list[j];
        }
    list[j+1] = thres;
    }
  }

int find_index(char a){
  char *thres_a = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
  int size = 53;
  int index = 0;
  for (int i =0; i<size; i++){
    if (thres_a[i] == a) {index = i;}
  }
  return index;
}

// void InsertionSort(int list[])
// {
//   /* Write your code here */	
//   int i, j, thres;
//   for (i = 1; i < MAX_NUMS; i++) {
//     // check from the fist to the last of the list
//     thres = list[i];
//     // compare thres from thres-1 to 0 in descending order
//     // if thres is smaller, than the compared (j) goes to right (j+1)
//     for (j = i-1; thres <list[j] && j>=0; j--){
//       list[j+1] = list[j];
//     }
//     // if thres is bigger, than the right (j+1) of the compared (j) becomes the thres
//     list[j+1] = thres;
//   }
// }