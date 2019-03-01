//Rafaella Silva Almeida
//Lista 6 - Exercício 2

#include <stdio.h>

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

void gerarVetoresdaMatriz(int *matriz, int m, int n){
    int i, j, *inicio = matriz, *vetor, linha = 1;
    for(i = 0; i < m*n; i+=n, linha++){
        vetor = &matriz[i];
        printf("Vetor da linha %d:\n", linha);
        for(j = 0; j < n; j++){
            printf("%d ", vetor[j]);
        }
        printf("\n\n");
    }
    matriz = inicio;
}

int main(){
    int i, m, n;
    do{
        printf("Ingresse as dimensoes da matriz: ");
        scanf("%d %d", &m, &n);
    }while(m <= 0 || n <= 0);
    int mat[m][n];
    int *matriz = mat[0];
    preencherMatriz(matriz, m, n);
    imprimirMatriz(matriz, m, n);
    gerarVetoresdaMatriz(matriz, m, n);
    return 0;
}
