#include<stdio.h>
// This is just spaghetti code bruh
// The pattern in question for n = 3
/*

*****
 ***
  *
 ***
*****
*/
int main() {
	int N;
	scanf("%d", &N); // peak
	// first half
	int sp = 0, asterisks = (2*N)-1;
	for (int r = 1; r <= N; r++) {
		for (int space = 1; space <= sp; space++) {
			printf(" ");
		}
		for (int s1 = 1; s1 <= asterisks; s1++) {
			printf("*");
		}
		asterisks -= 2;
		sp++;
		printf("\n");
	}
	sp--;
	asterisks = 1;
	for (int r = 1; r <= N-1; r++) {
		sp--;
		asterisks += 2;
		for (int space = 1; space <= sp; space++) {
			printf(" ");
		}

		for (int s2 = 1; s2 <= asterisks; s2++) {
			printf("*");
		}
		printf("\n");
	}
}
