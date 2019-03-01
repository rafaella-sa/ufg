#include <stdio.h>
int main(){
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int j;
    for(j=0; j<10; j++){
        printf("%d\n", *(vet+j));
    }
    return 0;
}
