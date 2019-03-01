//Rafaella Silva Almeida
#include <stdio.h>
int binario(int n){
    int aux, base2, j, cont;
    base2 = 0;
    j = 1;
    aux = n;
    while(aux > 0){
        base2+=(aux%(2)*j);
        aux = aux/2;
        j*=10;
    }
    return base2;
}
int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n", binario(num));
    return 0;
}
