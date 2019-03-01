#include <stdio.h>
#include <string.h>

int main(){
    char senha[30];
    do{
        gets(senha);
        if(strcmp(senha, "pc01") != 0)
            printf("senha invalida\n");
        else
            printf("senha correta\n");
    }
    while(strcmp(senha, "pc01") != 0);
    return 0;
}
