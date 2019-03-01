#include <stdio.h>
#include <string.h>
int main(){
  char frase[50];
  gets(frase);
  char *pfrase;
  pfrase=&frase[strlen(frase)-1];
  while(pfrase>=&frase[0]){
    printf("O caracter %c esta no endereco %p\n", *pfrase, pfrase);
    pfrase--;
  }
  return 0;
}