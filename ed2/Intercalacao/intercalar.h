//define a estrutura 'Arquivo' que auxilia na gestao dos discos
typedef struct arquivo Arquivo;

//compara dois elementos de forma nao-decrescente
int comparaCrescente(const void *a, const void *b);

//grava elementos gerados aleatoriamente no arquivo de entrada
void gravarArquivo();

//gera as particoes do disco de forma ordenada
void gerarArquivosOrdenados();

//preenche o buffer com os elementos dos discos
void preencheBuffer(struct arquivo *arq, int K);

//procura o menor valor no buffer para salva-lo no arquivo
int buscaMenorValor(struct arquivo *arq, int K, int *menor);

//aplica o metodo Merge Sort nos discos
void mergeExterno();

//gerencia a execucao das outras funcoes
void menu();
