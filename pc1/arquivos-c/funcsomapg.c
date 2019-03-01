//Rafaella Silva Almeida
#include <stdio.h>
#include <math.h>
int somapg(int a1, int n, int q){
    return (a1*(1-pow(q,n)))/(1-q);
}
int main(){
    int primeiro, n, razao;
    scanf("%d %d %d", &primeiro, &n, &razao);
    printf("%d\n", somapg(primeiro, n, razao));
}
