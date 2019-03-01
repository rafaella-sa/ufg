//Rafaella Silva Almeida
//Exercicio 2

#include <stdio.h>

int fatorial(int n){
    int i, f = 1;
    for(i = n; i >=2; i--){
        f = f * i;
        }
    return f;
}

int main(){
    int f, n;
    printf("Ingresse o numero: ");
    scanf("%d", &n);
    f = fatorial(n);
    printf("%d! = %d", n, f);
    return 0;
}
