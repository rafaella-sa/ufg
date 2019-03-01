#include <stdio.h>
void main(){
	int P, Q, conta, over;
	char sinal;
	scanf("%d", &over);
	scanf("%d %c %d", &P, &sinal, &Q);
	if (sinal == '+')
		conta = P + Q;
	else
		conta = P * Q;
	if (conta <= over)
		printf ("OK \n");
	else
		printf ("OVERFLOW \n");
}
