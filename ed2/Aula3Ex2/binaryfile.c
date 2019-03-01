#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryfile.h"

void imprimir_registro(struct record rec){
    //recebe o registro por parametro e imprime todos os dados associados
    printf("ID: %d\n", rec.id_number);
    printf("NOME: %s\n", rec.name);
    printf("ENDERECO: %s\n", rec.adress);
    printf("TELEFONE: %ld\n", rec.phone);
    printf("IDADE: %d\n", rec.age);
    printf("SALARIO: %.2f\n\n", rec.salary);
}

void gravar_arquivo(){
    FILE *fp; //ponteiro para o arquivo
    int i; //variavel de controle do laco de repeticao
    int n = 0; //quantidade de elementos a serem gravados no arquivo
    int result; //variavel que recebe o numero de elementos gravados
    struct record database[100]; //armazenamento temporario dos dados
    if((fp = fopen("test.bin", "a+b")) == NULL){
        //se nao abriu corretamente o arquivo, encerra a funcao e retorna ao menu
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    while(n <=0 || n > 100){
        //le e verifica uma quantidade de elementos para serem guardados no arquivo
        printf("Quantidade de registros a serem guardados (entre 1 e 100): ");
        scanf("%d", &n);
    }
    for(i = 0; i < n; i++){
        //limpa o buffer
        fflush(stdin);
        //le todos os dados dos 'n' registros
        printf("\nNome: "); gets(database[i].name);
        printf("Endereco: "); gets(database[i].adress);
        printf("Telefone: "); scanf("%ld", &database[i].phone);
        printf("Idade: "); scanf("%d", &database[i].age);
        printf("Salario: "); scanf("%f", &database[i].salary);
        printf("ID: "); scanf("%d", &database[i].id_number);
    }
    //armazena e mostra quantos dados foram gravados
    result = fwrite(database, sizeof(database[0]), n, fp);
    printf("\nNumero de elementos gravados: %d\n\n", result);
    //fecha o arquivo
    fclose(fp);
    return;
}

void buscar_arquivo(){
    FILE *fp; //ponteiro para o arquivo
    int i; //variavel de controle do laco de repeticao
    int id; //chave fornecida pelo usuario para busca de informacao
    int flag; //bandeira para controle do laco de repeticao
    int n; //quantidade de elementos lidos do arquivo
    struct record database[5]; //armazenamento temporario dos dados
    if((fp = fopen("test.bin", "rb")) == NULL){
        //se nao abriu corretamente o arquivo, encerra a funcao e retorna ao menu
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    do{
        //le dados de 5 em 5
        n = fread(&database[0], sizeof(database[0]), 5, fp);
        printf("\nNumero de elementos lidos: %d\n\n", n);
        if(n != 0){ //se foram recuperados elementos
            //le a id a ser buscada
            printf("Insira a ID a ser buscada: "); scanf("%d", &id);
            flag = 0;
            //enquanto nao foi encontrado e ainda ha elementos a serem verificados
            for(i = 0; i < n && !flag; i++){
                //se foi encontrado, imprime os dados e altera status da bandeira
                if(database[i].id_number == id){
                    printf("\nRegistro encontrado!\n\n");
                    imprimir_registro(database[i]);
                    flag = 1;
                }
            }
            if(!flag) //se nao foi encontrado o elemento nesta porcao selecionada
                printf("Registro nao encontrado nesta parte do arquivo.\n");
        } //enquanto nao chegou ao fim do arquivo e nao foi encontrado
    }while(!feof(fp) && !flag);
    if(feof(fp) && !flag) //caso chegue ao final do arquivo e nao foi encontrado
        printf("O registro de ID %d nao existe no arquivo.\n\n", id);
    //fecha o arquivo
    fclose(fp);
}

void opcoes_menu(){
    //imprime as opcoes disponiveis no menu
    printf("ARQUIVO BINARIO - MANIPULACAO\n\n");
    printf("1. Gravar Dados\n");
    printf("2. Buscar Dados\n");
    printf("\n0. SAIR\n\n");
    printf("Selecione uma opcao valida: ");
}

void menu(){
    int op; //variavel que recebe a opcao do menu
    do{ //inicio do menu
        opcoes_menu();
        scanf("%d", &op);
        switch (op){
            case 0: { //SAIR
                    printf("Encerrando...\n");
                    break;
            }
            case 1: { //gravar dados
                    gravar_arquivo();
                    break;
            }
            case 2: { //Buscar dados
                    buscar_arquivo();
                    break;
            }
            default:{ //se for selecionada uma opcao indisponivel
                    printf("\nOpcao invalida!\n\n");
                    break;
            }
        } //executa enquanto for diferente de zero
    }while(op != 0);
}
