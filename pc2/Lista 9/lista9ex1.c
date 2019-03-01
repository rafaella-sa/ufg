//Rafaella Silva Almeida
//Lista 9 - Exercício 1

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("arquivo.txt", "r");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    short int c;
    int flag = 0;
    while((c = fgetc(file)) != EOF && !flag){
        if(c == 'a')
            if((c = fgetc(file)) == 'c')
                if((c = fgetc(file)) == 'a')
                    if((c = fgetc(file)) == 's')
                        if((c = fgetc(file)) == 'o'){
                            printf("acaso\n");
                            flag = 1;
                        }
    }
    fclose(file);
    return 0;
}
