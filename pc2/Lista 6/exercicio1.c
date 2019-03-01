//Rafaella Silva Almeida
#include <stdio.h>

void imprimirVetor(int *p, int dim){
    int i, *aux = p;
    for(i = 0; i < dim; i++){
        printf("%d ", *p);
        p++;
    }
    p = aux;
}

int main(){
    int i, dim;
    do{
        printf("Ingresse a dimensão do vetor: ");
        scanf("%d", &dim);
    }while(dim <=0);
    int vet[dim], dobro[dim];
    int *pv = vet;
    int *pd = dobro;
    printf("Ingresse os elementos do vetor: ");
    for(i = 0; i < dim; i++){
        scanf("%d", pv);
        *pd = 2 * (*pv);
        pv++;
        pd++;
    }
    pv = vet;
    pd = dobro;
    printf("Vetor original: ");
    imprimirVetor(pv, dim);
    printf("\nVetor com valores dobrados: ");
    imprimirVetor(pd, dim);
    return 0;
    }
