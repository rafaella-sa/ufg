//Rafaella Silva Almeida

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int dado;
    struct pilha *prox;
}pilha;

int pilhaVazia(pilha *p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

pilha* push(pilha *p, int dado){
    pilha *novo, *aux = p;
    if((novo = (pilha*) malloc (sizeof(pilha))) == NULL){
        printf("ERRO!\n");
        exit(1);
    }
    novo->dado = dado;
    novo->prox = NULL;
    if(pilhaVazia(p)) return novo;
    else{
        novo->prox = aux;
        return novo;
    }
}

pilha* pop(pilha *p){
    if(pilhaVazia(p)) return p;
    else{
        pilha *aux = p->prox;
        free(p);
        return aux;
    }
}

pilha* poptopo(pilha *p, int *dado){
    if(pilhaVazia(p)) {
        printf("Pilha vazia, dado recebe -1.\n");
        *dado = -1;
        return p;
    }
    else{
        *dado = p->dado;
        pilha *aux = p->prox;
        free(p);
        return aux;
    }
}

void imprime(pilha *p){
    pilha *aux = NULL; int i = 1;
    for(;!pilhaVazia(p); p = p->prox){
        printf("%d. %d\n", i++, p->dado);
        aux = push(aux, p->dado);
    }
    printf("\n");
    for(;!pilhaVazia(aux); aux = aux->prox){
        p = push(p, aux->dado);
    }
}

int main(){
    pilha *p = NULL; int dado;
    p = push(p, 10);
    imprime(p);
    p = push(p, 20);
    imprime(p);
    p = push(p, 30);
    imprime(p);
    p = pop(p);
    imprime(p);
    p = poptopo(p, &dado);
    printf("TOPO: %d\n\n", dado);
    imprime(p);
    return 0;
}
