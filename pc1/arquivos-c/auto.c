#include <stdio.h>
void main(){
  char painel;
  int C, unid, i;
  scanf("%d", &C);
  unid = 0;
  for(i = 1; i <= C; i++){
    scanf(" %c", &painel);
    switch(painel){
      case 'C':
      case 'P': {
		unid = unid + 2;
		break;		
		}
      case 'A': {
		unid = unid + 1;
		break;
		}
    }
  }
  printf("%d\n", unid);
}