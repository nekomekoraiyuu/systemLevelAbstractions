#include<stdio.h>
// The pattern in question
/*

*
**
***
****
*****
****
***
**
*

*/
// do you see a pattern?
// yeah so it increases till some peak is reached like 5 ASTERISKS here
// you dont need to think about the total N length just about the peaks.
// Okay divide the problem in half
/*
 * first half is till the peak
 * last is the rest
*/
// Observing this we can see the total row is just N+N-1 = 2N-1
// Input N is the peak!!!
int main() {
	int N; // Peak  at N th row
	scanf("%d", &N);
	// first half
	for (int r = 1; r <= N; r++) {
		for (int s1 = 1; s1 <= r; s1++) {
			printf("*");
		}
		printf("\n");
	}
	// Second half
	for (int r = 1; r <= N-1; r++) {
		for (int s2 = 1; s2 <= N-r; s2++) {
			printf("*");
		}
		printf("\n");
	}
}
