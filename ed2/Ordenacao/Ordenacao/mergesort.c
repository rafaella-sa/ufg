#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"

void mergeS(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tam, i, j, k;
    int fim1 = 0, fim2 = 0;
    tam = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int*) malloc (tam * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tam; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                if(p1>meio) fim1 = 1;
                if(p2>fim) fim2 = 1;
            }else{
                if(!fim)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        for(j = 0, k = inicio; j < tam; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        mergeS(v, inicio, meio, fim);
    }
}
