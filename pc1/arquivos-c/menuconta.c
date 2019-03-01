#include <stdio.h>
void main(){
  int opcao, a, b;
  scanf("%d", &opcao);
  case 1: {
	  int soma = a + b;
	  printf("Soma: %d \n", soma);
	  break;
	  }
  case 2: {
	  int sub = a - b;
	  printf("Subtração: %d \n", sub);
	  break;
	  }
  case 3: {
	  int mult = a * b;
	  printf("Multiplicação: %d \n", mult);
	  break;
	  }
  case 4: {
	  int div;
	  if(b!=0){
	    div = a/b;
	    printf("Divisão: %d \n", div);
	    }
	  else
	    printf("Não se pode fazer divisão por 0.");
	  break;
	  }
  case 5: {

	  double raiz = sqrt(a);
	  printf("Raiz de 'A': %d", raiz);
	  break;
	  }

