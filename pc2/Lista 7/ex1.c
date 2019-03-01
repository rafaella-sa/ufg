//Rafaella Silva Almeida
//Lista 7 - Exercício 1

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    float media;
} aluno;

int main(){
    aluno *alunos;
    int i, n;
    do{
        printf("Digite a quantidade de alunos: ");
        scanf("%d", &n);
    }while(n <= 0);
    alunos = (aluno*) malloc (sizeof(aluno)*n);
    if(alunos == NULL)
        exit(1);
    for(i = 0; i < n; i++){
        printf("ALUNO %d:\n", i+1);
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite a media: ");
        scanf("%f", &alunos[i].media);
    }
    printf("\nALUNOS DE EXAME: \n");
    for(i = 0; i < n; i++){
        if(alunos[i].media < 6.0){
            printf("ALUNO %d (media %0.2f)\n", alunos[i].matricula, alunos[i].media);
        }
    }
    free(alunos);
    return 0;
}
