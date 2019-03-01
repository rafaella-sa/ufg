//Rafaella Silva Almeida
#include <stdio.h>
void main(){
    int i, j, div, N1, N2;
    do{
        printf("Ingresse dois números naturais: \n");
        scanf("%d %d", &N1, &N2);
    }
    while(N1 < 1 || N2 < 1 || N1 > N2);
    for(i = N1; i <= N2; i++){
        div = 0;
        for(j = 1; j <= i; j++){
            if(i % j == 0){
                div++;
            }
        }
        if(div == 2)
            printf("%d\n", i);
        }
    }

