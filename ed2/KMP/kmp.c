#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"

int *computePrefixFunction(char *padrao, int m){
	int k = -1;
	int q;
	int *pi = (int*)malloc(sizeof(int)*m);
	if (!pi)
		return NULL;
	pi[0] = k;
	for (q = 1; q < m; q++) {
		while (k > -1 && padrao[k+1] != padrao[q])
			k = pi[k];
		if (padrao[q] == padrao[k+1])
			k++;
		pi[q] = k;
	}
	return pi;
}

void kmpMatcher(char *texto, int n, char *padrao, int m){
	int i, flag = 0;
	int *pi = computePrefixFunction(padrao, m);
	int q = -1;
	if (!pi){
        printf("ERRO! Memoria nao foi alocada corretamente.\n");
		return;
	}
	for (i = 0; i < n; i++) {
		while (q > -1 && padrao[q+1] != texto[i])
			q = pi[q];
		if (texto[i] == padrao[q+1])
			q++;
		if (q == m - 1) {
            flag = 1;
			printf("Padrao ocorre com deslocamento %d.\n", i-m+1);
			q = pi[q];
		}
	}
	if(!flag)
        printf("Nao houve emparelhamento.\n");
	free(pi);
}

void compara(){
    char op = 's';
    char texto[100], padrao[100];
    do{
        system("CLS");
        printf("========== Algoritmo KMP ==========\n\n");
        printf("Digite o texto: ");
        scanf("%[^\n]", texto);
        fflush(stdin);
        printf("\nDigite o padrao: ");
        scanf("%[^\n]", padrao);
        fflush(stdin);
        printf("\n");
        kmpMatcher(texto, strlen(texto), padrao, strlen(padrao));
        printf("\nDeseja continuar? (S)im / (N)ao\n");
        scanf(" %c", &op);
        fflush(stdin);
    }while(op == 's' || op == 'S');
    printf("\nEncerrando...\n");
}
