//Rafaella Silva Almeida
#include <stdio.h>
int maiorelem(int vet[10]){
    int i, maior=vet[0], pos=0;
    for(i=1; i<10; i++)
        if(vet[i]>maior){
            maior = vet[i];
            pos = i;
        }
    return pos;
}
int main(){
    int i, maior, vetor[10];
    for(i=0; i<10; i++)
        scanf("%d", &vetor[i]);
    maior = maiorelem(vetor);
    printf("MAIOR: %d\nPOSICAO: %d\n", vetor[maior], maior+1);
}
