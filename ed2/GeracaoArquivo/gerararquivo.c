#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct aluno{
    int mat;
    int n1, n2, n3;
};
typedef struct aluno Aluno;

Aluno gerarAluno(){
    Aluno al;
    al.mat = 150000 + (1 + rand() % 9999);
    al.n1 = 1 + rand() % 10;
    al.n2 = 1 + rand() % 10;
    al.n3 = 1 + rand() % 10;
    return al;
}

void imprimirAlunos(Aluno alunos[], int n){
    int i;
    printf("\n");
    for(i = 0; i < n; i++){
        printf("ALUNO %d\n\n", i+1);
        printf("Matricula: %d\n", alunos[i].mat);
        printf("Nota 1: %d\n", alunos[i].n1);
        printf("Nota 2: %d\n", alunos[i].n2);
        printf("Nota 3: %d\n\n", alunos[i].n3);
    }
}

void gravarArquivo(){
    //foram selecionados n = 100000 e j de 1 a 35
    //para gerar um arquivo de aproximadamente 50 MB
    //abre arquivo
    FILE *f = fopen("registros.bin", "a+b");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    //variaveis
    int i, j, n = 100000;
    Aluno alunos[n];
    printf("\nGravando elementos...\n\n");
    //gera vetores
    srand((unsigned) time (NULL));
    for(j = 1; j <= 35; j++){
        for(i = 0; i < n; i++)
            alunos[i] = gerarAluno();
        fwrite(alunos, sizeof(alunos[0]), n, f);
    }
    //fecha arquivo
    fclose(f);
}

void lerArquivo(){
    int n = 0, r;
    //abre arquivo
    FILE *f = fopen("registros.bin", "rb");
    if(f == NULL){
        printf("Erro na abertura do arquivo.\n\n");
        return;
    }
    //seleciona quantidade de elementos a serem lidos
    while(n <= 0 || n > 100){
        printf("Ingresse a quantidade de elementos (entre 1 e 100): ");
        scanf("%d", &n);
    }
    //le do arquivo
    Aluno alunos[n];
    r = fread(alunos, sizeof(alunos[0]), n, f);
    if(r == 0){ //se o arquivo esta vazio
        printf("Nao ha elementos no arquivo.\n\n");
        return;
    }
    else //senao imprime dados encontrados
        imprimirAlunos(alunos, n);
    //fecha arquivo
    fclose(f);
}

void opcoesMenu(){
    printf("GERACAO DE ARQUIVO BINARIO\n\n");
    printf("1. Gravar elementos\n");
    printf("2. Ler elementos\n\n");
    printf("0. Sair\n\n");
    printf("Selecione a opcao desejada: ");
}

void menu(){
    int op = 0;
    do{
        opcoesMenu();
        scanf("%d", &op);
        switch(op){
            case 0: {
                    printf("Encerrando...\n");
                    break;
                    }
            case 1: {
                    gravarArquivo();
                    break;
                    }
            case 2: {
                    lerArquivo();
                    break;
                    }
            default:{
                    printf("Opcao invalida!\n\n");
                    break;
                    }
        }
    }while(op != 0);
}
