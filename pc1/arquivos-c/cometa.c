#include <stdio.h>
void main(){
	int ano, atual, n, r;
	ano = 1986;
	n = 1;
	r = 76;
	printf("Ingresse o ano atual: ");
	scanf("%d", &atual);
	while(ano <= atual){
		n++;
		ano = 1986 + (n-1) *r;
	}
	printf("A próxima passagem do cometa será em %d. \n", ano);
}
