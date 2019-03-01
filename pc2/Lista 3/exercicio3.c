//Rafaella Silva Almeida
//Exercicio 3

#include <stdio.h>

void fibonacci(int n){
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b);
    for(i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

int main(){
    int n;
    printf("Ingresse o numero: ");
    scanf("%d", &n);
    printf("Sequencia de Fibonacci para os %d primeiros numeros: ", n);
    if(n == 0)
        printf("0");
    else if(n == 1)
        printf("0 1");
    else
        fibonacci(n);
    return 0;
}
