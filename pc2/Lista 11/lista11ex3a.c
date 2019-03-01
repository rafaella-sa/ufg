//Rafaella Silva Almeida
//Lista 11 - Exercício 3.a

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file1, *file2;
    if((file1 = fopen("ex3ain.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo de entrada.\n");
        exit(1);
    }
    if((file2 = fopen("ex3aout.txt", "w")) == NULL){
        printf("Nao e possivel abrir o arquivo de saida.\n");
        exit(2);
    }
    int c;
    while((c = fgetc(file1)) != EOF){
        c = c + 9;
        fputc(c, file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
