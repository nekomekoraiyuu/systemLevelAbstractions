#include<stdio.h>
/* Pyramid In Question:
 * for N = 4
			*
		*	*	*
	*	*	*	*	*
*	*	*	*	* 	*	*
*/
// We can try dividing the problem into 3 parts i guess
// We need n - 1 spaces
int main() {
	int N;
	scanf("%d", &N);
	// r is rows
	for (int r = 1; r <= N; r++) {
		for (int sp = 1; sp <= N-r; sp++) {
			printf(" ");
		}
		for (int s1 = 1; s1 <= r; s1++) {
			printf("*");
		}
		for (int s2 = 1; s2 <= r-1; s2++) {
			printf("*");
		}
		printf("\n");
	}
}
