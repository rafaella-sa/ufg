//ordena o vetor atraves do metodo Shell Sort
void shellSort (int data[], int arrSize);

//auxilia o metodo Heap Sort, gerando o heap
void criaHeap(int *v, int i, int f);

//ordena o vetor atraves do metodo Heap Sort
void heapSort(int *v, int n);

//auxilia o metodo Merge Sort, fazendo a mescla de
//elementos
void mergeS(int *v, int inicio, int meio, int fim);

//ordena o vetor atraves do metodo Merge Sort
void mergeSort(int *v, int inicio, int fim);

//auxilia o metodo Quick Sort, ao gerar o elemento
//pivo
int particiona(int *v, int inicio, int fim);

//ordena o vetor atraves do metodo Quick Sort
void quickSort(int *v, int inicio, int fim);

//gera um vetor auxiliar com os tamanhos dos vetores
//aleatorios, de 10 a 300000
int* tamanhoVetores();

//gera um vetor de inteiros aleatorios
void gerarVetor(int *v, int n);

//grava em um arquivo os vetores a serem ordenados
void gravarVetores();

//ordena os vetores lidos do arquivo utilizando
//os quatro metodos
void ordenarVetores();

//metodo a partir do qual se executa todo o codigo
void principal();
