#include <stdio.h>
void main(){
    int aux, i = 1, n, raiz = 0;
    scanf("%d", &n);
    aux = n;
    while(aux > 0){
        aux = aux - i;
        raiz++;
        i = i + 2;
    }

    printf("%d\n", raiz);
}
