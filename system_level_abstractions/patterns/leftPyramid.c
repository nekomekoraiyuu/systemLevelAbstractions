#include<stdio.h>
// Print N length left pyramid
int main() {
	int N;
	scanf("%d", &N);
	// for row
	for (int r = 1; r <= N; r++) {
		// for column
		for (int s = 1; s <= r; s++) {
		printf("*");
		}
	printf("\n");
	}
}
