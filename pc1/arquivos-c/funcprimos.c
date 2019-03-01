//Rafaella Silva Almeida
#include <stdio.h>
int primo(int n){
    int i, div=0;
    if(n==1 || n==2)
       return -1;
    else if (n%2==0)
        return 0;
        else{
            for(i=3; i<=n; i++){
                if(n%i==0)
                    div++;
            }
            if(div>1)
                return 0;
            else
                return -1;
        }
}
int main(){
    int i, n1, n2;
    while(n1>n2)
        scanf("%d %d", &n1, &n2);
    for(i=n1; i<=n2; i++){
        if(primo(i) == 0)
            printf("O numero %d NAO E PRIMO.\n", i);
        else
            printf("O numero %d E PRIMO.\n", i);
    }
    return 0;
}
