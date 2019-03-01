#include <stdio.h>
int main(){
    int matriz[100][100], auxmin[100][100], auxmax[100][100];
    int minimax = -1, i, j, n, f, c, min, max;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            scanf("%d",&matriz[i][j]);
            auxmin[i][j]=1000;
            auxmax[i][j]=-1;
        }
    for(i=0; i<n; i++){
        min=matriz[i][0];
        max=matriz[0][i];
        for(j=0; j<n; j++){
            if(matriz[i][j]<min)
                min=matriz[i][j];
            if(matriz[j][i]>max)
                max=matriz[j][i];
        }
        for(j=0; j<n; j++){
            auxmin[i][j]=min;
            auxmax[j][i]=max;
        }
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        if(auxmin[i][j]==auxmax[i][j]){
            f=i+1;
            c=j+1;
            minimax=auxmax[i][j];
        }
    if(minimax==-1)
        printf("N\n");
    else
        printf("%d %d %d\n", minimax, f, c);
    return 0;
}
