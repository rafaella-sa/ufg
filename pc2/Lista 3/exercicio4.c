//Rafaella Silva Almeida
//Exercicio 4

#include <stdio.h>

int digitoprincipal(int n){
    int i, d = n + 1;
    while(n > 10){
        d = d%10;
        n = n/10;
    }
    return n;
}

int main(){
    int n, dig;
    printf("Ingresse o numero: ");
    scanf("%d", &n);
    dig = digitoprincipal(n);
    printf("Digito principal da entrada %d: %d", n, dig);
    return 0;
}
