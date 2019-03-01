//Rafaella Silva Almeida
//Lista 10 - Exercício 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *file;
    if((file = fopen("ex3.txt", "w")) == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    int x1, x2, y1, y2;
    float d;
    printf("Digite as coordenadas (x1, y1) e (x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    fprintf(file, "Distancia entre (%d, %d) e (%d, %d): %.1f", x1, y1, x2, y2, d);
    fclose(file);
    return 0;
}
