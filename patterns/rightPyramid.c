#include<stdio.h>
// Make a rightPyramid
int main() {
	int N; // How long the pyramid should be
	scanf("%d", &N);
	// rows
	for (int r = 1; r <= N; r++) {
		// Displacement Spaces
		for (int sp = 1; sp <= N-r; sp++) {
			printf(" ");
		}
		for (int s = 1; s <= r; s++) {
			printf("*");
		}
		printf("\n");
	}
}
