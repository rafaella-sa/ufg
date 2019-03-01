//Rafaella Silva Almeida
//Lista 9 - Exercício 2

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    if((file = fopen("codigo.c", "r")) == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    char str[100];
    int i = 1;
    while(fgets(str, 100, file) != NULL){
        printf("%d.  %s", i++, str);
    }
    fclose(file);
    return 0;
}
