#include <stdio.h>
void main(){
	int A, B, C, X, Y, Z, altura, areac, arean, cont, quant;
	printf("Ingresse as dimensoes do container: ");
	scanf("%d %d %d", &A, &B, &C);
	printf("Ingresse as dimensoes do navio: ");
	scanf("%d %d %d", &X, &Y, &Z);
	cont = 0;
	areac = A * B;
	arean = X * Y;
	quant = arean/areac;
	altura = C;
	while(altura <= Z){
	  altura = altura + C;
	  cont++;
	}
	quant = quant * cont;
	printf("A quantidade de containers é %d. \n", quant);
}
