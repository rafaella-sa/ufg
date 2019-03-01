/* Estruturas de Dados 2
   Exercicio de programacao 4
   Rafaella Silva Almeida

Metodo Insertion Sort em lista duplamente ligada

Em um exemplo da implementacao com vetores, para o caso em
que ha 'k' elementos fora da ordem antes do elemento atual,
deveriamos fazer a movimentacao destes 'k' elementos em
memoria, fazendo copias dos mesmos nas posicoes subsequentes,
ate encontrarmos a posicao ideal para o elemento atual.

Ja na implementacao com listas ligadas, basta armazenarmos a
posicao dos ponteiros e utilizá-las para realizar a ordenacao.
A quantidade de movimentacoes cai consideravelmente, visto que,
para a recolocacao de um elemento na sequencia, em vez de
movimentar os 'k' elementos desordenados, como antes, apenas
percorremos a lista até encontrar a posicao correta e fazemos
uma unica mudanca de referencias dos ponteiros.

*/

#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"

int main(){
    menu();
    return 0;
}
