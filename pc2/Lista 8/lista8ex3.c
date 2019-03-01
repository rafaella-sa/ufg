//Rafaella Silva Almeida
//Lista 8 - Exercício 3

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

char* intastring (int i, char *texto){
    char const digit[] = "0123456789";
    char* p = texto;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{
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

int buscarcpf(char *texto, char *frase){
    int i;
    if(strcmp(cpfvalido(frase), "SIM") != 0){
        return -1;
    }
    else{
        for(i = 0; i < strlen(texto); i++){
            if(strcmp(frase, substring(texto, i, i + strlen(frase)-1)) == 0)
                return i+1;
        }
        return -1;
    }
}

//o codigo do buscarnome e do buscardata dao erro, apesar de serem identicos
//ao codigo do buscarcpf que funciona

int buscarnome(char *texto, char *frase){
    int i;
    if(strcmp(apenasletras(frase), "SIM") != 0){
        return -1;
    }
    else{
        for(i = 0; i < strlen(texto); i++){
            if(strcmp(frase, substring(texto, i, i + strlen(frase)-1)) == 0)
                return i+1;
        }
        return -1;
    }
}

int buscardata(char *texto, char *frase){
    int i;
    if(strcmp(datavalida(frase), "SIM") != 0){
        return -1;
    }
    else{
        for(i = 0; i < strlen(texto); i++){
            if(strcmp(frase, substring(texto, i, i + strlen(frase)-1)) == 0)
                return i+1;
        }
        return -1;
    }
}

void verificadora(int op, char *texto, char *frase){
    int (*p)();
    switch(op){
            case 1:{ //cpf
                p = buscarcpf;
                if(p == NULL)
                    exit(1);
                printf("%d\n", p(texto, frase));
                free(p);
                break;
            }
            case 2:{ //nome
                p = buscarnome;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(texto, frase));
                free(p);
                break;
            }
             case 3:{ //data
                p = buscardata;
                if(p == NULL)
                    exit(1);
                printf("%s\n", p(texto, frase));
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
    char texto[100], *ptexto, frase[25], *pfrase;
    printf("Digite seu texto abaixo:\n");
    gets(texto);
    ptexto = texto;
    printf("Digite o conteudo a ser buscado abaixo:\n");
    gets(frase);
    pfrase = frase;
    do{
        printf("Opcoes:\n1. Verificar e buscar CPF\n2. Verificar e buscar nome\n3. Verificar e buscar data\n0. Sair\n");
        scanf("%d", &op);
        verificadora(op, ptexto, pfrase);
    }while(op!=0);
    printf("Programa finalizado!\n");
    return 0;
}
