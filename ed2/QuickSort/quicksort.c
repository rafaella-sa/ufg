#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quicksort.h"

void gerarVetor(int *v, int n){
    srand((unsigned) time (NULL));
    int i;
    for(i = 0; i < n; i++)
        //Gera elementos aleatorios entre 1 e 100
        v[i] = 1 + rand()%100;
}

void mostrarVetor(int *v, int n){
    int i; //mostra todos os elementos do vetor
    for(i = 0; i < n; i++)
        printf("[%d] ", v[i]);
    printf("\n\n");
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *v, int inicio, int fim, int n){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        //nos dois lacos a seguir, troca-se o sinal
        //de comparacao para que se ordene de forma
        //decrescente o vetor
        while(v[esq] >= pivo) esq++;
        while(v[dir] < pivo) dir--;
        if (esq < dir){
            troca(&v[esq], &v[dir]);
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    //mostra o estado atual do vetor
    printf("Ordem parcial:\n");
    mostrarVetor(v, n);
    return dir;
}

void quickSort(int *v, int inicio, int fim, int n){
    if(inicio < fim){
        int pivo = particiona(v, inicio, fim, n);
        quickSort(v, inicio, pivo-1, n);
        quickSort(v, pivo+1, fim, n);
    }
}

void principal(){
    int n;
    do{ //leitura e verificacao do tamanho do vetor
        printf("Ingresse o tamanho do vetor (valor maior que 0): ");
        scanf("%d", &n);
    }while(n <= 0);
    int v[n];
    printf("\nVetor original:\n");
    gerarVetor(v, n);
    mostrarVetor(v, n);
    quickSort(v, 0, n-1, n);
    printf("Vetor ordenado: \n");
    mostrarVetor(v, n);
}
