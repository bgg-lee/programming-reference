#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Use structs below if you need.
typedef struct StackNode {
    char character;
    int count;
    struct StackNode* next;
} StackNode;

StackNode* push(StackNode* top, char ch, int count) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->character = ch;
    newNode->count = count;
    newNode->next = top;
    return newNode;
}

StackNode* pop(StackNode* top) {
    if (top == NULL) return NULL;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
}

char* function4(char* s, int k) {
    //Write your code
}

// Feel free to construct functions you need. 
// Submit functions.h file.

// compile command: g++ -o main main.c
// execute command: 
//             ./main "accassl" 2 # answer: l