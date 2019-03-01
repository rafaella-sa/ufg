#include <stdio.h>	
void main(){
  int cod;
  printf("Ingresse o código: ");
  scanf("%d", &cod);
  switch(cod){
    case 1: printf("Alimento não perecível \n");
	    break;
    case 2: 
    case 3: 
    case 4: printf("Alimento perecível \n");
	    break;
    case 5: 
    case 6: printf("Vestuário \n");
	    break;
    case 7: printf("Higiene pessoal \n");
	    break;
    case 8: 
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15: printf("Limpeza e utensílios domésticos \n");
	     break;
    default: printf("Opção inválida \n");
    }
}