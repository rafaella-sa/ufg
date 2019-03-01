#include <stdio.h>
void main(){
    int i, j, v, soma, menor, ganhador, N, M;
    scanf("%d %d", &N, &M);
    menor = 1000;
    for (i = 1; i <= N; i++){
        soma = 0;
        for(j = 1; j <= M; j++){
            scanf("%d", &v);
            soma = soma + v;
        }
        if(soma < menor){
            ganhador = i;
            menor = soma;
        }
    }
    printf("%d\n", ganhador);
}

