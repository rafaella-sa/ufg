#include <stdio.h>
int main(){
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int m, n, soma, I, J, P, Q, R, S, X, Y, k, l;
    scanf("%d",&n);
    scanf("%d %d %d %d %d %d", &P, &Q, &R, &S, &X, &Y);
    for(k=0; k<n; k++)
        for(l=0; l<n; l++){
            A[k][l]=(P*(k+1)+Q*(l+1))%X;
            B[k][l]=(R*(k+1)+S*(l+1))%Y;
            }
    for(k=0; k<n; k++)
        for(l=0; l<n; l++){
            soma=0;
            for(m=0; m<n; m++)
                soma=soma+((A[k][m]*B[m][l]));
            C[k][l]=soma;
        }
    scanf("%d %d",&I,&J);
    printf("%d",C[I-1][J-1]);
    return 0;
}
