//Rafaella Silva Almeida
//Atividade - Aula nao presencial

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if(argc == 4){
        int num1 = atoi(argv[2]);
        int num2 = atoi(argv[3]);
        if(strcmp(argv[1], "soma") == 0){
            printf("%d + %d = %d\n", num1, num2, num1+num2);
        }else if(strcmp(argv[1], "sub")== 0){
            printf("%d - %d = %d\n", num1, num2, num1-num2);
        }else if(strcmp(argv[1], "mult") == 0){
            printf("%d * %d = %d\n", num1, num2, num1*num2);
        }else if(strcmp(argv[1], "div") == 0){
            if(num2!=0)
                printf("%d / %d = %d\n", num1, num2, num1/num2);
            else
                printf("ERRO! Nao se pode dividir por zero.\n");
        }else{
            printf("Operacao desconhecida\n");
        }
    }
    else
        printf("ERRO! Quantidade de argumentos diferente do esperado.\n");
    return 0;
}
