//Rafaella Silva Almeida
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int menor(int *vet, int dim, int menorvalor){
    if(dim == 0)
        return menorvalor;
    else if(vet[dim-1]<menorvalor)
        return menor(vet, dim-1, vet[dim-1]);
    else
        return menor(vet, dim-1, menorvalor);
    }

int main(){
    srand(time(NULL));
    int i, dim;
    do{
        scanf("%d", &dim);
    }while(dim <= 0);
    int vet[dim];
    printf("Elementos no vetor: ");
    for(i = 0; i < dim; i++){
        vet[i] = rand()%100;
        printf("%d ", vet[i]);
    }
    printf("\nMenor valor no vetor: %d", menor(vet, dim-1, vet[dim-1]));
    return 0;
}
