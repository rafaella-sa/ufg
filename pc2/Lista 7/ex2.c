//Rafaella Silva Almeida
//Lista 7 - Exercício 2

#include <stdio.h>
#include <stdlib.h>

typedef struct viagem{
    float distancia;
    float litros;
    float preco;
    float kmporlitro;
}viagem;

int main(){
    int i;
    float precototal=0.0;
    viagem* viagens;
    viagens = (viagem*) malloc (sizeof(viagem)*3);
    if(viagens == NULL)
        exit(1);
    for(i = 0; i < 3; i++){
        printf("VIAGEM %d:\n", i+1);
        printf("Digite a distancia: ");
        scanf(" %f", &viagens[i].distancia);
        printf("Digite o preco do litro: ");
        scanf(" %f", &viagens[i].preco);
        printf("Digite quantos quilometros o veiculo anda com 1 litro de combustivel: ");
        scanf(" %f", &viagens[i].kmporlitro);
        viagens[i].litros = viagens[i].distancia/viagens[i].kmporlitro;
        precototal = viagens[i].litros * viagens[i].preco;
        printf("Na viagem %d serao necessarios %0.0f litros e o preco total sera R$%0.2f.\n",
               i+1, viagens[i].litros, precototal);
    }
    free(viagens);
    return 0;
}
