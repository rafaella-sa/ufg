//Rafaella Silva Almeida
#include <stdio.h>
void main(){
    int i, N, L, C, quebrados;
    do{
        printf("Ingresse a quantidade de bandejas: \n");
        scanf("%d", &N);
    }
    while(N < 1 && N > 100);
    quebrados = 0;
    for(i = 1; i <= N; i++){
        printf("Ingresse quantidade de latas e copos: \n");
        do{
            scanf("%d %d", &L, &C);
        }
        while(L < 0 && C > 100);
        if(L > C)
            quebrados = quebrados + C;
    }
    printf("Copos quebrados: %d.\n", quebrados);

}
