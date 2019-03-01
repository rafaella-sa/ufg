#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void gerarVetor(int *v, int n){
    int i;
    for(i = 0; i < n; i++)
        //Gera elementos aleatorios entre 1 e 100
        v[i] = 1 + rand()%100;
}

void troca (int *a, int *b){
    //'troca' recebe o primeiro elemento
    int troca = *a;
    //'*a' recebe o valor de '*b'
    *a = *b;
    //'b' recebe o valor de '*a'
    *b = troca;
}

void insertionSort(int *v, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        //'aux' recebe o valor atual
        aux = v[i];
        //procura a posicao adequada no pedaco de vetor ja ordenado
        for(j = i; j > 0 && aux < v[j-1]; j--)
            v[j] = v[j-1];
        //faz a troca de posicoes
        v[j] = aux;
        printf("Ordem parcial: (passo %d)\n", i+1);
        mostrarVetor(v, n);
    }
}

void selectionSort(int *v, int n){
    int i, j, menor;
    for(i = 0; i < n-1; i++){
        for(j = i+1, menor = i; j < n; j++)
            //seleciona o menor elemento
            if(v[j] < v[menor])
                menor = j;
        //se a posicao for diferente, troca os elementos
        if(i != menor)
            troca(&v[menor], &v[i]);
        printf("Ordem parcial (passo %d): \n", i+1);
        mostrarVetor(v, n);
    }
}

void bubbleSort(int *v, int n){
    int i, j;
    int flag = 1; //bandeira que evita passagens desnecessarias
    for(i = 0; (i < n-1) && flag; i++){
        flag = 0; //se nao ha troca, sai do laco porque o
                  //vetor ja esta ordenado
        for(j = n-1; j > i; --j)
            if(v[j] < v[j-1]){
                troca(&v[j], &v[j-1]);
                flag = 1;
            }
        printf("Ordem parcial (passo %d): \n", i+1);
        mostrarVetor(v, n);
    }
}

void mostrarVetor(int *v, int n){
    int i; //mostra todos os elementos do vetor
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n\n");
}

void ordenarVetor(int op){
    int n = 0; //tamanho do vetor
    int *v; //vetor
    //verifica que se ingresse um tamanho valido
    while(n <= 0){
        printf("Ingresse uma dimensao valida para o vetor: ");
        scanf("%d", &n);
    }
    //semente para geracao de numeros aleatorios diferentes
    srand(time(NULL));
    //aloca memoria para os 'n' elementos
    v = (int*) malloc (n * sizeof(int));
    gerarVetor(v, n);
    printf("\nVetor original:\n");
    mostrarVetor(v, n);
    switch (op){
        case 1: {
                insertionSort(v, n);
                break;
        }
        case 2: {
                selectionSort(v, n);
                break;
        }
        case 3: {
                bubbleSort(v, n);
                break;
        }
    }
    printf("Vetor ordenado:\n");
    mostrarVetor(v, n);
    //libera memoria associada ao vetor
    free(v);
}

void opcoes_menu(){
    //opcos disponiveis no menu
    printf("ORDENACAO - ALGORITMOS BASICOS\n\n");
    printf("1. Insercao\n");
    printf("2. Selecao\n");
    printf("3. Bolha\n");
    printf("\n0. SAIR\n\n");
    printf("Selecione uma opcao valida: ");
}

void menu(){
    int op; //variavel que recebe a opcao a ser selecionada
    do{ //inicio do menu
        opcoes_menu();
        scanf("%d", &op);
        switch (op){
            case 0: { //SAIR
                    printf("Encerrando...\n");
                    break;
                    }
            case 1: { //Insercao
                    ordenarVetor(1);
                    break;
            }
            case 2: { //Selecao
                    ordenarVetor(2);
                    break;
            }
            case 3: { //Bolha
                    ordenarVetor(3);
                    break;
            }
            default:{ //se for selecionada uma opcao indisponivel
                    printf("\nOpcao invalida!\n");
                    break;
            }
        }
    }while(op != 0); //executa menu enquanto nao se seleciona 0
}
