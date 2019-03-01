//Rafaella Silva Almeida
//Lista 8 - Exercício 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char *apenasletras(char *palavra){
    int i, flag = TRUE, asc;
    for(i = 0; i < strlen(palavra) && flag == TRUE; i++){
        asc = palavra[i];
        if(asc == -25 || asc == -57 || asc >= 65 && asc <= 90 || asc >= 97 && asc <= 122 || asc == 32){
            flag = TRUE;
        }
        else{
            flag = FALSE;
        }
    }
    if(flag == TRUE)
        return "SIM";
    else
        return "NAO";
}

char *apenasnumeros(char *palavra){
    int i, flag = TRUE, asc;
    for(i = 0; i < strlen(palavra) && flag == TRUE; i++){
        asc = palavra[i];
        if(asc >= 48 && asc <= 57){
            flag = TRUE;
        }
        else{
            flag = FALSE;
        }
    }
    if(flag == TRUE)
        return "SIM";
    else
        return "NAO";
}

char *letrasnafrase(char *palavra){
    int i, asc, quant=0;
    char *letras = (char *) malloc(sizeof (char) * strlen(palavra));
    for(i = 0; i < strlen(palavra); i++){
        asc = palavra[i];
        if(asc == -25 || asc == -57 || asc >= 65 && asc <= 90 || asc >= 97 && asc <= 122 || asc == 32){
            letras[quant] = palavra[i];
            quant++;
        }
    }
    if(quant == 0)
        return "Nao ha letras na frase.";
    else{
        letras[quant] = '\0';
        return letras;
    }
}

void verificadora(int op, char *palavra){
    char *(*p)();
    switch(op){
            case 1:{ //apenas letras
                p = apenasletras;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(palavra));
                free(p);
                break;
            }
            case 2:{ //apenas numeros
                p = apenasnumeros;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(palavra));
                free(p);
                break;
            }
             case 3:{ //apenas numeros
                p = letrasnafrase;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(palavra));
                free(p);
                break;
            }
            case 0: {
                printf("Saindo do programa...\n");
                break;
            }
            default: {
                printf("Opcao invalida!");
                break;
            }
    }
}

int main(){
    int op;
    char frase[50], *pfrase;
    gets(frase);
    pfrase = frase;
    do{
        printf("Opcoes:\n1. Apenas letras?\n2. Apenas numeros?\n3. Letras na frase?\n0. Sair\n");
        scanf("%d", &op);
        verificadora(op, pfrase);
    }while(op!=0);
    printf("Programa finalizado!\n");
    return 0;
}
