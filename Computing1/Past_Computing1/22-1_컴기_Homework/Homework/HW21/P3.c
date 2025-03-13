#include <stdio.h>
#include <stdlib.h>

int InputInclude(int n, int *arr, int length);

/* Linked list node structure */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to create a new node */
struct Node * createNode(struct Node * newNode, int data){
  newNode = (struct Node *) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int main(int argc, char* argv[])
{  
  /* length: the length of input arguments (except for inputList.txt) */
  int length = argc - 2;
  /* inputArr: array of input arguments (except for inputList.txt) */
  int * inputArr = (int *) malloc(sizeof(int) * length);
  /* filepath: path for inputList.txt which will be give as a first argument */
  char * filepath = argv[1]; 

  /* Create inputArr */
  for (int i = 0; i < length; ++i){
    inputArr[i] = atoi(argv[i+2]);
  }

  /* Create a linked list from file input */
  int k = 1;
  struct Node* head = NULL;
  struct Node* prev = NULL;
  struct Node* curr = NULL;

  FILE *fp = fopen(filepath, "r");
  char buffer[10]; 
  
  while (fscanf(fp, "%s", buffer) == 1){
    curr = createNode(curr, atoi(buffer));  
    if (k > 1){
      prev->next = curr;
    }
    else{
     head = curr;
    }
    k++;
    prev = curr;
  }

  fclose(fp);
  
  /* numConnected: the number of connected "cluster" */
  int numConnected = 0;

  /* 
   * TODO: Your code starts here
   */	
  curr = head;
  struct Node* head2 = NULL;
  struct Node* prev2 = NULL;
  struct Node* curr2 = NULL;
  int p = 1;
  
  while (curr){
    if (InputInclude(curr->data, inputArr, length) == 1) {
      curr2 = createNode(curr2, 1);
    }
    else {
      curr2 = createNode(curr2, 0);
    }
    if (p>1) {prev2->next = curr2;}
    else {head2 = curr2; }
    p++;
    prev2 = curr2;
    curr = curr->next;
    }
  
  curr = head2;
  while(curr){
    if (curr->data == 1){
      if (curr->next == NULL) numConnected ++;
      else if (curr->next->data == 0) numConnected ++;}
    curr = curr-> next;
  }

  // curr = head2; // print the SLL of head2
  // while (curr){
  //   printf("%d", curr->data);
  //   curr = curr->next;
  // }

	/* 
   * Do not modify below 
   */	

  printf("%d", numConnected);

  return 0;

}

int InputInclude(int n, int *arr, int length) {
  for (int i = 0; i < length; i++){
    // printf("i : %d\n", i);
    if (arr[i] == n) {
      // printf("arr[i] : %d, i : %d, n : %d\n",arr[i], i, n);
      return 1;}
  }
  return 0;
}
