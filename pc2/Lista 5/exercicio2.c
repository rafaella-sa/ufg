//Rafaella Silva Almeida
#include <stdio.h>

int main(){
    int x, y, *p;
    y = 0;
    p = &y; //ponteiro p aponta para y, logo *p = 0
    x = *p; //x recebe o valor que o ponteiro aponta, que é y, logo x = 0;
    x = 4; //x muda de 0 para 4
    (*p)++; //incrementa o valor q o ponteiro aponta em 1, logo *p = 1 e y = 1;
    --x; //x diminui de 4 para 3
    (*p) +=x; //o valor q o ponteiro aponta soma-se a x, logo *p = 4 e y = 4
    printf("%d %d %d", x, y, *p); //x = 3, y = 4, *p = 4
    return 0;
}
