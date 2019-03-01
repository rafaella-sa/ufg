#include <stdio.h>

int n,i,m,vet[50];

int main ()
{
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&vet[i]);

    for(i=0; i<n; i++)
    {
        m=0;
        if((i>0)&&(vet[i-1]==1)) m++;
        if(vet[i]==1) m++;
        if((i<n)&&(vet[i+1]==1)) m++;
        printf("%d\n",m);
    }
    return 0;
}
