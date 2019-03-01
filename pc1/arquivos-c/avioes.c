#include <stdio.h>
void main(){
	int C, P, F, comp;
	scanf("%d %d %d", &C, &P, &F);
	comp = P/F;
	if (C <= comp)
		printf("S \n");
	else
		printf("N \n");
	}
