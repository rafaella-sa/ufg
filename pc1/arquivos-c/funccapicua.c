//Rafaella Silva Almeida
#include <stdio.h>
int capicua(int n){
  int i=1, inverso=0;
  while(i<=n){
      inverso*=10;
      inverso+=(n%(i*10)-n%i)/i;
      i*=10;
  }
  if(n == inverso)
     return 1;
  else
     return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", capicua(n));
    return 0;
   }

