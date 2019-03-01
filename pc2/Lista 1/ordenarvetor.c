//Rafaella Silva Almeida
//Exercicio 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zerarVetor(int *vet, int dim);
void preencherVetor(int *vet, int dim);
void ordenarVetorMenor(int *vet, int dim);
void ordenarVetorMaior(int *vet1, int *vet2, int *resul);
void mostrarVetor(int *vet, int dim);

int main(){
    srand(time(NULL));
    int vet1[10], vet2[10], resul[20];
    //vetor 1
    preencherVetor(vet1, 10);
    ordenarVetorMenor(vet1, 10);
    printf("Vetor 1: ");
    mostrarVetor(vet1, 10);
    //vetor 2
    preencherVetor(vet2, 10);
    ordenarVetorMenor(vet2, 10);
    printf("\nVetor 2: ");
    mostrarVetor(vet2, 10);
    //vetor resultado
    zerarVetor(resul, 20);
    ordenarVetorMaior(vet1, vet2, resul);
    printf("\nResultado: ");
    mostrarVetor(resul, 20);
    return 0;
}

//inicializar o vetor com valor '0' em todas as posicoes
void zerarVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        vet[i] = 0;
}

//preenche o vetor com inteiros aleatorios entre 0 e 10
void preencherVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        vet[i] = rand()%10;
}

//ordena os vetores de 10 elementos
void ordenarVetorMenor(int *vet, int dim){
    int i, j, aux;
    for(i = 0; i < dim-1; i++){
        for(j = i+1; j < dim; j++){
            if(vet[i]>vet[j]){
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
}

//ordena o vetor de 20 elementos
void ordenarVetorMaior(int *vet1, int *vet2, int *resul){
    int i, j, k, l;
    i = j = k = 0;
    do{
        if(vet1[i]<vet2[j]){
            resul[k] = vet1[i];
            i++;
            k++;
        }
        else{
            resul[k] = vet2[j];
            j++;
            k++;
        }
        if (i == 10){
            for(l = j; l < 10; l++){
                resul[k] = vet2[j];
                j++;
                k++;
            }
        }
        else if(j == 10){
            for(l = i; l < 10; l++){
                resul[k] = vet1[i];
                i++;
                k++;
                }
        }
    }while(k < 20);
}

//imprime o conteudo do vetor
void mostrarVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        printf("%d ", vet[i]);
}

