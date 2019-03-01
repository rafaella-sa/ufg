//Rafaella Silva Almeida
#include <stdio.h>
struct imovel{
  int tipo;
  char bairro[10];
  float valor;
  int situacao;
  };
  
struct imovel imoveis[100];

void lerimoveis(int n){
  int i;  
  for(i=0; i<n; i++){
    printf("IMOVEL %d\n", i+1);
    printf("Tipo do imovel(1:loja; 2:apto; 3:casa; 4:kitnet): ");
    scanf(" %d", &imoveis[i].tipo);
    printf("Bairro: ");
    scanf(" %s", &imoveis[i].bairro);
    printf("Valor: ");
    scanf(" %f", &imoveis[i].valor);
    printf("Situacao(1:aluguel; 2:venda): ");
    scanf(" %d", &imoveis[i].situacao);
    printf("\n");
    }
}
    
void consultarimoveis(int n){
  int i, t, s;
  printf("CONSULTA DE IMOVEIS");
  printf("\n");
  printf("Ingresse o tipo e a situacao do imovel: ");
  scanf("%d %d", &t, &s);
  printf("\n");
  for(i=0; i<n; i++){
    if(imoveis[i].tipo == t && imoveis[i].situacao == s){
      puts(imoveis[i].bairro);
      printf("%f\n", imoveis[i].valor);
      }
      printf("\n");
  }
}
    
int main(){
  int n; 
  printf("Quantidade de imoveis a serem registrados: ");
  scanf(" %d", &n);
  printf("\n");
  lerimoveis(n);
  consultarimoveis(n);
  return 0;
}