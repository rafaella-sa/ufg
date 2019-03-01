//Rafaella Silva Almeida
#include <stdio.h>

void troca (int *i, int *j);

int main(){
    //letra a
    int x, *p;
    x = 100;
    /* p = x;. Nao há ponto final após o ponto-e-vírgula.
    Atribuição incorreta: iguala um inteiro a um ponteiro para inteiro.
    O correto seria:*/
    p = &x;
    printf("Valor de p: %d.\n", *p);
    return 0;
}

//letra b: Não há erros neste código.
void troca (int *i, int *j) {
        int *temp;
        *temp = *i;
        *i = *j;
        *j = *temp;
    }
