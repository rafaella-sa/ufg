//Rafaella Silva Almeida

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dado;
    struct lista *prox;
}lista;

lista* criano(int dado){
    lista *novoNo;
    novoNo = (lista*) malloc (sizeof(lista));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

lista* inserefim (lista *inicio, int dado){
    lista* newnode = criano(dado);
    if(inicio == NULL)
        return newnode;
    else{
        lista *aux;
        for(aux = inicio; aux->prox != NULL; aux = aux->prox);
        aux->prox = newnode;
        return inicio;
    }
}

lista* insereinicio (lista *inicio, int dado){
    lista* newnode = criano(dado);
    if(inicio != NULL)
        newnode->prox = inicio;
    return newnode;
}

lista* removefim(lista *l){
	if(l==NULL)
		return l;
    else{
		lista *p, *ant;
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

lista* removeval(lista *l, int d){
	if(l==NULL)
		return l;
    else{
		lista *p, *ant, *aux;
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
			free(p);
			return l;
		}
	}
}

lista* removeinicio (lista *l){
    if(l == NULL)
        return l;
    else{
        lista *aux;
        aux = l;
        aux = aux->prox;
        free(l);
        return aux;
    }
}

void imprime(lista *inicio){
    lista *aux;
    for(aux = inicio; aux != NULL; aux = aux->prox){
        printf("%d ", aux->dado);
    }
}

int main(){
    lista *l = NULL;
    int i, n, x;
    printf("Quantidade: ");
    scanf("%d", &n);
    printf("Inserir pelo fim: ");
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        l = inserefim(l, x);
    }
    imprime(l);
    printf("\nInserir pelo inicio: ");
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        l = insereinicio(l, x);
    }
    imprime(l);
    printf("\n");
    l = removefim(l);
    imprime(l);
    printf("\n");
    l = removeinicio(l);
    imprime(l);
    printf("Elemento: ");
    scanf("%d", &x);
    l = removeval(l, x);
    imprime(l);
}
