//Rafaella Silva Almeida
//Lista 9 - Exercício 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *file;
    file = fopen("imc.txt", "r");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    int i, peso, quant;
    float altura;
    fscanf(file, "%d", &quant);
    for(i = 1; i <= quant; i++){
        fscanf(file, "%d %f", &peso, &altura);
        printf("IMC da pessoa %d: %.1f\n", i, peso/(pow(altura, 2)));
    }
    fclose(file);
    return 0;
}
