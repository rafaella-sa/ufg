//Rafaella Silva Almeida
#include <stdio.h>
int somapa (int a1, int n, int r){
  int an = a1 + (n-1)*r;
  return ((a1+an)*n)/2;
  }
int main(){
  int primeiro, n, razao;
  scanf("%d %d %d", &primeiro, &n, &razao);
  printf("%d\n", somapa(primeiro, n, razao));
  return 0;
  }
