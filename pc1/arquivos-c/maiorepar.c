#include <stdio.h>
void main(){
    int n;
    scanf("%d", &n);
    if(n %2 == 0 && n > 10)
        printf("S");
    else
        printf("N");
}
