#include <stdio.h>
int main(){
    int matriz[100][100];
    int i, j, m, n, sf, sc, prod = 0;
    scanf("%d %d", &m, &n);
    if(m!=1 && n!=1){
       for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&matriz[i][j]);
       for(i=0; i<m; i++){
            sf=0;
            sc=0;
            for(j=0; j<n; j++){
                sf=sf+matriz[i][j];
                sc=sc+matriz[j][i];
            }
            if(sf>sc){
                if(sf>prod)
                    prod=sf;
                }
            else if(sc>sf)
                if(sc>prod)
                    prod=sc;
            }
    }
    else if(m==1)
        for(i=0; i<n; i++){
            scanf("%d",&matriz[0][i]);
            prod=prod+matriz[0][i];
        }
    else if(n==1)
        for(i=0; i<m; i++){
            scanf("%d", &matriz[i][0]);
            prod=prod+matriz[i][0];
                }
    printf("%d",prod);
    return 0;
}
