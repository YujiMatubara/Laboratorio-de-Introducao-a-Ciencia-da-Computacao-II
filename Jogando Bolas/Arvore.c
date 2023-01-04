#include <stdio.h>
#include <stdlib.h>

typedef struct no_ NO;
struct no_
{
	int valor;
	int trueorfalse;
	NO* filho1;
	NO* filho2;
};

NO* arvore_criar_profundidade(int profundidade, int contador)
{
	if (profundidade == 0)
	{
		return NULL;
	}
	
	NO* arvore = (NO*)malloc(sizeof(NO));
	arvore->valor = contador;
	arvore->trueorfalse = 0;
	arvore->filho1 = arvore_criar_profundidade(profundidade - 1, contador * 2);
	arvore->filho2 = arvore_criar_profundidade(profundidade - 1, (contador * 2) + 1);

	return arvore;
}

int resolve(NO* arvore)
{
	if (arvore->filho1 == NULL && arvore->filho2 == NULL)
	{
		return arvore->valor;
	}
	
	if (arvore->trueorfalse == 0)
	{
		arvore->trueorfalse = 1;
		return resolve(arvore->filho1);
	}
	else //arvore->trueorfalse == 1
	{
		arvore->trueorfalse = 0;
		return resolve(arvore->filho2);
	}
}

void arvore_printar(NO* arvore)
{
	if (arvore == NULL)
	{
		return;
	}
	
	printf("%d ", arvore->valor);
	arvore_printar(arvore->filho1);
	arvore_printar(arvore->filho2);
	return;
}
