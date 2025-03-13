/* Description
 * Write a function to return an natural number in base 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	
int base_four(int n){
/* Please write your code below */
	int ans = 0;
	int power = 1;
	int mod = 0;

	while (n > 0) {
		// printf("n: %d, mod: %d ans: %d, power: %d\n", n, mod, ans, power); 
		mod = (n % 4); // mod = 3 -> 1
		n /= 4; // n = 7 -> 1 -> 0
		ans += ((mod) * power); // ans = 3 -> 13
		power *= 10; // power = 1 -> 10

		// printf("n: %d, mod: %d ans: %d, power: %d\n", n, mod, ans, power);
		
	}
  return ans;
	}

/* Do not modify below */



int main(int argc, char* argv[]){
	
	/* 
	argc: Store the number of arguments of program. 
	argv[]: Array for storing arguments of program. 
	The first value of argv[] is the name of program. 
	That is, if there is no argument, argc is 1 and argv[0] is the name of program. 
	*/

	// If the number of argument is not 1
	if (argc != 2){
		printf("Enter any natural number n\n");
		return 0;
	}

	// Store first argument into variable n
	int n = atoi(argv[1]);		

	// If n is smaller than 1
	if (n < 1){

		printf("No negative number is allowed\n");
		return 0;

	} else {

		int f = 0;
		// Execute base_four function. Then store the result into variable f
		f = base_four(n);
		// Print answer
		printf("%d\n",f);	
		return 0;

	}


}

