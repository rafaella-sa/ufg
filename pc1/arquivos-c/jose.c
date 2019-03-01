#include <stdio.h>
void main(){
	int A, B, i, numa, numb;
	scanf("%d %d", &A, &B);
    numa = 0;
    numb = 0;
    i=1;
    while(i<=A){
       numa*=10;
       numa+=(A%(i*10)-A%i)/i;
       i*=10;
   }
   i = 1;
   while(i<=B){
       numb*=10;
       numb+=(B%(i*10)-B%i)/i;
       i*=10;
   }
	if(numa > numb)
        printf("%d", numa);
    else
        printf("%d", numb);
	}

