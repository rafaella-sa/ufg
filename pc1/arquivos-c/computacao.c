#include <stdio.h>
void main(){
    int aux, num, base4, i, j, cont;
    scanf("%d", &cont);
    for(i = 1; i <= cont; i++){
        scanf("%d", &num);
        base4 = 0;
        j = 1;
        aux = num;
        while(aux > 0){
           base4+=(aux%(4)*j);
           aux = aux/4;
           j*=10;
        }
        printf("%d\n", base4);
   }
}
