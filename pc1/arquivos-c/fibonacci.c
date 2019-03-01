#include <stdio.h>

void main(){
  int m, n, num, i;
  scanf("%d %d", &m, &n);
  printf("%d\n", m);
  printf("%d\n", n);
  for(i = 0; i < 8; i++){
    num = m + n;
    m = n;
    n = num;
    printf("%d\n", num);
  }
}
