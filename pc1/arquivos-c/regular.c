#include <stdio.h>
void main(){
    int i, n, cont;
    scanf("%d", &cont);
    for(i = 1; i <= cont; i++){
        scanf("%d", &n);
        if(n % 7 != 0)
            printf("1\n");
        else
            printf("0\n");
    }
}
