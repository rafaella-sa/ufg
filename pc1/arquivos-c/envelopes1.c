#include <stdio.h>
void main(){
    int x = 1000, i, tipo, N, K, vet[20];
    scanf("%d %d", &N, &K);
    for(i = 0; i < K; i++)
        vet[i] = 0;
    for(i = 1; i <= N; i++){
        scanf("%d", &tipo);
        vet[tipo - 1]++;
    }
    for(i = 0; i < K; i++)
        if(vet[i] < x)
            x = vet[i];
    printf("%d\n", x);
}
