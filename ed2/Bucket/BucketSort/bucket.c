#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bucket.h"

int* tamanhoVetores(){
    int *tam = (int*) malloc (5*sizeof(int));
    //tamanhos dos vetores a serem ordenados
    tam[0] = 10;
    tam[1] = 100;
    tam[2] = 1000;
    tam[3] = 10000;
    tam[4] = 100000;
    return tam;
}

void gerarVetor(int v[], int n){
    srand((unsigned) time (NULL));
    int i;
    for(i = 0; i < n; i++)
        v[i] = 1 + rand() % 10;
}

void bucketSort(int *v, int n){
    int i, j;
    int b[n];
    for (i = 0; i < n; i++)
        b[i] = 0;
    for (i = 0; i < n; i++)
        (b[v[i]])++;
    for (i = 0, j = 0; i < n; i++)
        for(; b[i] > 0; (b[i])--)
            v[j++] = i;
}

void ordenarVetores(){
    //abre arquivo onde serao armazenados os resultados
    FILE *resultados;
    if((resultados = fopen("resultados.csv", "a")) == NULL){
        printf("Erro na abertura do arquivo de resultados.\n\n");
        return;
    }
    //grava cabecalho da tabela de resultados
    fprintf(resultados, "Tamanho;Tempo médio\n");
    time_t t1, t2; //mede o tempo de execucao
    int i, j, *tam = tamanhoVetores();
    float tempo; //tempo medio de execucao
    for(i = 0; i < 5; i++){
        int v[tam[i]];
        tempo = 0;
        fprintf(resultados, "%d;", tam[i]);
        //para o tamanho 'tam[i]' gera 1000 vetores
        for(j = 1; j <= 1000; j++){
            gerarVetor(v, tam[i]);
            time(&t1); //tempo antes
            //executa o metodo
            bucketSort(v, tam[i]);
            time(&t2); //tempo depois
            //soma o resultado ao tempo total
            tempo += (t2 - t1);
        }
        //salva no arquivo o tempo medio das 1000 execucoes para o tamanho 'tam[i]'
        printf("Tempo medio de execucao para vetores de tamanho %d: %f\n\n", tam[i], tempo/1000);
        fprintf(resultados, "%f\n", tempo/1000);
    }
    //fecha arquivos
    fclose(resultados);
    //libera memoria associada a 'tam'
    free(tam);
    printf("Vetores ordenados! Conferir arquivo de resultados.\n");
}

void principal(){
    printf("Ordenacao Bucket Sort\n\n");
    printf("Implementacao e avaliacao de desempenho\n\n");
    ordenarVetores();
}


