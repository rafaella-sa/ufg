#include <stdio.h>
void main(){
    int quant, pot, i, j, n, num;
    scanf("%d", &quant);
    for (i = 1; i <= quant; i++){
        scanf("%d", &num);
        j = 9;
        pot = 0;
        while(j >= 2 && pot == 0){
            n = j;
            while(n < num){
                n = n * j;
                if(n == num)
                pot = j;
            }
            j--;
        }
        printf("%d\n", pot);
    }
}
