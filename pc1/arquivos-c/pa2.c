#include <stdio.h>
void main(){
    int num[20];
    int r, t, N;
    char pa = 'V';
    do
        scanf("%d", &N);
    while(N <= 1 && N > 20);
    for(t = 0; t < N; t++)
        scanf("%d", &num[t]);
    r = num[1] - num[0];
    t = 2;
    do{
        if(num[t] - num[t-1] != r)
            pa = 'F';
        t++;
    }
    while(pa == 'V' && t < N);
    if(pa == 'V')
        printf("%d\n", r);
    else
        printf("N\n");
    }
