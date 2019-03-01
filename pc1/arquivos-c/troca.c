#include <stdio.h>
void main (){
	int a, b, troca;
	printf("Ingresse os valores de A e B: \n");
	scanf("%d %d", &a, &b);
	troca = a;
	a = b;
	b = troca;
	printf("%d %d \n", a, b);
}
