#include <stdio.h>
void somarNum(int *num,int M){
    int i,somapar=0,somaimpar=0;
    for(i=0;i<M;i++){
        if(num[i]%2==0)
            somapar=somapar+num[i];
        else
            somaimpar=somaimpar+num[i];
    }
    for(i=0;i<M;i++){
        if(i%2==0)
            num[i]=somapar;
        else
            num[i]=somaimpar;
    }
}
int main(){
    int i,N,num[20];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&num[i]);
    somarNum(num,N);
    for(i=0;i<N;i++)
        printf("%d\n",num[i]);
    return 0;
}
