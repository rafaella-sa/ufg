//Rafaella Silva Almeida
#include <stdio.h>
#include <string.h>

int palindromo(char *vet, int dim, int i){
    if(i == dim/2 && vet[dim-1-i]==vet[i])
        return 1;
    else if(vet[dim-1-i]==vet[i])
        return palindromo(vet, dim, i+1);
    else
        return 0;
    }

int main(){
    char palavra[100];
    scanf("%s", &palavra);
    puts(palavra);
    if(palindromo(palavra, strlen(palavra), 0) == 1)
        printf("E palindromo");
    else
        printf("NAO e palindromo");
    return 0;
}
