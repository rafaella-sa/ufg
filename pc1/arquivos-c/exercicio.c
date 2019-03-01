#include <stdio.h>
int var;
void naoMudaVar(){
 int var=100;
 }

 void muda(){
var=200;
 }

int main () {
    var=10;
    naoMudaVar();
    printf("\n%d",var);
    muda();
    printf("\n%d\n",var);
    char *ps = "Este ponteiro aponta para o inicio desta frase.";
    printf("%s\n", ps);
    int y, *p, x;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x = x - 1;
    (*p)= (*p)+x;
    printf ("y = %d \n", y);
    return 0;
}
