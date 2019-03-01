#include <stdio.h>
int primo(int n){
  int i, div = 0;
  if(n%2==0)
    return 0;
  else{
    for(i=3; i<=n; i++){
      if(n%i==0)
	div++;
    }
    if(div>2)
      return 0;
    else
      return -1;
    }
}
  
int main(){
  int n;
  scanf("%d", &n);
  if(primo(n) == 0)
    printf("O número %d NÃO É PRIMO.\n", n);
  else
    printf("O número %d É PRIMO.\n", n);
  return 0;
}