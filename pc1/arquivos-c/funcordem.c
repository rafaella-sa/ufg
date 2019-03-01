//Rafaella Silva Almeida
#include <stdio.h>
int ordem(int vet[10]){
    int i=0, ord=1;
    while(i<9 && ord){
        if(vet[i]>vet[i+1])
            ord = 0;
        i++;
    }
    return ord;
}
int main(){
    int i, vetor[10];
    for(i=0; i<10; i++)
        scanf("%d", &vetor[i]);
    printf("%d\n", ordem(vetor));
    return 0;
}
