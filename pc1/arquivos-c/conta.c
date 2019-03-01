#include <stdio.h>
void main(){
	int N, conta, aux;
	scanf("%d", &N);
	conta = 7;
	if (N > 10 && N <= 30){
		aux = N - 10;
		aux = aux * 1;
		conta = conta + aux;
	}
	else if (N > 30 && N <= 100){
		conta = conta + 20;
		aux = N - 30;
		aux = aux * 2;
		conta = conta + aux;
	}
	else if (N > 100){
		conta = conta + 20 + 140;	
		aux = N - 100;
		aux = aux * 5;
		conta = conta + aux;
	}
	printf("%d \n", conta);
}
	
		 
