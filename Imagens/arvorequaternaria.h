#ifndef arvorequaternaria_h
#define arvorequaternaria_h

typedef struct no_ NO;

NO* no_criar();

NO* arvore_criar();

NO* arvore_criar_simples(int i);

void arvore_montar(NO* raiz, char* linha, int* i, int contadorfilho, int lenlinha);

void arvore_interpola(NO* raiz1, NO* raiz2, NO* raiz3);

void arvore_print(NO* raiz);

void arvore_nump(NO* raiz, int *num, int profundidade);

void arvore_remove(NO* raiz);

#endif