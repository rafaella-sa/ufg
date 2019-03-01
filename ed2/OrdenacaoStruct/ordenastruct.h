//Definicao do TDA 'aluno'
struct aluno{
    int matricula, anoIngresso;
    char nome[100];
    char curso[100];
};
typedef struct aluno aluno;

//compara alunos pelo criterio ano de ingresso
int comparaAnoIngresso(aluno a, aluno b);

//compara alunos pelo criterio curso
int comparaCurso(aluno a, aluno b);

//compara alunos pelo criterio matricula
int comparaMatricula(aluno a, aluno b);

//compara alunos pelo criterio nome
int comparaNome(aluno a, aluno b);

//aplica criterio de comparacao escolhido pelo usuario
int comparaAlunos(aluno a, aluno b, int opcao);

//metodo utilizado para ordenacao dos dados
void shellSort (aluno data[], int arrSize, int opcao);

//le e armazena dados dos alunos a serem ordenados
aluno* geraVetorAlunos(int *quant);

//imprime informacoes dos alunos
void imprimirAlunos(aluno* alunos, int n);

//mostra as opcoes do menu
void opcoesMenu();

//execucao do menu
void menu();
