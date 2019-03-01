#include <stdio.h>
void main(){
    int i, n, fat = 1;
    scanf("%d", &n);
    if(n == 0 || n == 1)
        printf("1\n");
    else{
        for(i = n; i >= 1; i--)
            fat = fat * i;
        printf("%d\n",fat);
    }
}
