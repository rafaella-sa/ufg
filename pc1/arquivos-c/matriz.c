#include <stdio.h>
int main(){
    int T=5;
    int A[T][T], i, j, aux;
    for(i = 0; i < T; i++)
        for(j = 0; j < T; j++)
            scanf("%d", &A[i][j]);
    printf("\n");	
    //troca a linha
    for(j = 0; j < T; j++){
        aux = A[1][j];
        A[1][j] = A[4][j];
        A[4][j] = aux;
    }
    //imprimir matriz
    for(i = 0; i < T; i++){
        for(j = 0; j < T; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
    //troca a coluna
    for(i = 0; i < T; i++){
        aux = A[i][0];
        A[i][0] = A[i][3];
        A[i][3] = aux;
    }
    //imprimir matriz
    for(i = 0; i < T; i++){
        for(j = 0; j < T; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
    //trocar diagonais
    for(i = 0; i < T; i++){
            aux = A[i][i];
            A[i][i] = A[i][T-i-1];
            A[i][T-i-1] = aux;
        }
    //imprimir matriz
    for(i = 0; i < T; i++){
        for(j = 0; j < T; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
return 0;
}
