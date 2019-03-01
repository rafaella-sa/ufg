#include <stdio.h>
int main(){
    int i, j, A[3][3], d = 0;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &A[i][j]);
    for(i = 0; i < 3; i++)
        d = d + A[i][i];
    printf("%d", d);
    return 0;
}
