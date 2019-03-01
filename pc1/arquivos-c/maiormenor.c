#include <stdio.h>
void main(){
  int num, maior, menor;
  char opcao;
  printf("Digite um numero: ");
  scanf("%d", &num);
  maior = -1;
  menor = 1000;
  printf("%d%dContinua? (S/N) ",maior, menor);
  scanf(" %c", &opcao);
  while(opcao == 'S' || opcao == 's'){
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num > maior)
      maior = num;
    else if(num < menor)
      menor = num;
    printf("%d%dContinua? (S/N) ", maior, menor);
    scanf(" %c", &opcao);
    }
  printf("Maior: %d \n", maior);
  printf("Menor: %d \n", menor);
  }
