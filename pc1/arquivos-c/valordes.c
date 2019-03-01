#include <stdio.h>
int main() {
   float s=0;
   int i, sinal=1;
   for (i=1; i<=10; i++) {
      s += sinal * (float) i / i*i;
      sinal = -sinal;
      printf("%d/%d\n", i, i*i);
   }
   printf("S = %f\n", s);
   return 0;
}
