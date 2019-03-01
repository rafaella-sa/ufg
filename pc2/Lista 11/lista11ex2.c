//Rafaella Silva Almeida
//Lista 11 - Exercício 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    char arquivo[25];
    printf("Digite o nome do arquivo a ser aberto: ");
    scanf(" %s", arquivo);
    strcat(arquivo, ".txt");
    if((file = fopen(arquivo, "r")) == NULL){
        printf("Nao e possivel abrir o arquivo.\n");
        exit(1);
    }
    char c;
    int cont = 0;
    while((c = fgetc(file)) != EOF){
        if(c == '\n' || c == ' ')
            cont++;
    }
    if(c == EOF) //para contar a ultima palavra do arquivo
        cont++;
    printf("Quantidade de palavras no arquivo: %d\n", cont);
    fclose(file);
    return 0;
}
