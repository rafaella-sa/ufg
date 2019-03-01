//Rafaella Silva Almeida
//Lista 7 - Exercício 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clube{
    char nome[30];
    int pontos;
}clube;

typedef struct campeonato{
    char nome[30];
    clube* clubes;
    }campeonato;

int main(){
    campeonato *torneios;
    torneios = (campeonato*)malloc(sizeof(campeonato)*2);
    if(torneios == NULL);
        exit(1);
    torneios[0].clubes = (clube*)malloc(sizeof(clube)*10);
    if(torneios[0].clubes == NULL);
        exit(1);
    torneios[1].clubes = (clube*)malloc(sizeof(clube)*5);
    if(torneios[1].clubes == NULL);
        exit(1);
    int i;
    printf("CAMPEONATO 1\n");
    printf("NOME: ");
    gets(torneios[0].nome);
    for(i = 0; i < 10; i++){
        printf("\nCLUBE %d\n", i+1);
        printf("NOME: ");
        gets(torneios[0].clubes[i].nome);
        printf("PONTUACAO: ");
        scanf("%d", &torneios[0].clubes[i].pontos);
        fflush(stdin);
    }
    printf("\nCAMPEONATO 2\n");
    printf("NOME: ");
    gets(torneios[1].nome);
    for(i = 0; i < 5; i++){
        printf("\nCLUBE %d\n", i+1);
        printf("NOME: ");
        gets(torneios[1].clubes[i].nome);
        printf("PONTUACAO: ");
        scanf("%d", &torneios[1].clubes[i].pontos);
        fflush(stdin);
    }
    printf("\nINFORMACOES DO CAMPEONATO 1\n");
    printf("NOME: %s\n", torneios[0].nome);
    for(i = 0; i < 10; i++){
        printf("\nCLUBE %d\n", i+1);
        printf("NOME: %s\n", torneios[0].clubes[i].nome);
        printf("PONTUACAO: %d\n", torneios[0].clubes[i].pontos);
    }
    printf("\nINFORMACOES DO CAMPEONATO 2\n");
    printf("NOME: %s\n", torneios[1].nome);
    for(i = 0; i < 5; i++){
        printf("\nCLUBE %d\n", i+1);
        printf("NOME: %s\n", torneios[1].clubes[i].nome);
        printf("PONTUACAO: %d\n", torneios[1].clubes[i].pontos);
    }
    free(torneios[1].clubes);
    free(torneios[0].clubes);
    free(torneios);
    return 0;
}
