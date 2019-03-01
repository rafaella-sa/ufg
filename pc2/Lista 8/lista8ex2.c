//Rafaella Silva Almeida
//Lista 8 - Exercício 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intastring (int i, char *texto){
    char const digit[] = "0123456789";
    char* p = texto;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return texto;
}

char *cpfvalido(char *sequencia){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(sequencia) != 11)
        return "NAO";
    else if((strcmp(sequencia,"00000000000") == 0) || (strcmp(sequencia,"11111111111") == 0) || (strcmp(sequencia,"22222222222") == 0) ||
            (strcmp(sequencia,"33333333333") == 0) || (strcmp(sequencia,"44444444444") == 0) || (strcmp(sequencia,"55555555555") == 0) ||
            (strcmp(sequencia,"66666666666") == 0) || (strcmp(sequencia,"77777777777") == 0) || (strcmp(sequencia,"88888888888") == 0) ||
            (strcmp(sequencia,"99999999999") == 0))
            return "NAO";
    else{
        for(i = 0, j = 10; i < strlen(sequencia)-2; i++, j--)
            digito1 += (sequencia[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((sequencia[9]-48) != digito1)
            return "NAO";
        else{
            for(i = 0, j = 11; i < strlen(sequencia)-1; i++, j--)
                    digito2 += (sequencia[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if((sequencia[10]-48) != digito2)
                return "NAO";
        }
    }
    return "SIM";
}
char* substring(char *sequencia, int inicio, int fim) {
    int i, j;
    char *sub;
    sub = (char *) malloc(sizeof(char) * (fim - inicio + 1));
    for(i = inicio, j = 0; i <= fim; i++, j++) {
        sub[j] = sequencia[i];
    }
    sub[j] = '\0';
    return sub;
}

char *datavalida(char *sequencia){
    int dia, mes, ano;
    if(strlen(sequencia) != 8)
        return "NAO";
    else{
        ano = atoi(substring(sequencia, 0, 3));
        mes = atoi(substring(sequencia, 4, 5));
        dia = atoi(substring(sequencia, 6, 7));
        if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)){
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)){
                return "SIM";
            }
            if (dia <= 28 && mes == 2){
                return "SIM";
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
                return "SIM";
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)){
                return "SIM";
            }
            else{
                return "NAO";
            }
        }
        else{
                return "NAO";
           }
    }
}

char *idadedapessoa(char *sequencia){
    int ano;
    char *idade = (char *) malloc(sizeof (char) * 3);;
    if(strcmp("SIM", datavalida((sequencia))) == 0){
        ano = atoi(substring(sequencia, 0, 3));
        return intastring(2014-ano, idade);
    }
    else{
        return "DATA INVALIDA";
    }
}

void verificadora(int op, char *sequencia){
    char *(*p)();
    switch(op){
            case 1:{ //cpf valido
                p = cpfvalido;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(sequencia));
                //free(p);
                break;
            }
            case 2:{ //data valida
                p = datavalida;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(sequencia));
                free(p);
                break;
            }
            case 3:{ //idade da pessoa
                p = idadedapessoa;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(sequencia));
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
    char sequencia[50], *psequencia;
    gets(sequencia);
    psequencia = sequencia;
    do{
        printf("Opcoes:\n1. CPF valido?\n2. Data valida?\n3. Idade da pessoa?\n0. Sair\n");
        scanf("%d", &op);
        verificadora(op, psequencia);
    }while(op!=0);
    printf("Programa finalizado!\n");
    return 0;
}
