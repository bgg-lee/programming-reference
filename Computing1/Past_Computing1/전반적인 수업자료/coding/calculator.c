#include <stdio.h>

int main(void){
    int operand1, operand2;
    int result = 0;
    char operation;

    printf("Enter first operand: ");
    scanf("%d", &operand1);
    
    printf("Enter the operation to perform: ");
    scanf("\n%c", &operation);
    
    printf("Enter second operand: ");
    scanf("%d", &operand2);

    switch (operation){
        case '+':
        result = operand1 + operand2;
        break;

        case '-':
        result = operand1 - operand2;
        break;

        case '*':
        result = operand1 * operand2;
        break;

        case '/':
        result = operand1 / operand2;
        break;
        
    }
    printf("The result is %d\n", result);
    return 0;
}