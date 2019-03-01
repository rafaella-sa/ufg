#include <stdio.h>
int main(){
    int mat[10][10];
    int *p;
    int i, j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++)
            mat[i][j] = i+j;
    }
    p = mat[0];
    for(i=0; i<100; i++){
        printf("%d ", *p);
        p++;
        if((i+1)%10 == 0)
            printf("\n");
    }
    return 0;
}
