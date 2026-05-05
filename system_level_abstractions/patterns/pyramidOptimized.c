#include<stdio.h>
/* Pyramid In Question:
			*
		*	*	*
	*	*	*	*	*
*	*	*	*	* 	*	*
*/
// Now we are gonna use direct expression 2n-1
// because look for every row the ASTERISKS increase by that factor
/* 
 
 if you couldnt derive it, its okay, you are not a bad programmer
 	its just you havent faced problems like this.
	Good luck practicing!!
	i know you can learn :>


*/
int main() {
	int N;
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		// Deal with the spaces
		for (int sp = 1; sp <= N-r; sp++) {
			printf(" ");
		}
		for (int s = 1; s <= (2*r-1); s++) {
			printf("*");
		}
		printf("\n");
	}

}
