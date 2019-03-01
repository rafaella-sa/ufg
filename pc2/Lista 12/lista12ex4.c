//Rafaella Silva Almeida
//Lista 12 - Exercício 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file1, *file2;
    if((file1 = fopen("ex4e1.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    if((file2 = fopen("ex4e2.txt", "r")) == NULL){
            printf("Nao e possivel abrir o arquivo. \n");
            exit(1);
        }
    char str1[50], str2[50];
    int i = 0;
    printf("Palavras em comum:\n");
    while(fscanf(file1, "%s", str1) != EOF){
        while(fscanf(file2, "%s", str2) != EOF){
            if(strcmp(str1, str2) == 0){
                printf("%s\n", str1);
                i++;
            }
        }
        fseek(file2, 0, SEEK_SET);
    }
    if(i == 0)
        printf("Nao ha palavras em comum.\n");
    fclose(file1);
    fclose(file2);
    return 0;
}
