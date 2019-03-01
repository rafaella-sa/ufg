#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contagem.h"

void Encode(char *src, char *dst){
    int index = 0;
    char runTotal = 0, currentChar = 0;
    char *rt = (char*) malloc (2 * sizeof(char));
    char *cc = (char*) malloc (2 * sizeof(char));
    while(index < (int)strlen(src)) {
        runTotal = 0;
        currentChar = src[index];
        while(currentChar == src[index] && runTotal < 255) {
            runTotal++;
            index++;
        }
        if(runTotal > 3) {
            strcat(dst, "~");
            sprintf(rt, "%d", runTotal);
            strcat(dst, rt);
            sprintf(cc, "%c", currentChar);
            strcat(dst, cc);
        }
        else{
            int i;
            sprintf(cc, "%c", currentChar);
            for(i = 0; i < runTotal; i++)
                strcat(dst, cc);
        }
    }
    free(cc);
    free(rt);
}

void Decode(char *src, char *dst){
    char *cc = (char*) malloc (2 * sizeof(char));
    int index = 0, runTotal = 0;
    char currentChar = 0;
    while(index < strlen(src)) {
        if(src[index++] == '~') {
            while(src[index] == '~'){
                sprintf(cc, "%c", src[index-1]);
                strcat(dst, cc);
                index++;
            }
            runTotal = (int)src[index++] - 48;
            currentChar = src[index++];
            int i;
            sprintf(cc, "%c", currentChar);
            for(i = 0; i < runTotal; i++)
                strcat(dst, cc);
        }
        else{
            sprintf(cc, "%c", src[index-1]);
            strcat(dst, cc);
        }
    }
    free(cc);
}

void menu(){
    char op1 = 's', op2;
    char str1[100], str2[100];
    do{
        system("CLS");
        printf("COMPRESSAO POR CONTAGEM DE CARACTERES REPETIDOS\n\n");
        printf("Ingresse o texto: ");
        scanf("%[^\n]", str1);
        fflush(stdin);
        printf("\nO que deseja: (C)ompressao ou (D)escompressao?\n");
        scanf(" %c", &op2);
        fflush(stdin);
        if(op2 == 'c' || op2 == 'C'){
            Encode(str1, str2);
            printf("\nResultado: %s\n", str2);
        }
        else if(op2 == 'd' || op2 == 'D'){
            Decode(str1, str2);
            printf("\nResultado: %s\n", str2);
        }
        else
            printf("Opcao invalida!\n");
        printf("\nDeseja continuar? (S)im / (N)ao\n");
        scanf(" %c", &op1);
        fflush(stdin);
    }while(op1 == 's' || op2 == 'S');
    printf("Encerrando...\n");
}
