//Rafaella Silva Almeida
//Lista 12 - Exercício 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file1, *file2;
    if((file1 = fopen("ex1a.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    if((file2 = fopen("ex1b.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    char str1[101], str2[101];
    int i = 1, flag = 1, cont1=0, cont2=0;
    while(fgets(str1, 100, file1) != NULL)
        cont1++;
    while(fgets(str2, 100, file1) != NULL)
        cont2++;
    fseek(file1, 0, SEEK_SET);
    fseek(file2, 0, SEEK_SET);
    if(cont1 != cont2){
        while(fgets(str1, 100, file1) != NULL | fgets(str2, 100, file2) != NULL){
            if(strcmp(str1, str2) != 0){
                printf("As linhas %d dos arquivos sao diferentes. \n", i);
            }
            i++;
        }
    }
    else{
        while(fgets(str1, 100, file1) != NULL && fgets(str2, 100, file2) != NULL){
            if(strcmp(str1, str2) != 0){
                printf("As linhas %d dos arquivos sao diferentes. \n", i);
                flag = 0;
            }
            i++;
        }
        if(flag == 1)
            printf("Os arquivos sao iguais.\n");
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
