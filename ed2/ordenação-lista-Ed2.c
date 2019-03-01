#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct lista{
	int dado;
	struct lista *ant;
	struct lista *prox;
}lista;

lista* inicializa(){
	return NULL;
}

lista* insereinicio(lista* l, int d){
	lista *novo;
	novo = (lista*) malloc(sizeof(lista));
	if(!novo){
		printf("Mem?ria n?o pode ser alocada");
		exit(0);
	}
	else{
	    novo->dado = d;
		novo->ant = NULL;
		novo->prox = NULL;
	}

	if(l==NULL){
		return novo;
	}else{
		novo->prox = l;
		return novo;

	}
}

void imprime(lista* l)
{
	lista *p;
		p = l;
		if(p==NULL){
			printf("lista vazia");
		}else{
			printf("NULL");
			while(p!=NULL){
				printf("<--[%d]-->",p->dado);
				p = p->prox;
			}

			printf("NULL");
		}
		printf("\n\n");
}


void insertionSort(lista *l, int n){
lista *i;
lista *j;
/*printf("\tAlgoritmo de Ordena%c%co por Inser%c%co(InsertionSort).\n",-121,-58,-121,-58);
printf("\nDados do vetor sem ordena%c%co:\n",-121,-58);
//mostravetor(data, n);
printf("Passos feitos para ordena%c%co:\n",-121,-58);*/


lista *k;
k = l;
    for (i = l->prox ; i->prox != NULL; i = i->prox){
        int tmp = i->dado;
            for (j = i; j->ant != NULL && tmp < (j->ant)->dado ; /*j--*/  j = j->ant){
                j->dado = (j->ant)->dado;

            }

        j->dado = tmp;
//mostravetor(data, n);
    printf("\n\n\n\ntmp = %d\n j = %d \ni = %d\n\n\n\n", tmp , j->dado , i->dado);
    }


puts("Vetor ordenado totalmente:\n");
//mostravetor(data, n);
imprime(l);

}

int main(){


srand(time(NULL));

puts("Entre com o numero de elementos do vetor:");
int n;
scanf("%d",&n);


int z;

lista *l;
l = inicializa();
//Ordenação por InsertionSort
for( z = 0 ;  z < n ; z++){
    int x = rand() %100;
     l = insereinicio(l,x);
}
imprime(l);
printf("teste\n");
insertionSort(l , n);


free(l);

return 0 ;
}

