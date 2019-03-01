#include <stdio.h>
void main(){
    int num[20];
    int i, env, N;
    do
        scanf("%d", &N);
    while(N > 20 && N <= 0);
    for(i = 0; i < N; i++)
        scanf("%d", &num[i]);
    env = num[0];
    for(i = 1; i < N; i++)
        if(num[i] < env)
            env = num[i];
    printf("%d\n", env);
}
