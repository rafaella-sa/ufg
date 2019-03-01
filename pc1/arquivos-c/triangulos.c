#include <stdio.h>
void main(){
	int N1, N2, N3;
	scanf("%d %d %d", &N1, &N2, &N3);
	if(N1 == N2 && N2 == N3)
		printf("E \n");
	else if (N1 == N2 || N2 == N3 || N1 == N3)
		printf("I \n");
	else if (N1 < N2 + N3 && N2 < N1 + N3 && N3 < N1 + N2)
		printf("S \n");
    else
		printf("N \n");
}
