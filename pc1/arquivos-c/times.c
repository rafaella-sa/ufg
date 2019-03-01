#include <stdio.h>
int main(){
  char nome[100], auxnome[100];
  char nomes[100][100];
  int hab[100];
  int i, j, T, H, K, N, auxhab, time;
  scanf("%d %d", &N, &T);
  for(i = 0; i < N; i++){
    gets(nomes[i]);
    scanf("%d", &H);   
    hab[i] = H;
    }
  for(i = 0; i < N-1; i++)
    for(j = i+1; j < N; j++)
      if(hab[j] > hab[i]){
	auxhab = hab[i];
	hab[i] = hab[j];
	hab[j] = auxhab;
	strcopy(auxnome, nomes[i]);
	strcopy(nomes[i], nomes[j]);
	strcopy(nomes[j], auxnome);
	/*auxnome = nomes[i];
	nomes[i] = nomes[j];
	nomes[j] = auxnome;*/
      }
  
  for(time = 1; time <= T; time++){    
    i = time - 1;
    printf("Time %d", time);
    while(i < N){
      puts(nomes[i]);
      i = i + T;
    }
    printf("\n");
  }
  return 0;
}