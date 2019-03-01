#include <stdio.h>
void main(){
    int i, j, vet[20], pedras, sapos, pos, dist;
    scanf("%d %d", &pedras, &sapos);
    for(i = 0; i < pedras; i++)
        vet[i] = 0;
    for(i = 1; i <= sapos; i++){
        scanf("%d %d", &pos, &dist);
        j = pos - 1;
        vet[j] = 1;
        while(j < pedras){
            j = j + dist;
            if(j < pedras)
                vet[j] = 1;
        }
        j = pos - 1;
        while(j >= 0){
            j = j - dist;
            if(j >= 0)
                vet[j] = 1;
        }
    }
    for(i = 0; i < pedras; i++){
        printf("%d\n", vet[i]);
    }
}
