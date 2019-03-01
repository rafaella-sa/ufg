//Rafaella Silva Almeida
#include <stdio.h>

void troca (float *a, float *b){
    float *aux;
    *aux = *a;
    *a = *b;
    *b = *aux;
}

int main(){
    float a, b;
    printf("Digite os numeros A e B: ");
    scanf("%f %f", &a, &b);
    printf("Numeros digitados antes da troca: A = %0.2f; B = %0.2f\n", a, b);
    troca(&a, &b);
    printf("Numeros digitados depois da troca: A = %0.2f; B = %0.2f\n", a, b);
    return 0;
}
