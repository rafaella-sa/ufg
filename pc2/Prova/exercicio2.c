//Rafaella Silva Almeida
//Prova 2 - Exercício 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int dado;
    struct lista* prox;
}lista;

lista* inserefim(lista* l, int dado){
    lista* novo = (lista*) malloc (sizeof(lista));
    if(novo == NULL){
        printf("Nao foi possivel inserir o dado.\n");
        exit(1);
    }
    novo->dado = dado;
    novo->prox = NULL;
    if(l == NULL)
        return novo;
    else{
        lista *aux = l;
        for(;aux->prox != NULL; aux = aux->prox);
        aux->prox = novo;
        return l;
    }
}

lista* removefim(lista* l){
    if(l == NULL)
        return l;
    else{
        lista *ant = NULL, *aux = l;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            free(aux);
            return NULL;
        }
        else{
            ant->prox = NULL;
            free(aux);
            return l;
        }
        return l;
    }
}

void imprime(lista* l){
    if(l == NULL)
        printf("NULL\n");
    else{
        lista *aux = l;
        for(;aux != NULL; aux = aux->prox)
            printf("%d -> ", aux->dado);
        printf("NULL\n");
    }
}

void imprimemenor(lista* l){
    int menor;
    printf("Menor elemento na lista: ");
    if(l == NULL)
        printf("NULL\n");
    else{
        lista *aux = l;
        menor = aux->dado;
        for(;aux->prox != NULL; aux = aux->prox)
            if(aux->dado < menor)
                menor = aux->dado;
        printf("%d\n", menor);
    }
}

void imprimeenesimo(lista *l, int n){
    printf("Enesimo elemento na lista: ");
    if(l == NULL)
        printf("NULL\n");
    else{
        lista *aux = l; int i;
        for(i = 1; aux->prox != NULL && i<n; aux = aux->prox, i++);
        if(aux->prox == NULL || i != n)
            printf("Nao encontrado.\n");
        else
            printf("%d\n", aux->dado);
    }
}

int main(){
    lista *l = NULL;
    int n, r; char c;
    printf("INSERCAO:\n\n");
    do{
        printf("Insira um inteiro na lista (-1 para parar): ");
        scanf("%d", &n);
        if(n != -1)
            l = inserefim(l, n);
    }while(n != -1);
    printf("\n");
    imprime(l);
    printf("\nREMOCAO:\n\n");
    do{
        printf("Deseja remover o ultimo elemento? (S/N): ");
        scanf(" %c", &c);
        if(c == 's' || c == 'S')
            l = removefim(l);
        imprime(l);
        if(l == NULL)
            printf("\nLista vazia!\n");
    }while((c == 's' || c == 'S' ) && l != NULL);
    imprimemenor(l);
    printf("\nInsira o enesimo elemento: ");
    scanf("%d", &n);
    imprimeenesimo(l, n);
    return 0;
}
