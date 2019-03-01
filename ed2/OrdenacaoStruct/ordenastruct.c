#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenastruct.h"

int comparaAnoIngresso(aluno a, aluno b){
    return (a.anoIngresso < b.anoIngresso);
}

int comparaCurso(aluno a, aluno b){
    return (strcmp(a.curso, b.curso) < 0);
}

int comparaMatricula(aluno a, aluno b){
    return (a.matricula < b.matricula);
}

int comparaNome(aluno a, aluno b){
    return (strcmp(a.nome, b.nome) < 0);
}

int comparaAlunos(aluno a, aluno b, int opcao){
    //ponteiro para funcao que seleciona o criterio
    int (*compara)();
    switch(opcao){
        case 1:{
                compara = comparaAnoIngresso;
                break;
        }
        case 2:{
                compara = comparaCurso;
                break;
        }
        case 3:{
                compara = comparaMatricula;
                break;
        }
        case 4:{
                compara = comparaNome;
                break;
        }
    }
    //realiza a comparacao de acordo com a opcao
    //selecionada e devolve o resultado
    return compara(a, b);
}

void shellSort (aluno data[], int arrSize, int opcao){
    register int i, j, hCnt, h;
    int increments[20], k;
    for (h=1, i=0; h < arrSize; i++){
        increments[i] = h;
        h = 3*h + 1;
    }
    for (i--; i >= 0; i--) {
        h = increments[i];
        for (hCnt = h; hCnt < 2*h; hCnt++) {
            for (j = hCnt; j < arrSize;){
                aluno tmp = data[j];
                k = j;
                //chama a funcao de comparacao correta de acordo com a
                //opcao selecionada pelo usuario
                while (k-h >= 0 && comparaAlunos(tmp, data[k-h], opcao)){
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
}

