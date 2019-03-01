#include <stdio.h>
void main(){
    int i, j, v, vet[20], soma, menor, seg, ter, ouro, prata, bronze, N, M;
    scanf("%d %d", &N, &M);
    menor = 1000;
    seg = 1000;
    ter = 1000;
    ouro = prata = bronze = 1;
    for(i = 0; i < N; i++){
        soma = 0;
        for(j = 1; j <= M; j++){
            scanf("%d", &v);
            soma = soma + v;
        }
        vet[i] = soma;
    }
    for(i = 0; i < N; i++){
        if(vet[i] < menor){
            ouro = i+1;
            menor = vet[i];
        }
    }
    for(i = 0; i < N; i++){
        if(vet[i] < seg && vet[i] > menor){
            prata = i+1;
            seg = vet[i];
        }
    }
    for(i = 0; i < N; i++){
        if(vet[i] < ter && vet[i] > seg){
            bronze = i+1;
            ter = vet[i];
        }
    }
    printf("%d\n", ouro);
    printf("%d\n", prata);
    printf("%d\n", bronze);
}

