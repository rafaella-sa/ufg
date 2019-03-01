#include <stdio.h>
int main(){
    int i, soma = 0, A[10], corte;
    printf("Ingresse a nota de corte: ");
    scanf("%d", &corte);
    printf("Ingresse as 10 notas: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < 10; i++)
        if(A[i] >= corte)
            soma += A[i];
    printf("Somatorio das notas acima do ponto de corte: %d", soma);
}
