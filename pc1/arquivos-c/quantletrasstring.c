#include <stdio.h>
#include <string.h>

int main(){
    char palavra[30];
    gets(palavra);
    printf("A string %s possui %d caracteres.\n", palavra, strlen(palavra));
    return 0;
}
