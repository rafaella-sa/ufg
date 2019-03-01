//Rafaella Silva Almeida
//Lista 6 - Exercício 4

#include <stdio.h>

void preencherMatriz(int *matriz, int m);
void imprimirMatriz(int *matriz, int m);
void trocarMatrizes(int *pm1, int *pm2, int m);

int main(){
    int i, m;
    do{
        printf("Ingresse a dimensao da matriz: ");
        scanf("%d", &m);
    }while(m <= 0);
    int mat1[m][m], mat2[m][m];
    int *pm1 = mat1[0];
    int *pm2 = mat2[0];
    printf("\nMATRIZ 1\n");
    preencherMatriz(pm1, m);
    printf("\nMATRIZ 2\n");
    preencherMatriz(pm2, m);
    printf("\nAntes da troca: \n");
    printf("\nMATRIZ 1\n");
    imprimirMatriz(pm1, m);
    printf("MATRIZ 2\n");
    imprimirMatriz(pm2, m);
    trocarMatrizes(pm1, pm2, m);
    printf("Depois da troca: \n");
    printf("\nMATRIZ 1\n");
    imprimirMatriz(pm1, m);
    printf("MATRIZ 2\n");
    imprimirMatriz(pm2, m);
    return 0;
}

void preencherMatriz(int *matriz, int m){
    int i, *inicio = matriz;
    printf("\n");
    for(i = 0; i < m*m; i++){
        printf("Digite o elemento %d da matriz: ", i+1);
        scanf("%d", &matriz[i]);
    }
    matriz = inicio;
}

void imprimirMatriz(int *matriz, int m){
    int i, *inicio = matriz;
    printf("\nA matriz e: \n");
    for(i = 0; i < m*m; i++){
        printf("%d ", matriz[i]);
       if((i+1)%m == 0)
            printf("\n");
    }
    matriz = inicio;
    printf("\n");
}


void trocarMatrizes(int *pm1, int *pm2, int m){
    int i, aux, *m1 = pm1, *m2 = pm2;
    for(i = 0; i < m*m; i++){
        aux = *pm1;
        *pm1 = *pm2;
        *pm2 = aux;
        pm1++;
        pm2++;
    }
    pm1 = m1;
    pm2 = m2;
}
