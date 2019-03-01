//Rafaella Silva Almeida
//Lista 6 - Exercício 3

#include <stdio.h>

void imprimirVetor(int *p, int dim);
void preencherMatriz(int *matriz, int m, int n);
void imprimirMatriz(int *matriz, int m, int n);
void gerarVetoresdePares(int *matriz, int m, int n, int *vetor);

int main(){
    int i, m, n;
    do{
        printf("Ingresse as dimensoes da matriz: ");
        scanf("%d %d", &m, &n);
    }while(m <= 0 || n <= 0);
    int mat[m][n], vet[n];
    int *vetor = vet;
    int *matriz = mat[0];
    preencherMatriz(matriz, m, n);
    imprimirMatriz(matriz, m, n);
    gerarVetoresdePares(matriz, m, n, vetor);
    return 0;
}

void imprimirVetor(int *p, int dim){
    int i, *aux = p;
    for(i = 0; i < dim; i++){
        printf("%d ", *p);
        p++;
    }
    p = aux;
    printf("\n");
}

void preencherMatriz(int *matriz, int m, int n){
    int i, *inicio = matriz;
    printf("\n");
    for(i = 0; i < m*n; i++){
        printf("Digite o elemento %d da matriz: ", i+1);
        scanf("%d", &matriz[i]);
    }
    matriz = inicio;
}

void imprimirMatriz(int *matriz, int m, int n){
    int i, *inicio = matriz;
    printf("\nA matriz e: \n");
    for(i = 0; i < m*n; i++){
        printf("%d ", matriz[i]);
       if((i+1)%n == 0)
            printf("\n");
    }
    matriz = inicio;
    printf("\n");
}

void gerarVetoresdePares(int *matriz, int m, int n, int *vetor){
    int i, j, *iniciom = matriz, *iniciov = vetor, pares, linha = 1;
    for(i = 0; i < m*n; i+=n){
        pares = 0;
        for(j = i; j < n+i; j++){
            if(matriz[j]%2==0){
                vetor[pares] = matriz[j];
                pares++;
            }
        }
        vetor = iniciov;
        printf("Pares da linha %d: ", linha);
        if(pares == 0)
            printf("Nao ha pares nesta linha.\n");
        else
            imprimirVetor(vetor, pares);
        linha++;
    }
}

