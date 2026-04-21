#include<stdio.h>
// pattern in question:
// peak starts at n = 5
/*
				*
			*	*
		*	*	*
	*	*	* 	*
*	*	*	*	*
	*	*	*	*
		*	*	*
			*	*
				*
*/
// we should try diving the problem in half
int main() {
	int N;
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		// done with the spaces
		for (int sp = 1; sp <= N-r; sp++) {
			printf(" ");
		}
		for (int s1 = 1; s1 <= r; s1++) {
			printf("*");
		}
		printf("\n");
	}
	for (int r = 1; r <= N-1; r++) {
		// deal with the spaces
		for (int sp = 1; sp <= r; sp++) {
			printf(" ");
		}
		for (int s2 = 1; s2 <= N-r; s2++) {
			printf("*");
		}
		printf("\n");
	}
}
