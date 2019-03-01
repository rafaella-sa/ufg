//Rafaella Silva Almeida
//Lista 11 - Exercício 1

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    if((file = fopen("ex1.txt", "w")) == NULL){
        printf("Nao e possivel abrir o arquivo.\n");
        exit(1);
    }
    int i;
    float nota1, nota2, media;
    char nome[30];
    for(i = 1; i <= 10; i++){
        printf("ALUNO %i\nNome:", i);
        scanf(" %s", nome);
        fflush(stdin);
        printf("Nota 1: ");
        scanf(" %f",&nota1);
        printf("Nota 2: ");
        scanf(" %f",&nota2);
        media = (nota1 + nota2)/2;
        printf("%.2f\n", media);
        fprintf(file, "Aluno %s: media %.2f \n",nome,media);
    }
    fclose(file);
    return 0;
}
