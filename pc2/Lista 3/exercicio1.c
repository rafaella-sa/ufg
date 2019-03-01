//Rafaella Silva Almeida
//Exercicio 1

#include <stdio.h>

int potencia(int x, int z){
    int i, p = x;
    for(i = 2; i <= z; i++){
        p = p * x;
        }
    return p;
}

int main(){
    int x, z;
    printf("Ingresse X e Z separados por um espaco: ");
    scanf("%d %d", &x, &z);
    int p = potencia(x, z);
    printf("Resultado: %d", p);
    return 0;
}
