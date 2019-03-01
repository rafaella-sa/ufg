/* Estruturas de Dados 2
   Aula 1 - Exercicio 1
   Rafaella Silva Almeida */

//Inclusao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definicao das constantes TRUE e FALSE
#define TRUE 1
#define FALSE 0

int main(){
    //Declaracao de variaveis
    int i; //Contador para percorrer os vetores
    int tam; //Tamanho dos vetores escolhido pelo usuario
    int valor; //Variavel que armazena o valor buscado pelo usuario
    int flag = FALSE; //Bandeira para controle do laco

    //Semente para geracao de aleatorios
    srand((unsigned)time(NULL));

    //Leitura da dimensao dos vetores
    printf("Ingresse o tamanho do vetor: ");
    scanf("%d", &tam);

    //Alocacao de memoria e geracao do vetor de inteiros
    int *vet_int = (int*) malloc (tam*sizeof(int));
    printf("Vetor de inteiros:\n\n");
    for(i = 0; i < tam; i++){
        *(vet_int + i) = rand()%tam;
        printf("%d\n", *(vet_int + i));
    }

    //Alocacao de memoria e geracao do vetor de ponto flutuante
    printf("\nVetor double:\n\n");
    double *vet_double = (double*) malloc (tam*sizeof(double));
    for(i = 0; i < tam; i++){
        *(vet_double + i) = rand()%1001;
        *(vet_double + i) = (*(vet_double + i)) / 100;
        printf("%.2f\n", *(vet_double + i));
    }

    // Pede ao usuario que digite um valor inteiro
    printf("\nDigite um valor inteiro: ");
    scanf("%d", &valor);

    //Comeca a busca no vetor de inteiros
    for(i = 0; i < tam && !flag; i++){
        if(*(vet_int + i) == valor){ //Se o valor digitado pelo usuario corresponde
                                 //a algum valor armazenado no vetor de inteiros
            //Imprime o valor que corresponde no vetor de ponto flutuante
            printf("Valor correspondente no vetor double: %.2f\n", *(vet_double + i));
            //Altera o status da bandeira para encerrar o laco
            flag = TRUE;
        }
    }

    if(!flag) //Se nao foi encontrado nenhum elemento correspondente
              //Imprime a mensagem
        printf("Elemento nao tem correspondente no vetor double.\n");

    //Liberacao da memoria alocada
    free(vet_int);
    free(vet_double);
    return 0;
}
