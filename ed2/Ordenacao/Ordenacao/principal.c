#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"

int* tamanhoVetores(){
    int *tam = (int*) malloc (10*sizeof(int));
    //tamanhos dos vetores a serem ordenados
    tam[0] = 10;
    tam[1] = 100;
    tam[2] = 1000;
    tam[3] = 10000;
    tam[4] = 20000;
    tam[5] = 30000;
    tam[6] = 50000;
    tam[7] = 100000;
    tam[8] = 200000;
    tam[9] = 300000;
    return tam;
}

void gerarVetor(int *v, int n){
    srand((unsigned) time (NULL));
    int i;
    for(i = 0; i < n; i++)
        //Gera elementos aleatorios entre 1 e 100
        v[i] = 1 + rand()%100;
}

void gravarVetores(){
    int i, n, *tam = tamanhoVetores();
    //arquivo que guarda os vetores gerados que serao
    //ordenados
    FILE *vetores;
    //abre o arquivo
    if((vetores = fopen("vetores.bin", "a+b")) == NULL){
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    //para todos os tamanhos de vetores armazenados em 'tam'
    for(i = 0; i < 10; i++){
        //gera um vetor com 'tam[i]' elementos
        int v[tam[i]];
        gerarVetor(v, tam[i]);
        //armazena e mostra quantos dados foram gravados
        n = fwrite(v, sizeof(v[0]), tam[i], vetores);
        printf("Numero de elementos gravados para o vetor de tamanho %d: %d\n\n", tam[i], n);
    }
    //fecha o arquivo
    fclose(vetores);
    //libera memoria associada a 'tam'
    free(tam);
}

void ordenarVetores(){
    //arquivo que guarda os resultados finais dos tempos de
    //execucao de cada metodo para cada vetor
    FILE *resultados;
    //arquivo que guarda os vetores gerados que serao
    //ordenados
    FILE *vetores;
    //abre os arquivos
    if((vetores = fopen("vetores.bin", "rb")) == NULL){
        printf("Erro na abertura do arquivo de vetores.\n\n");
        return;
    }
    if((resultados = fopen("resultados.csv", "a")) == NULL){
        printf("Erro na abertura do arquivo de resultados.\n\n");
        return;
    }
    printf("Ordenando...\n\n");
    //gera o cabecalho da tabela de tempos de execucao
    fprintf(resultados, "Tamanho;Shell Sort;Heap Sort;Merge Sort;Quick Sort;\n");
    //variaveis para medir o tempo
    time_t t1, t2;
    //variaveis auxiliares
    int i, *aux, *tam = tamanhoVetores();
    //para todos os tamanhos de vetor armazenados
    for(i = 0; i < 10; i++){
        //guarda o tamanho do vetor atual a ser ordenado
        fprintf(resultados, "%d;", tam[i]);
        //le o vetor do arquivo
        int v[tam[i]];
        fread(v, sizeof(v[0]), tam[i], vetores);
        //faz uma copia do vetor a ser ordenado
        //se ordenar o original, nao e possivel
        //verificar os outros metodos
        aux = v;
        //tempo antes da execucao
        time(&t1);
        //chamada do metodo de ordenacao
        shellSort(aux, tam[i]);
        //tempo depois da execucao
        time(&t2);
        //calcula e salva no arquivo o tempo de duracao
        //da execucao do metodo em segundos
        fprintf(resultados, "%ld;", t2 - t1);
        //o mesmo procedimento e repetido para os outros
        //metodos
        aux = v;
        time(&t1);
        heapSort(aux, tam[i]);
        time(&t2);
        fprintf(resultados, "%ld;", t2 - t1);
        aux = v;
        time(&t1);
        mergeSort(aux, 0, tam[i]);
        time(&t2);
        fprintf(resultados, "%ld;", t2 - t1);
        aux = v;
        time(&t1);
        quickSort(aux, 0, tam[i]);
        time(&t2);
        fprintf(resultados, "%ld;\n", t2 - t1);
    }
    //fecha arquivos
    fclose(resultados);
    fclose(vetores);
    //libera memoria associada a 'tam'
    free(tam);
    printf("Vetores ordenados! Conferir arquivo de resultados.\n");
}

void principal(){
    printf("Algoritmos de ordenacao eficientes\n");
    printf("Implementacao e avaliacao de desempenho\n\n");
    gravarVetores();
    ordenarVetores();
}
