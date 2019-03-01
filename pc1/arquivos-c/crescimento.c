#include <stdio.h>
void main(){
  double a = 1.5; 
  double f = 1.1;
  int cont = 0;
  while(a >= f){
    a = a + 0.02;
    f = f + 0.03;
    cont++;
  }
  printf("%d\n", cont);
}