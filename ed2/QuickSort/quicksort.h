//Gera aleatoriamente os elementos do vetor
void gerarVetor(int *v, int n);

//Mostra os elementos do vetor
void mostrarVetor(int *v, int n);

//Troca dois elementos de lugar no vetor
void troca(int *a, int *b);

//Calcula o pivo ideal para ordenar o vetor
int particiona(int *v, int inicio, int fim, int n);

//Ordena o vetor pelo metodo Quicksort
void quickSort(int *v, int inicio, int fim, int n);

//Le o tamanho, gera e ordena o vetor
void principal();
