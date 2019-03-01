//Rafaella Silva Almeida

#include <stdio.h>
#include <stdlib.h>

typedef struct listad{
	int dado;
	struct listad *ant;
	struct listad *prox;
}listad;

listad* inicializa(){
	return NULL;
}

listad* insereinicio(listad* l, int d){
	listad *novo;
	novo = (listad*) malloc(sizeof(listad));
	if(!novo){
		printf("Memória não pode ser alocada");
		exit(0);
	}else{
		novo->dado = d;
		novo->ant = NULL;
		novo->prox = NULL;
	}

	if(l==NULL)
		return novo;
	else{
		novo->prox = l;
		return novo;
	}
}

listad* inserefim(listad* l, int d){
	listad *novo;
	novo = (listad*) malloc(sizeof(listad));
	if(!novo){
		printf("Memória não pode ser alocada");
		exit(0);
	}else{
		novo->dado = d;
		novo->ant = NULL;
		novo->prox = NULL;
	}

	if(l==NULL)
		return novo;
	else{
        listad *aux = l;
        for(;aux->prox!=NULL;aux=aux->prox);
        aux->prox = novo;
		novo->ant = aux;
		return l;
	}
}

void imprime(listad* l){
	listad *p;
    p = l;
    if(p==NULL)
        printf("lista vazia");
    else{
        printf("NULL");
        while(p!=NULL){
            printf("<--[%d]-->",p->dado);
            p = p->prox;
        }
        printf("NULL");
    }
    printf("\n");
}

listad* removeinicio (listad *l){
    if(l == NULL)
        return l;
    else{
        listad *aux;
        aux = l;
        aux = aux->prox;
        aux->ant = NULL;
        free(l);
        return aux;
    }
}

listad* removefim(listad *l){
	if(l==NULL)
		return l;
    else{
		listad *p, *ant;
		p = l;
		ant = NULL;
		while(p->prox != NULL){
			ant = p;
			p = p->prox;
		}
		if(ant == NULL){
			free(p);
			return NULL;
		}else{
			ant->prox = p->prox;
			free(p);
		}
		return l;
	}
}

listad* removeval(listad *l, int d){
	if(l==NULL)
		return l;
    else{
		listad *p, *ant, *aux;
		p = l;
		aux = l;
		ant = NULL;
		while(p->prox != NULL && p->dado != d){
			ant = p;
			p = p->prox;
		}
		if(p->prox == NULL){
            printf("Elemento nao encontrado. \n");
            return aux;
		}
		else if(ant == NULL){
			free(p);
			return NULL;
		}else{
			ant->prox = p->prox;
			(p->prox)->ant = p->ant;
			free(p);
			return l;
		}
	}
}

int main(){
	listad* l;
	l = inicializa();
	l = insereinicio(l,2);
	imprime(l);
	l = inserefim(l,4);
	imprime(l);
	l = insereinicio(l,5);
	imprime(l);
	l = inserefim(l,9);
	imprime(l);
	l = removeinicio (l);
	imprime(l);
	l = removeval (l, 4);
	imprime(l);
	l = removefim (l);
	imprime(l);
    return 0;
}
