//Definicao da estrutura 'registro'
struct record{
    int id_number;
    char name[30];
    char adress[30];
    long int phone;
    int age;
    float salary;
};

//Imprime as informacoes de um determinado registro
void imprimir_registro(struct record rec);

//Grava informacao no arquivo
void gravar_arquivo();

//Recupera informacao no arquivo de acordo com uma chave dada
void buscar_arquivo();

//Descreve as opcoes do menu
void opcoes_menu();

//Mostra e gerencia as opcoes
void menu();
