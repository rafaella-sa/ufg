#include <stdio.h>
int main() {
   float h=0;
   int i,j=1;
   for (i=1; i<=50; i++) {
      h +=(float) j / i;

      printf("%d/%d\n", j, i);
      j += 2;
   }
   printf("H = %f\n", h);
   return 0;
}
