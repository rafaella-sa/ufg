#include <stdio.h>
void desenhaQuadrado(int num, char car){
    int i, j;
    for(i = 1; i <= num; i=i+1){
        for (j = 1; j <= num; j=j+1){
            printf("%c", car);
        }
        printf("\n");
        }

    return ;
    }
void main(){
    int N;
    char C;
    scanf("%c", &C);
    scanf("%d", &N);
    desenhaQuadrado(N, C);
}
