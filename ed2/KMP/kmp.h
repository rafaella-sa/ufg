//Calcula o prefixo; m = longitude do padrao
int *computePrefixFunction(char *padrao, int m);

//Algoritmo Knuth-Morris-Pratt
//n = longitude do texto
void kmpMatcher(char *texto, int n, char *padrao, int m);

//Gerencia a comparacao de cadeias
void compara();
