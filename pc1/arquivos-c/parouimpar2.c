#include <stdio.h>
int par(int n){
  if(n%2==0)
    return 1;
  else
    return 0;
  }
    
int main(){
  int n;
  scanf("%d", &n);
  if(par(n)==1)
    printf("O número %d É PAR.\n", n);
  else
    printf("O número %d É ÍMPAR.\n", n);
  return 0;
}