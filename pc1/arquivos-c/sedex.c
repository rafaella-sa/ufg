#include <stdio.h>
void main(){
	int N, A, L, P;
	scanf("%d", &N);
	scanf("%d %d %d", &A, &L, &P);
	if (N <= A && N <= L && N <= P)
		printf("S \n");
	else
		printf("N \n");
}
