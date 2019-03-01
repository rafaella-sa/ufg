//Rafaella Silva Almeida
//Lista 10 - Exercício 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    if((file = fopen("ex2.txt", "w")) == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    char palavra[100];
    int i;
    while(strcmp(gets(palavra), "sair") != 0){
        for(i = 0; i < strlen(palavra); i++){
            switch(palavra[i]){
                case 'A': {
                    palavra[i] = '4';
                    break;
                }
                case 'E': {
                    palavra[i] = '3';
                    break;
                }
                case 'I': {
                    palavra[i] = '1';
                    break;
                }
                case 'O': {
                    palavra[i] = '0';
                    break;
                }
                case 'G': {
                    palavra[i] = '6';
                    break;
                }
                case 'S': {
                    palavra[i] = '5';
                    break;
                }
                case 'T': {
                    palavra[i] = '7';
                    break;
                }
                case 'Z': {
                    palavra[i] = '2';
                    break;
                }
            }
        }
        fputs(palavra, file);
        fputs("\n", file);
    }
    fclose(file);
    if((file = fopen("ex2.txt", "r")) == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    while((fgets(palavra, 100, file)) != NULL){
        printf("%s", palavra);
    }
    fclose(file);
    return 0;
}
