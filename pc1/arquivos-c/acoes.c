#include <stdio.h>
void main(){
    int i, j, lim = 4, N, vet[20], lucro = -1000, soma;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }
    for(j = 0; j <= N - 4; j++){
        soma = 0;
        i = j;
        while(i < lim){
            soma = soma + vet[i];
            i++;
        }
        if(soma > lucro)
            lucro = soma;
        lim++;
    }
    printf("%d\n", lucro);
}
