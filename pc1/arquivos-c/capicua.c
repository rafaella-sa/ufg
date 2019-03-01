#include <stdio.h>
void main(){
	int num, inverso, i, j, cont;
    scanf("%d", &cont);
    for(i = 0; i < cont; i++){
        inverso = 0;
        j = 1;
        scanf("%d", &num);
        while(j<=num){
           inverso*=10;
           inverso+=(num%(j*10)-num%j)/j;
           j*=10;
        }
        if(num == inverso)
            printf("S\n");
        else
            printf("N\n");
   }
}
