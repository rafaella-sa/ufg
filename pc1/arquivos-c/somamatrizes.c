#include <stdio.h>
int main(){
    int i, j, n, A[10][10], B[10][10], C[10][10];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    printf("\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    printf("\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            C[i][j] = A[i][j]+B[i][j];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
        }
    return 0;
}
