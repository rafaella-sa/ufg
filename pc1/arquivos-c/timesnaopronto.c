#include <stdio.h>
int main(){
    int N, T, H, i, j, k, auxint;
    char[100] vetnome[100];
    int[100] vethab;
    char[100] times[100];
    char[100] nome, auxchar;
    scanf("%d %d", &N, &T);
    for(i = 0; i < N; i++){
        gets(nome);
        scanf(" %d", &H);
        vetnome[i] = nome;
        vethab[i] = H;
    }
    for(i=0;i<N;i++)
        for(j=i+1;j<=N;j++)
            if(vethab[j]>vethab[i]){
                auxint = vethab[j];
                auxchar = vetnome[j];
                vethab[j] = vethab[i];
                vetnome[j] = vetnome[i];
                vethab[i] = auxint;
                vetnome[i] = auxchar;
            }
    for(i = 0; i < T; i++){
        j = 0;
        k = 0;
        while(j < N){
            time[k] = vetnome[j];
            j += T;
            k++;
        }
        for(l=0;l<N;l++)
        for(m=i+1;m<=N;m++)
            if(vethab[j]>vethab[i]){
                auxint = vethab[j];
                auxchar = vetnome[j];
                vethab[j] = vethab[i];
                vetnome[j] = vetnome[i];
                vethab[i] = auxint;
                vetnome[i] = auxchar;
            }

    }
         //   times[i][j] = "nenhum";
    for(i = 0; i < N)
    return 0;
}
