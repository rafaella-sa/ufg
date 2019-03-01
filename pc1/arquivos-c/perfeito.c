#include <stdio.h>
int perfeito(int num){
    int np, n;
    np = 0;
    for(n = 1; n < num; n++){
            if(num % n == 0)
                np = np + n;
        }
    if(np == num)
        return 1;
    else
        return 0;
}
void main(){
    int i, p, num, N;
    scanf("%d\n", &N);
    for(i = 1; i <= N; i++){
        scanf("%d", &num);
        p = perfeito(num);
        printf("%d\n", p);
    }
}
