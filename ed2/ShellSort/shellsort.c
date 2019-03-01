#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "shellsort.h"

void gerarVetor(int *v, int n){
    srand((unsigned) time (NULL));
    int i;
    for(i = 0; i < n; i++)
        //Gera elementos aleatorios entre 1 e 100
        v[i] = 1 + rand()%100;
}

void mostrarIncrementos (int *v, int n, int inc){
    int i, j;
    //'inc' e o incremento 'h' que veio por parametro
    for(i = 0; i < inc; i++){
        printf("%d.\n", i+1);
        //mostra o subvetor gerado de acordo com 'inc'
        for(j = i; j < n; j += inc)
            printf("[%d] ", v[j]);
        printf("\n\n");
    }
    printf("\n");
}

void mostrarVetor(int *v, int n){
    int i; //mostra todos os elementos do vetor
    for(i = 0; i < n; i++)
        printf("[%d] ", v[i]);
    printf("\n\n");
}

//implementacao do Shell Sort baseada nos slides
void shellSort (int data[], int arrSize){
    register int i, j, hCnt, h;
    int increments[20], k;
    for (h=1, i=0; h < arrSize; i++){
        increments[i] = h;
        h = 3*h + 1;
    }
    for (i--; i >= 0; i--) {
        h = increments[i];
        printf("Subvetores do incremento %d antes da ordenacao: \n\n", h);
        mostrarIncrementos(data, arrSize, h);
        for (hCnt = h; hCnt < 2*h; hCnt++) {
            for (j = hCnt; j < arrSize;){
                int tmp = data[j];
                k = j;
                while (k-h >= 0 && tmp < data[k-h]){
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;

                j += h;
            }
        }//mostra o andamento da ordenacao depois de cada incremento
        printf("Subvetores do incremento %d depois da ordenacao: \n\n", h);
        mostrarIncrementos(data, arrSize, h);
        printf("Ordem parcial do vetor (ordenacao com incremento %d): \n\n", h);
        mostrarVetor(data, arrSize);
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
    shellSort(v, n);
    printf("Vetor ordenado: \n");
    mostrarVetor(v, n);
}
