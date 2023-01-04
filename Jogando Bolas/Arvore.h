#ifndef ARVORE_H
#define ARVORE_H

typedef struct no_ NO;

NO* arvore_criar_profundidade(int profundidade, int contador);
int resolve(NO* arvore);
void arvore_printar(NO* arvore);

#endif
