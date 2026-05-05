#include<stdio.h>
/*
  DO NOT COMPILE BEFORE FIXING THIS FILE
  THIS FILE IS WIP
*/

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
	int rowsTotal = 2*N-1;
	for (int r = 1; r <= rowsTotal; r++) {
			// First half till the peak
			for (int s1 = 1; s1 <= r; s1++) {
				printf("*");
			}
			// Second half
			for (int s2 = N+1; s2 <= rowsTotal-r; s2++) {
				printf("*");
			}
			printf("\n");
		}
}
