#include<stdio.h>

// the pattern in question
/*

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

*/

/* so
    we are gonna use the binomial theorem
    for j th term for i th max power
    C(i,j) = i!/j!(i-j)!
    since computing the factorials is very cpu expensive we are just gonna 
    do a little trick by getting the next term from the previous term
    for j-1 term
    C(i,j-1) = i!/(j-1)!(i-j+1)! [note -(j-1) = -j+1]
    to set up a relation take the ratios
    C(i,j)/C(i,j-1) = [i!/j!(i-j)!] / [i!/(j-1)!(i-j+1)!]
    => C(i,j)/C(i,j-1) = [(j-1)!/j! * (i-j+1)!/(i-j)!]
    we know that (n-1)!/n! = 1/n
    so
    C(i,j)/C(i,j-1) = i-j+1/j
    => C(i,j) = C(i,j-1) * i-j+1/j
    now we can just put i and j
   */
int main() {
	int i,j,t,s; // t is our prev term ,, s is our space
	short n = 5; // max n 
	for (i = 0; i < n; i++) {
		t = 1;
		for (s = 0; s < n-i; s++)
			printf(" ");
		for (j = 0; j <= i; j++) {
			printf("%d ", t);
			t = t * (i-j)/(j+1); // we do this after printing because since j starts at 0 we will get division by 0 error.
		}
		printf("\n");
	}
}
