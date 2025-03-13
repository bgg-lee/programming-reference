/* Description
 * Write a program that reads any english alphabet from the keyboard 
 * and prints every character from that character down 
 * to the character A in the order in which they appear in the ASCII table
 */

#include <stdio.h>

int main(void){
	
	//Holds intermediate count values
	char counter; 

	//Starting point for count down
	char input_char; 

	/* Please write your code below */
	printf("Enter any alphabet:");
	scanf("%c", &input_char);

  for (counter = input_char; counter >= 65; counter--){
    printf("%c", counter); // %c 문자
  }

	/* Do not modify below */
	return 0;
}

