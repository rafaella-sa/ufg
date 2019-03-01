#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "intercalar.h"
//N: quantidade de elementos que se pode ter na memoria
#define N 100000
//DISCOS: quantidade de 'discos' (arquivos) disponiveis
#define DISCOS 4

//MAX: total de elementos
//buffer: dados que o arquivo contem
//pos: posicao atual do elemento
struct arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

void preencheBuffer(struct arquivo *arq, int K){
    //se o arquivo esta vazio, termina a execucao
    if(arq->f == NULL) return;
    arq->pos = 0;
    arq->MAX = 0;
    //se nao chegou ao fim do arquivo
    if(!feof(arq->f)) //le K elementos e armazena no buffer correspondente
        arq->MAX = fread(arq->buffer, sizeof(arq->buffer[0]), K, arq->f);
    else{ //se esta vazio, fecha o arquivo
        fclose(arq->f);
        arq->f = NULL;
        return;
    }
}

int buscaMenorValor(struct arquivo *arq, int K, int *menor){
    int i, j = -1; //j: posicao do menor elemento no buffer
    //procura elemento nos buffers dos discos
    for(i = 0; i < DISCOS; i++){
        if(arq[i].pos < arq[i].MAX){
            if(j == -1)
                j = i;
            else{
                if(arq[i].buffer[arq[i].pos] < arq[j].buffer[arq[j].pos])
                    j = i;
            }
        }
    }
    if(j != -1){ //se achou o menor elemento
        //passa o elemento por parametro
        *menor = arq[j].buffer[arq[j].pos];
        //"anda" no arquivo e passa mais elementos para o buffer
        arq[j].pos++;
        if(arq[j].pos == arq[j].MAX)
            preencheBuffer(&arq[j], K);
        return 1;
    }else return 0;
}

void mergeExterno(){
    //abre arquivo original para receber os dados ordenados
    FILE *fi;
    fi = fopen("registros.bin", "wb");
    if(fi == NULL){
        printf("Erro na abertura do arquivo O.\n\n");
        return;
    }
    //K: memoria associada a cada buffer
    int i, K = N/(DISCOS + 1);
    char nome[15];
    int *buffer = (int*) malloc (K * sizeof(int));
    //estrutura que gerencia os discos
    struct arquivo* arq;
    arq = (struct arquivo*) malloc (DISCOS * sizeof(struct arquivo));
    //para cada disco
    for(i = 0; i < DISCOS; i++){
        //abre o arquivo
        snprintf(nome, sizeof(nome), "disco%d.bin", i+1);
        arq[i].f = fopen(nome, "rb");
        if(arq[i].f == NULL){
            printf("Erro na abertura do arquivo %d.\n\n", i+1);
            return;
        }
        //cria e preenche um buffer
        arq[i].buffer = (int*) malloc (K * sizeof(int));
        arq[i].MAX = 0;
        arq[i].pos = 0;
        preencheBuffer(&arq[i], K);
    }
    int menor, cont = 0;
    //procura o menor elemento
    while(buscaMenorValor(arq, K, &menor) == 1){
        //se achou, retira do buffer do disco e
        //passa para o buffer do arquivo final
        buffer[cont] = menor;
        cont++;
        //se ja esgotou a memoria do buffer
        if(cont == K){ //guarda os elementos e 'esvazia' o buffer
            fwrite(buffer, sizeof(buffer[0]), K, fi);
            cont = 0;
        }
    }
    if(cont != 0) //se a conta nao foi exata
        //guarda os elementos restantes
        fwrite(buffer, sizeof(buffer[0]), cont, fi);
    //libera memoria
    for(i = 0; i < DISCOS; i++)
        free(arq[i].buffer);
    free(arq);
    free(buffer);
}

void menu(){
    gravarArquivo();
    gerarArquivosOrdenados();
    mergeExterno();
}
