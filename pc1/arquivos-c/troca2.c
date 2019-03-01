#include <stdio.h>
void troca(int *x, int *y){
  int aux;
  aux = *x
  *x = *y;
  *y = aux;
  }
  
int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("Antes da troca: %d %d %d\n", a, b, c);
  /*
  if(a<b){
    if(b>c){
      if(a<c)
	troca(&b, &c);
      else{
	troca(&a, &c);
	troca(&b, &a);
	}
    }
  }
  else{ 
    if(b<c){
      if(a<c)
	troca(&a, &b);
      else{
	troca(&a, &b);
	troca(&a, &c);
      }
    }
    else
      troca(&a, &c);
  }*/
  if(a>b) troca(&a, &b);
  if(b>c) troca(&b, &c);
  if(c>a) troca(&c, &a);
  if(a>b) troca(&a, &b);
  printf("Depois da troca: %d %d %d\n", a, b, c);
  return 0;
}