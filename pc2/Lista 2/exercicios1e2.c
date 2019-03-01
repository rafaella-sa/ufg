//Rafaella Silva Almeida
//Exercicios 1 e 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef struct{
    int numero;
    int quantidade;
} elemento;

void preencherVetor(int *vet, int dim);
void mostrarVetor(int *vet, int dim);
void inicializarRepetidos(elemento *repetidos, int dim);
int foiContado(int num, elemento *repetidos, int dim);
void mostrarRepetidos(elemento *repetidos, int dim);
void maisrepeticoes(elemento *repetidos, int dim);
void menosrepeticoes(elemento *repetidos, int dim);

int main(){
    srand(time(NULL));
    int fil, col, f, c, i, j, r, cont;
    do{
        printf("Ingresse uma dimensao valida para as filas da matriz (maior que 0): ");
        scanf("%d", &fil);
    }while(fil < 0);
    do{
        printf("Ingresse uma dimensao valida para as colunas da matriz (maior que 0): ");
        scanf("%d", &col);
    }while(col < 0);
    int mat[fil][col];
    int dim = fil * col;
    elemento repetidos[dim];
    printf("Matriz gerada: \n");
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            mat[i][j] = rand()%10;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    inicializarRepetidos(repetidos, dim);
    r = 0;
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            cont = 0;
            for(f = 0; f < fil; f++){
                for(c = 0; c < col; c++){
                    if(mat[f][c] == mat[i][j]){
                        if(foiContado(mat[i][j], repetidos, dim) == FALSE)
                            cont++;
                    }
                }
            }
            if(cont > 1){
                repetidos[r].numero = mat[i][j];
                repetidos[r].quantidade = cont;
                r++;
            }
        }
    }
    if(r > 0){
        printf("\nElementos repetidos: \n");
        mostrarRepetidos(repetidos, r);
        maisrepeticoes(repetidos, r);
        menosrepeticoes(repetidos, r);
    }
    else
        printf("Nao ha elementos repetidos no vetor. ");
    system("PAUSE");
    return 0;
}

//preenche o vetor com inteiros aleatorios entre 0 e 10
void preencherVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        vet[i] = rand()%10;
    }

//imprime o conteudo do vetor
void mostrarVetor(int *vet, int dim){
    int i;
    for(i = 0; i < dim; i++)
        printf("%d ", vet[i]);
    printf("\n");
    }

//preenche o vetor com valores basicos
void inicializarRepetidos(elemento *repetidos, int dim){
    int i;
    for(i = 0; i < dim; i++){
        repetidos[i].numero = -1;
        repetidos[i].quantidade = 0;
    }
}

//verifica se o elemento ja foi contado anteriormente
int foiContado(int num, elemento *repetidos, int dim){
    int i;
    for(i = 0; i < dim; i++)
        if(num == repetidos[i].numero)
            return TRUE;
    return FALSE;
}

//mostra os elementos repetidos
void mostrarRepetidos(elemento *repetidos, int dim){
    int i;
    for(i = 0; i < dim; i++){
        printf("Elemento: %d\n", repetidos[i].numero);
        printf("Repeticoes: %d\n", repetidos[i].quantidade);
        printf("\n");
    }
}

//verifica qual numero se repete mais
void maisrepeticoes(elemento *repetidos, int dim){
    int i, posmais = -1, mais = -1;
    for(i = 0; i < dim; i++){
        if(repetidos[i].quantidade > mais){
            mais = repetidos[i].quantidade;
            posmais = i;
        }
    }
    printf("Numero MAIS repetido: %d\n", repetidos[posmais].numero);
}

//verifica qual numero se repete menos
void menosrepeticoes(elemento *repetidos, int dim){
    int i, posmenos = -1, menos = 11;
    for(i = 0; i < dim; i++){
        if(repetidos[i].quantidade < menos){
            menos = repetidos[i].quantidade;
            posmenos = i;
        }
    }
    printf("Numero MENOS repetido: %d\n", repetidos[posmenos].numero);
}
