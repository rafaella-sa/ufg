#include <stdio.h>

void main(){
  int m, n, num, i, j;
  scanf("%d %d %d", &m, &n, &j);
  printf("%d\n", m);
  printf("%d\n", n);
  for(i = 0; i < j-2; i++){
    num = m + n;
    m = n;
    n = num;
    printf("%d\n", num);
  }
}
