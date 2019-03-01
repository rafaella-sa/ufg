//Rafaella Silva Almeida
//Exercicios 3 e 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zerarVetor(int *vet, int dim){
    int j;
    for(j = 0; j < dim; j++){
        *(vet+j) = 0;
    }
}

void mostrarVetor(int *vet, int dim){
    int j;
    for(j = 0; j < dim; j++){
        printf("%d ", *(vet+j));
    }
}

int maiorcoluna(int *vet, int dim){
    int j, maior = -1, pos = -1;
    for(j = 0; j < dim; j++){
        if(*(vet+j) > maior){
            maior = *(vet+j);
            pos = j+1;
        }
    }
    return pos;
}

int main(){
    int i, j, m, n, maior;
    srand(time(NULL));
    do{
        printf("Ingresse uma dimensao valida para as filas (maior que 0): ");
        scanf("%d", &m);
    }while(m < 0);
    do{
        printf("Ingresse uma dimensao valida para as colunas (maior que 0): ");
        scanf("%d", &n);
    }while(n < 0);
    int mat[m][n];
    int vet[n];
    //exercicio 3
    zerarVetor(vet, n);
    printf("Matriz gerada: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            mat[i][j] = rand()%10;
            vet[j] += mat[i][j];
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Soma das colunas: ");
    mostrarVetor(vet, n);
    //exercicio 4
    maior = maiorcoluna(vet, n);
    printf("\nMaior coluna: %d", maior);
    return 0;
}
