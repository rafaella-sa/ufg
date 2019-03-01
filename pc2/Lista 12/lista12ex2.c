//Rafaella Silva Almeida
//Lista 12 - Exercício 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file1, *file2, *file3;
    if((file1 = fopen("ex2entrada1.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    if((file2 = fopen("ex2entrada2.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    if((file3 = fopen("ex2saida.txt", "w")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    char str[1001];
    while(fgets(str, 1000, file1) != NULL){
        fputs(str, file3);
    }
    fputs("\n", file3);
    while(fgets(str, 1000, file2) != NULL){
        fputs(str, file3);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    if((file3 = fopen("ex2saida.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    printf("Conteudo do arquivo de saida: \n");
    while(fgets(str, 1000, file3) != NULL){
        printf("%s", str);
    }
    fclose(file3);
    return 0;
}
