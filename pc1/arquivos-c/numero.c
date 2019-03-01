#include <stdio.h>
void main(){
	int num;
	printf("Ingresse o número a ser invertido: \n");
	scanf("%d", &num);
	while(num !=0){
		printf("%d", num%10);
		num /=10;
	}
	printf("\n");
}
