struct lista{
	int dado;
	struct lista *ant;
	struct lista *prox;
};

typedef struct lista Lista;

//Inicializacao da lista
Lista* inicializa();

//Calcula a quantidade de elementos da lista
int tamanhoLista(Lista* li);

//Insere elemento no inicio da lista
Lista* insereInicio(Lista* l, int d);

//Insere elemento no fim da lista
Lista* insereFim(Lista* l, int d);

//Remove elemento do inicio da lista
Lista* removeInicio (Lista *l);

//Remove elemento do fim da lista
Lista* removeFim(Lista *l);

//Remove um elemento determinado da lista
Lista* removeValor(Lista *l, int d);

//Imprime o conteudo da lista
void imprime(Lista *li);

//Procura o ponteiro para o elemento a ser selecionado
Lista* ponteiroElem(Lista* inicio, int pos);

//Le um valor inteiro
int leitura();

//Ordena a lista pelo metodo de insercao
void insertionSort(Lista *li);

//Descreve as opcoes disponiveis no menu
void opcoesMenu();

//Mostra o menu de opcoes
void menu();


