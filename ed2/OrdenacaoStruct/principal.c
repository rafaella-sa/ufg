#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenastruct.h"

aluno* geraVetorAlunos(int *quant){
    int i, n = 0;
    aluno* alunos;
    while(n <= 0){
        //le e verifica uma quantidade de elementos para serem guardados no vetor
        printf("Quantidade de registros a serem guardados (valor maior que 0): ");
        scanf("%d", &n);
    }
    //salva a quantidade de elementos e aloca memoria
    *quant = n;
    alunos = (aluno*) malloc (n * sizeof(aluno));
    if(alunos == NULL){
        printf("Erro na alocacao de memoria.\n");
        return NULL;
    }
    //le os dados
    for(i = 0; i < n; i++){
        //limpa o buffer
        fflush(stdin);
        //le todos os dados dos 'n' registros
        printf("\nNome: "); gets(alunos[i].nome);
        printf("Curso: "); gets(alunos[i].curso);
        printf("Matricula: "); scanf("%d", &alunos[i].matricula);
        printf("Ano de ingresso: "); scanf("%d", &alunos[i].anoIngresso);
    }
    return alunos;
}

void imprimirAlunos(aluno* alunos, int n){
    int i;
    //recebe os registros por parametro e imprime todos os dados associados
    for(i = 0; i < n; i++){
        printf("NOME: %s\n", alunos[i].nome);
        printf("CURSO: %s\n", alunos[i].curso);
        printf("ANO DE INGRESSO: %d\n", alunos[i].anoIngresso);
        printf("MATRICULA: %d\n\n", alunos[i].matricula);
    }
}

void opcoesMenu(){
    //imprime os criterios de ordenacao disponiveis
    printf("Criterios de ordenacao:\n\n");
    printf("1. Ano de ingresso\n");
    printf("2. Curso\n");
    printf("3. Matricula\n");
    printf("4. Nome\n\n");
    printf("0. Sair\n\n");
    printf("Selecione uma opcao valida: ");
}

void menu(){
    int opcao, quant;
    printf("Ordenacao de alunos pelo metodo Shell Sort\n\n");
    //armazena os alunos a serem ordenados
    aluno* alunos = geraVetorAlunos(&quant);
    if(alunos == NULL)
        exit (1);
    else
        printf("\nAlunos armazenados com sucesso!\n\n");
    do{
        opcoesMenu();
        scanf("%d", &opcao);
        switch(opcao){
            case 0: {
                    printf("Encerrando...\n\n");
                    break;
                    }
            case 1:
            case 2: //ordena os elementos de acordo
            case 3: //com o criterio selecionado
            case 4: {
                    printf("\nVetor original: \n\n");
                    imprimirAlunos(alunos, quant);
                    shellSort(alunos, quant, opcao);
                    printf("Vetor ordenado: \n\n");
                    imprimirAlunos(alunos, quant);
                    break;
                    }
            default:{
                    printf("Opcao invalida!\n\n");
                    break;
            }
        }
    }while(opcao != 0);
    //libera memoria associada a 'alunos'
    free(alunos);
}
