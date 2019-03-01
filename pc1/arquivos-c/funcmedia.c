//Rafaella Silva Almeida
#include <stdio.h>
int media(int vet[10]){
    int i, soma=0;
    for(i=0; i<10; i++)
        soma += vet[i];
    return soma/10;
}
int main(){
    int i, maior, vetor[10];
    for(i=0; i<10; i++)
        scanf("%d", &vetor[i]);
    printf("MEDIA: %d\n", media(vetor));
}
