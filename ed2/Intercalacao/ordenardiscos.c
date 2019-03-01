#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "intercalar.h"
//N: quantidade de elementos que se pode ter na memoria
#define N 100000
//DISCOS: quantidade de 'discos' (arquivos) disponiveis
#define DISCOS 4

int comparaCrescente(const void *a, const void *b){
    if(*(int*)a == *(int *)b) return 0; //iguais
    else if(*(int*)a < *(int *)b) return -1; //vem antes
    else return 1; // vem depois
}

void gravarArquivo(){
    //abre arquivo
    FILE *f = fopen("registros.bin", "a+b");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    //variaveis
    int i, j;
    int registros[N];
    printf("Gravando elementos...\n\n");
    //gera vetores
    srand((unsigned) time (NULL));
    for(j = 1; j <= 150; j++){
        for(i = 0; i < N; i++)
            registros[i] = 1 + rand() % 100000;
        fwrite(registros, sizeof(registros[0]), N, f);
    }
    //fecha arquivo
    fclose(f);
}

void gerarArquivosOrdenados(){
    //variaveis
    int i, total, buffer[N];
    //abre o arquivo original
    FILE *f;
    f = fopen("registros.bin", "rb");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    printf("Ordenando elementos em discos...\n\n");
    //gera quatro 'discos' (arquivos)
    i = 1;
    do{ //le uma quantidade de elementos
        total = fread(buffer, sizeof(buffer[0]), N, f);
        if(total == N){ //se foi lida uma quantidade correta
            //ordena esta quantidade pelo metodo 'quicksort'
            qsort(buffer, total, sizeof(int), comparaCrescente);
            //abre o disco
            char nome[15];
            snprintf(nome, sizeof(nome), "disco%d.bin", i++);
            FILE *disco = fopen(nome, "a+b");
            if(disco == NULL){
                printf("Erro na abertura do arquivo.\n\n");
                return;
            }
            //guarda os dados ordenados
            fwrite(buffer, sizeof(buffer[0]), total, disco);
            //fecha o 'disco'
            fclose(disco);
            if(i > DISCOS) i = 1; //serve para alternar entre os
                                  //quatro arquivos
        }
    }while(!feof(f)); //enquanto nao termina o arquivo original
    if(total > 0){ //se a divisao nao for exata, salva o restante
        qsort(buffer, total, sizeof(int), comparaCrescente);
        char nome[15];
        snprintf(nome, sizeof(nome), "disco%d.bin", i);
        FILE *disco = fopen(nome, "a+b");
        if(disco == NULL){
            printf("Erro na abertura do arquivo.\n\n");
            return;
        }
        fwrite(buffer, sizeof(buffer[0]), total, disco);
        fclose(disco);
    }
    fclose(f);
    printf("Discos ordenados!\n\n");
}
