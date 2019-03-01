#include <stdio.h>
int euclides(int a, int b);
int main(){
	int x, y, tam, i, j;
	printf("Este Algoritmo calcula mdc pela tabela de Euclides\n\n");
	printf("Digite os valores a e b\n");
	scanf("%d%d", &x, &y);
    printf("\n");
    printf("a\tb\tq\tr\ts\tt\t\n");
	tam=euclides(x,y);
	int a[tam], b[tam], q[tam], r[tam], s[tam], t[tam]; 
	a[0]=x;
	b[0]=y;
	s[tam-1]=0;
	t[tam-1]=1;
	j=0;
	for(i=0; i<tam; i++){
	q[j]=a[j]/b[j];
	r[j]=a[j]%b[j];
	j++;
	a[j]=b[j-1];
	b[j]=r[j-1];	
	}
	for(i=tam-1; i>0; i--){
		s[i-1]=t[i];
		t[i-1]=((t[i]*(-1))*q[i-1])+s[i];
	}	
	for(i=0; i<tam; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", a[i], b[i], q[i], r[i], s[i], t[i]);
	}
	printf("\n\tmdc(%d, %d)=%d\n", x, y, b[tam-1]);
	system("PAUSE");
}
int euclides(int a, int b){
	int q, r=1, cont=0;
	while(r!=0){
		q=a/b;
		r=a%b;
		a=b;
		b=r;
		cont++;
	}
	return cont;
}
