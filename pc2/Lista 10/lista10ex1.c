//Rafaella Silva Almeida
//Lista 10 - Exercício 1

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    if((file = fopen("ex1.txt", "w")) == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    char c;
    while((c = getchar()) != '\n'){
        switch(c){
            case 'A': {
                fputc('4', file);
                break;
            }
            case 'E': {
                fputc('3', file);
                break;
            }
            case 'I': {
                fputc('1', file);
                break;
            }
            case 'O': {
                fputc('0', file);
                break;
            }
            case 'G': {
                fputc('6', file);
                break;
            }
            case 'S': {
                fputc('5', file);
                break;
            }
            case 'T': {
                fputc('7', file);
                break;
            }
            case 'Z': {
                fputc('2', file);
                break;
            }
            default: {
                fputc(c, file);
                break;
            }
        }
    }
    fclose(file);
    return 0;
}
