#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"

Lista* inicializa(){
	return NULL;
}

int tamanhoLista(Lista* li){
    if(li == NULL) //lista vazia: 0 elementos
        return 0;
    int cont = 0;
    Lista *no = li;
    while(no != NULL){ //ate o fim da lista
        cont++; //conta os elementos
        no = no ->prox;
    }
    return cont;
}

Lista* insereInicio(Lista* l, int d){
	Lista *novo; //cria no da lista
	novo = (Lista*) malloc(sizeof(Lista));
	if(!novo){ //se criacao falhou
		printf("Memória não pode ser alocada");
		exit(1);
	}else{ //se deu certo associa os dados
		novo->dado = d;
		novo->ant = NULL;
		novo->prox = NULL;
	}
	printf("Elemento inserido com sucesso!\n\n");
	if(l==NULL) //se a lista esta vazia
		return novo; //novo e o primeiro elemento
	else{ //se nao esta vazia
		novo->prox = l; //aponta para o inicio atual
		return novo; //novo agora e o inicio
	}
}

Lista* insereFim(Lista* l, int d){
	Lista *novo; //cria no da lista
	novo = (Lista*) malloc(sizeof(Lista));
	if(!novo){ //se criacao falhou
		printf("Memória não pode ser alocada");
		exit(1);
	}else{ //se deu certo associa os dados
		novo->dado = d;
		novo->ant = NULL;
		novo->prox = NULL;
	}
	printf("Elemento inserido com sucesso!\n\n");
	if(l==NULL) //se a lista esta vazia
		return novo; //novo e o inicio da lista
	else{ //se nao esta vazia
        Lista *aux = l; //procura posicao
        for(;aux->prox!=NULL;aux=aux->prox);
        aux->prox = novo; //configura ponteiros
		novo->ant = aux;
		return l;
	}
}

Lista* removeInicio (Lista *l){
    if(l == NULL){ //se esta vazia
        printf("Lista vazia!\n\n");
        return l;
    }
    else{ //se nao esta
        Lista *aux; //sera o novo inicio
        aux = l;
        aux = aux->prox; //configura ponteiros
        aux->ant = NULL;
        free(l); //libera primeiro elemento
        printf("Elemento removido com sucesso!\n\n");
        return aux;
    }
}

Lista* removeFim(Lista *l){
	if(l==NULL){ //se esta vazia
        printf("Lista vazia!\n\n");
		return l;
	}
    else{ //se nao esta
		Lista *p, *ant;
		p = l;
		ant = NULL; //ira receber o ultimo elemento
		while(p->prox != NULL){ //percorre a lista
			ant = p; //ate o fim
			p = p->prox;
		}
		if(ant == NULL){ //lista so tinha um elemento
			free(p);
			printf("Elemento removido com sucesso!\n\n");
			return NULL; //ficou vazia
		}else{ //lista tinha mais de um elemento
			ant->prox = p->prox; //configura ponteiros
			free(p); //libera elemento
			printf("Elemento removido com sucesso!\n\n");
		}
		return l;
	}
}

Lista* removeValor(Lista *l, int d){
	if(l==NULL){ //se esta vazia
        printf("Lista vazia!\n\n");
		return l;
	}
    else{ //se nao esta
		Lista *p, *ant, *aux;
		p = l; //ira receber o elemento a ser eliminado
		aux = l; //variavel de controle do 'while'
		ant = NULL; //auxiliar
		while(p->prox != NULL && p->dado != d){
			ant = p; //procurando o valor
			p = p->prox;
		}
		if(p->prox == NULL){ //se nao encontrou - fim da lista
            printf("Elemento nao encontrado. \n");
            return aux;
		}
		else if(ant == NULL){ //remocao do elemento unico
			free(p);
			printf("Elemento removido com sucesso!\n\n");
			return NULL;
		}else{ //se havia mais de um elemento
			ant->prox = p->prox; //configura ponteiros
			(p->prox)->ant = p->ant;
			free(p); //libera elemento
			printf("Elemento removido com sucesso!\n\n");
			return l;
		}
	}
}


void imprime(Lista* l){
	Lista *p; //controla o laco 'for'
    p = l;
    if(p==NULL) //se esta vazia
        printf("Lista vazia!\n\n");
    else{ //se nao esta
        printf("\nNULL");
        while(p!=NULL){
            printf("<--[%d]-->",p->dado);
            p = p->prox;
        }
        printf("NULL\n\n");
    }
}

Lista* ponteiroElem(Lista* inicio, int pos){
    if(pos > tamanhoLista(inicio) - 1 || pos < 0) {
           printf("\n\nErro. Posicao inexistente.\n\n");
           return NULL; //posicao invalida
       }
    int cont = 0; //conta os elementos
    while(cont < pos) { //procura a posicao
            inicio = inicio->prox;
            cont++;
    }
    return inicio; //retorna o elemento na posicao dada
}

void insertionSort(Lista *l){
    if(l == NULL){ //se esta vazia
        printf("Lista vazia!\n\n");
        return; //nao continua a ordenar
    }
    int i, j; //controle dos lacos
    for(j = 1; j < tamanhoLista(l); j++){
        i = j - 1;
        int troca = ponteiroElem(l, j)->dado;
        //procura a posicao certa de insercao de forma decrescente
        while(i >= 0 && ponteiroElem(l, i)->dado > troca){
                 ponteiroElem(l, i+1)->dado = ponteiroElem(l, i)->dado;
                 i--;
        }
        ponteiroElem(l, i+1)->dado = troca;
        //mostra o estado atual da lista
        printf("Ordem parcial: (passo %d)\n", j);
        imprime(l);
    } //mostra o estado final da lista
    printf("LISTA ORDENADA:\n");
    imprime(l);
}

int leitura(){
    int n; //recebe o valor inserido pelo usuario
    printf("Ingresse o valor desejado: ");
    scanf("%d", &n);
    return n;
}

void opcoesMenu(){ //todas as opcoes disponiveis no menu
    printf("ORDENACAO DE LISTA DUPLAMENTE ENCADEADA - INSERTION SORT\n\n");
    printf("1. Inserir elemento - inicio\n");
    printf("2. Inserir elemento - final\n");
    printf("3. Remover elemento - inicio\n");
    printf("4. Remover elemento - final\n");
    printf("5. Remover elemento - valor desejado\n");
    printf("6. Ordenar lista - Insertion Sort\n");
    printf("7. Imprimir lista\n\n");
    printf("0. SAIR\n\n");
    printf("Selecione uma opcao valida: ");
}

void menu(){
    int op; //variavel que controla o menu
    Lista* l = inicializa();
    do{
        opcoesMenu();
        scanf("%d", &op);
        switch(op){
            case 0: { //SAIR
                    printf("Encerrando...\n");
                    break;
            }
            case 1: { //Inserir elemento - inicio
                    l = insereInicio(l, leitura());
                    break;
            }
            case 2: { //Inserir elemento - final
                    l = insereFim(l, leitura());
                    break;
            }
            case 3: { //Remover elemento - inicio
                    l = removeInicio(l);
                    break;
            }
            case 4: { //Remover elemento - final
                    l = removeFim(l);
                    break;
                    }
            case 5: { //Remover elemento - valor desejado
                    l = removeValor(l, leitura());
                    break;
                    }
            case 6: { //Ordenar lista - Insertion Sort
                    insertionSort(l);
                    break;
            }
            case 7: { //Imprimir lista
                    imprime(l);
                    break;
            }
            default:{
                    printf("OPCAO INVALIDA!!!\n\n");
                    break;
            }
        }
    }while(op != 0);
    free(l);
}

