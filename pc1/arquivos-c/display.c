#include <stdio.h>
int display(int *vet, int tam){
  int i;
  for(i = 0; i < tam; i++)
    printf("%d ", *(vet+i));
  printf("\n");
}
int main(){
  int i, tamanho;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho);
  int vetor[tamanho];
  for(i = 0; i<tamanho; i++)
    vetor[i] = i;
  display(vetor, tamanho);
  return 0;
}