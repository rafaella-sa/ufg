#include <stdio.h>
void main (){
	int r, a1, n, an;
	printf("Ingresse a razão 'r' e o primeiro termo 'a1': \n");
	scanf("%d %d", &r, &a1);
	printf("Ingresse a posição 'n' do termo da P.A.: \n");
	scanf("%d", &n);
	an = a1 + (n - 1) * r;
	printf("O termo %d da P.A. é %d. \n", n, an);
} 
 
	
	
