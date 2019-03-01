#include <stdio.h>
void main(){
  int n1, n2, div, cont = 0;
  scanf("%d %d", &n1, &n2);
  div = n1;
  do{
    div = div - n2;
    cont++;
    }
  while(div - n2 >= 0);
  printf("%d %d\n", div, cont);
  }
