#include<stdio.h>
// Pattern in question: for peak n = 3

/*

*				*
*	*		*	*
*	*	*	*	*
*	*		*	*
*				*
*/
int main() {
	int N; // peak
	scanf("%d", &N);
	// First half
	for (int r = 1, spCount = (2*N-1); r <= N; r++) {
		for (int s1 = 1; s1 <= r; s1++) {
			printf("*");
		}
		// calculate the space count
		spCount -= 2; // because there are asterisks on the both sides and they increase for every row
		for (int sp = 1; sp <= spCount; sp++) {
			printf(" ");
		}
		for (int s2 = 1, max = N-1; s2 <= r && s2 <= max; s2++) {
			printf("*");
		}
		// end	
		printf("\n");
	}
	// second half
	for (int r = 1, spCount = 1; r <= N-1; r++) {
		for (int s1 = 1; s1 <= N-r; s1++) {
			printf("*");
		}
		for (int sp = 1; sp <= spCount; sp++) {
			printf(" ");
		}
		for (int s2 = 1; s2 <= N-r; s2++) {
			printf("*");
		}
		printf("\n");
		spCount += 2;
	}
}
