#include<stdio.h>
#include<ctype.h>
#define IS_LOWER(x) ((x) >= 'a' && (x) <= 'z')
#define IS_UPPER(x) ((x) >= 'A' && (x) <= 'Z')
#define IS_ALPHA(x) (IS_UPPER(x) || IS_LOWER(x))
void flush() {
	unsigned char c;
	while ((c = getchar()) != '\n');
}
int mod(int a, int b) {
	return ((a%b)+b)%b;
}
void encrypt(int k) {
	unsigned char c;
	printf("-- Encrypt!\n");
	// Read Till \n
	while ((c = getchar()) != '\n') {
		// Check if lower or uppercase
		if (IS_ALPHA(c)) {
			// If its uppercase convert back to lower
			if (IS_UPPER(c)) {
				c = tolower(c);
			}
			// Main Logic
			c = (mod((c-'a'+k),26))+'a';
			k++;
			k = mod(k,12);
			printf("%c", c);

		}
		else {
			switch (c) {
				case ' ':
					printf("^");
					break;
				case '^':
					printf(" ");
					break;
				default:
					printf("%c", c);
					break;
			}
		}
	}
	// End
	printf("\n");
}
void decrypt(int k) {
	unsigned char c;
	printf("-- Decrypt!\n");
	while ((c = getchar()) != '\n') {
		// Check if lower or uppercase
		if (IS_LOWER(c)) {
			// If its uppercase convert back to lower
			// Main Logic
			c = (mod((c-'a'-k),26))+'a';
			k++;
			k = mod(k,12);
			printf("%c", c);
		}
		else {
			switch (c) {
				case ' ':
					printf("^");
					break;
				case '^':
					printf(" ");
					break;
				default:
					printf("%c", c);
					break;
			}
		}
	}
	// End
	printf("\n");
}
int main() {
	unsigned char c;
	int k;
	printf("komekrypt2>\n");
	printf("enter K: ");
	scanf("%d", &k);
	printf("Select mode\n[e]ncrypt\n[d]ecrypt\n");
	flush();
	scanf("%c", &c);
	flush();
	if (c == 'e')
		encrypt(k);
	else if (c == 'd')
		decrypt(k);
	else {
		printf("What");
		return 1;
	}
	return 0;
}
