#include <stdio.h>
#include <string.h>

int main(){
    char palavra1[30], palavra2[30];
    gets(palavra1);
    gets(palavra2);
    if(strcmp(palavra1, palavra2) == 0)
        printf("As strings ingressadas sao iguais.");
    else
        printf("As strings ingressadas sao diferentes.");
    return 0;
}
