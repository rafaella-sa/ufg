#include <stdio.h>
void main(){
    int i, n = 0;
    for (i = 0; i <= 1000; i++)
        n = (n + i) + n;
    printf("%d", n);
}
