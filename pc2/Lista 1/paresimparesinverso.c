//Rafaella Silva Almeida
//Exercicio 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zerarVetor(int *vet, int dim);
void preencherVetor(int *vet, int dim);
int gerarVetorPares(int *vetor, int dim, int *pares);
int gerarVetorImpares(int *vetor, int dim, int *impares);
void inverterVetor(int *vet, int dim);
void mostrarVetor(int *vet, int dim);

int main(){
    srand(time(NULL));
    int dimpar, dimimpar, dim;
    //ler e validar dimensao
    do{
        printf("Ingresse uma dimensao valida para o vetor (maior que 0): ");
        scanf("%d", &dim);
    }while(dim < 0);
    int vetor[dim], pares[dim], impares[dim];
    //vetor principal
    zerarVetor(vetor, dim);
    preencherVetor(vetor, dim);
    printf("Vetor inicial: ");
    mostrarVetor(vetor, dim);
    //vetor pares
    zerarVetor(pares, dim);
    printf("Vetor invertido de pares: ");
    dimpar = gerarVetorPares(vetor, dim, pares);
    if(dimpar != 0){
        inverterVetor(pares, dimpar);
        mostrarVetor(pares, dimpar);
    }
    else
        printf("Nao ha pares no vetor inicial.\n");
    //vetor impares
    zerarVetor(impares, dim);
    printf("Vetor invertido de impares: ");
    dimimpar = gerarVetorImpares(vetor, dim, impares);
    if(dimimpar != 0){
        inverterVetor(impares, dimimpar);
        mostrarVetor(impares, dimimpar);
    }
    else
        printf("Nao ha impares no vetor inicial.\n");
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

//separar os elementos pares
int gerarVetorPares(int *vetor, int dim, int *pares){
    int i, dimpar = 0;
    for(i = 0; i < dim; i++)
        if(vetor[i] %2 == 0){
            pares[dimpar] = vetor[i];
            dimpar++;
            }
    return dimpar;
}

//separar os elementos impares
int gerarVetorImpares(int *vetor, int dim, int *impares){
    int i, dimimpar = 0;
    for(i = 0; i < dim; i++)
        if(vetor[i] %2 != 0){
            impares[dimimpar] = vetor[i];
            dimimpar++;
            }
    return dimimpar;
}

//inverte os elementos do vetor
void inverterVetor(int *vet, int dim){
    int i, aux;
    for(i = 0; i < dim/2; i++){
        aux = vet[i];
        vet[i] = vet[dim-i-1];
        vet[dim-i-1] = aux;
    }
}

//imprime o conteudo do vetor
void mostrarVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        printf("%d ", vet[i]);
    printf("\n");
}




