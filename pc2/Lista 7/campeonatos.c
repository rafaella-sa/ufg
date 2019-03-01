//Rafaella Silva Almeida
//Lista 7.1 - Exercício - Campeonatos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct piloto{
    char nome[30];
    int idade;
}piloto;

typedef struct circuito{
    float km;
    char nome[50];
    char pais[30];
}circuito;

typedef struct escuderia{
    char nome[50];
    piloto *pilots;
}escuderia;

typedef struct campeonato{
    char nome[30];
    escuderia *equipes;
    circuito *pistas;
}campeonato;

int main(){
    int t, c, e, p;
    campeonato *torneio;
    torneio = (campeonato*) malloc (sizeof(campeonato)*2);
    if(torneio == NULL)
        exit(1);
    for(t = 0; t < 2; t++){
        torneio[t].pistas = (circuito*) malloc (sizeof(circuito)*5);
        if(torneio[t].pistas == NULL)
            exit(1);
        torneio[t].equipes = (escuderia*) malloc (sizeof(escuderia)*7);
        if(torneio[t].equipes == NULL)
            exit(1);
        for(e = 0; e < 7; e++){
            torneio[t].equipes[e].pilots = (piloto*) malloc (sizeof(piloto)*2);
            if(torneio[t].equipes[e].pilots == NULL)
                exit(1);
        }
    }
    for(t = 0; t < 2; t++){
        printf("CAMPEONATO %d\n\n", t+1);
        printf("NOME: ");
        scanf("%s", torneio[t].nome);
        printf("\n");
        for(c = 0; c < 5; c++){
            printf("CIRCUITO %d\n\n", c+1);
            printf("NOME: ");
            scanf("%s", torneio[t].pistas[c].nome);
            printf("PAIS: ");
            scanf("%s", torneio[t].pistas[c].pais);
            printf("QUILOMETRAGEM: ");
            scanf("%f", torneio[t].pistas[c].km);
            fflush(stdin);
            printf("\n");
        }
        printf("\n");
        for(e = 0; e < 7; e++){
            printf("ESCUDERIA %d\n\n", e+1);
            printf("NOME: ");
            scanf("%s", torneio[t].equipes[e].nome);
            for(p = 0; p < 2; p++){
                printf("PILOTO %d DA ESCUDERIA %d: \n", p+1, e+1);
                printf("NOME: ");
                scanf("%s", torneio[t].equipes[e].pilots[p].nome);
                printf("IDADE: ");
                scanf("%d", torneio[t].equipes[e].pilots[p].idade);
                fflush(stdin);
                printf("\n");
            }
        }
    }
    for(t = 0; t < 2; t++){
        printf("INFORMACOES DO CAMPEONATO %d\n\n", t+1);
        printf("NOME: %s", torneio[t].nome);
        printf("\n");
        for(c = 0; c < 5; c++){
            printf("CIRCUITO %d\n\n", c+1);
            printf("NOME: %s\n", torneio[t].pistas[c].nome);
            printf("PAIS: %s\n", torneio[t].pistas[c].pais);
            printf("QUILOMETRAGEM: %f\n", torneio[t].pistas[c].km);
            printf("\n");
        }
        printf("\n");
        for(e = 0; e < 7; e++){
            printf("ESCUDERIA %d\n\n", e+1);
            printf("NOME: %s\n", torneio[t].equipes[e].nome);
            for(p = 0; p < 2; p++){
                printf("PILOTO %d DA ESCUDERIA %d: \n", p+1, e+1);
                printf("NOME: %s\n", torneio[t].equipes[e].pilots[p].nome);
                printf("IDADE: %d\n", torneio[t].equipes[e].pilots[p].idade);
                printf("\n");
            }
        }
    }
    for(e = 0; e < 7; e++){
        free(torneio[t].equipes[e].pilots);
    }
    for(t = 0; t < 2; t++){
        free(torneio[t].pistas),
        free(torneio[t].equipes);
    }
    free(torneio);
    return 0;
}
