#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
// Variables
const char 
RESULT_CHARACTER = 'x',
DIV_SYMBOL = '-';
// Functions
void printHeader(short vars) {
	char c = 'A';
	// Print Variables
	for (int i = 0; i < vars; i++) {
		printf("%c\t", c);
		c++; // By adding we go to next char
	}
	printf("%c\n", RESULT_CHARACTER);
	// Print divider
	for (int i = 0; i <= vars; i++)
		printf("%c\t", DIV_SYMBOL);
	printf("\n");
}
// Initializer function
void init(bool *ptr, short size) {
	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}
void prntIndex(short s, short e, bool *ptr) {
	for (int i = s; i <= e; i++)
		printf("%d\t", ptr[i]);
}
//What the hell
void increment(bool *ptr, short size, short bit) {
	size--;
	for (int i = size; i >= 0; i--) {
			ptr[i] = (bit) & 1; // GET LSB
			bit = bit >> 1;
		}
}
//Main
int main() {
	// We should Take N variable inputs
	unsigned short int N, rows; // Because we are not doing for so many variables
	printf("Enter the amount of variables: ");
	scanf("%hi", &N);
	printHeader(N);
	bool *digits = malloc(N * sizeof(bool));
	init(digits,N);
	// Begin counting, for N variables there is 2^n rows i guess
	rows = pow(2,N);
	for (int i = 0; i < rows; i++) {
	increment(digits,N, i);
	prntIndex(0,N-1,digits);
	printf("\n");
	}
	free(digits);

}
