//Rafaella Silva Almeida
//Lista 12 - Exercício 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    if((file = fopen("ex2saida.txt", "r")) == NULL){
        printf("Nao e possivel abrir o arquivo. \n");
        exit(1);
    }
    char str[100];
    printf("Digite a palavra a ser procurada: ");
    scanf("%s", str);
    int ch, i = 0, m = 1, n=1;
    while((ch = fgetc(file)) != EOF){
        if(ch == str[i]){while(fgets(str1, 100, file1) != NULL && fgets(str2, 100, file2) != NULL){
        if(strcmp(str1, str2) != 0){
            printf("As linhas %d dos arquivos sao diferentes. \n", i);
            flag = 0;
        }
        i++;
    }
            i++;
            if(i == strlen(str)){
                printf("Encontrado na linha %d e na coluna %d\n", m, n-strlen(str)+1);
            }
        }
        else
            i = 0;
        n++;
        if(ch == '\n'){
            m++;
            n = 1;
        }
    }
    fclose(file);
    return 0;
}
