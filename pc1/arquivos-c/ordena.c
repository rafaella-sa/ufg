#include <stdio.h>
void ordenaVetor(int *num,int m){
    int aux,i,j;
    for(i=0;i<m;i++)
        for(j=i+1;j<=m;j++)
            if(num[j]>num[i]){
                aux=num[j];
                num[j]=num[i];
                num[i]=aux;
            }
}
int main(){
    int i,n,num[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    ordenaVetor(num,i);
    for(i=0;i<n;i++)
        printf("%d\n",num[i]);
    return 0;
}
