#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"

int particiona(int *v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo) esq++;
        while(v[dir] > pivo) dir--;
        if (esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int *v, int inicio, int fim){
    if(inicio < fim){
        int pivo;
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}
