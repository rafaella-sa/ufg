//Rafaella Silva Almeida
//Prova 2 - Exercício 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int A = 0, C = 0, T = 0, G = 0;
    FILE *file;
    if((file = fopen("genoma.txt", "r")) ==  NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    char ch;
    while((ch = fgetc(file)) != EOF){
        switch(ch){
            case 'A':{
                A++; break;
            }
            case 'C':{
                C++; break;
            }
            case 'T':{
                T++; break;
            }
            case 'G':{
                G++; break;
            }
        }
    }
    printf("Total de letras no arquivo: %d\n", A+C+T+G);
    printf("Letras 'A': %d\n", A);
    printf("Letras 'C': %d\n", C);
    printf("Letras 'T': %d\n", T);
    printf("Letras 'G': %d\n", G);
    fclose(file);
    return 0;
}
