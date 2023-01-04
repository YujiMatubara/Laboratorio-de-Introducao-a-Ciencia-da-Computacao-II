#include <stdio.h>
#include <stdlib.h>
#include "arvorequaternaria.h"
#include <math.h>

struct no_
{
	int pb;
	NO* filho1;
	NO* filho2;
	NO* filho3;
	NO* filho4;
};

NO* no_criar()
{
	NO* no = (NO*)malloc(sizeof(NO));
	no->pb = -1;
	no->filho1 = NULL;
	no->filho2 = NULL;
	no->filho3 = NULL;
	no->filho4 = NULL;

	return no;
}

NO* arvore_criar()
{
	NO* no = (NO*)malloc(sizeof(NO));
	no->pb = 3;
	no->filho1 = NULL;
	no->filho2 = NULL;
	no->filho3 = NULL;
	no->filho4 = NULL;

	return no;
}

NO* arvore_criar_simples(int i)
{
	NO* no = (NO*)malloc(sizeof(NO));
	if (i == 0)
	{
		no->pb = 0;
	}
	else if (i == 1)
	{
		no->pb = 1;
	}
	no->filho1 = NULL;
	no->filho2 = NULL;
	no->filho3 = NULL;
	no->filho4 = NULL;

	return no;
}

void arvore_montar(NO* raiz, char* linha, int* i, int contadorfilho, int lenlinha)
{
	if ((*i) > lenlinha)
	{
		return;
	}
	if (raiz->filho1 == NULL)
	{
		contadorfilho = 0;
	}
	else if (raiz->filho2 == NULL)
	{
		contadorfilho = 1;
	}
	else if (raiz->filho3 == NULL)
	{
		contadorfilho = 2;
	}
	else if (raiz->filho4 == NULL)
	{
		contadorfilho = 3;
	}
	else
	{
		contadorfilho = 0;
		return;
	}


	if (linha[*i] == 'p')
	{
		NO* novo = no_criar();
		if (contadorfilho == 0)
		{
			raiz->filho1 = novo;
		}
		else if (contadorfilho == 1)
		{
			raiz->filho2 = novo;
		}
		else if (contadorfilho == 2)
		{
			raiz->filho3 = novo;
		}
		else
		{
			raiz->filho4 = novo;
		}
		novo->pb = 3;
		(*i)++;
		contadorfilho = 0;
		arvore_montar(novo, linha, i, contadorfilho, lenlinha);
		arvore_montar(raiz, linha, i, contadorfilho, lenlinha);
	}
	else if (linha[*i] == 'e')
	{
		if (contadorfilho == 0)
		{
			raiz->filho1 = no_criar();
			raiz->filho1->pb = 0;
		}
		else if (contadorfilho == 1)
		{
			raiz->filho2 = no_criar();
			raiz->filho2->pb = 0;
		}
		else if (contadorfilho == 2)
		{
			raiz->filho3 = no_criar();
			raiz->filho3->pb = 0;
		}
		else
		{
			raiz->filho4 = no_criar();
			raiz->filho4->pb = 0;
		}
		(*i)++;
		contadorfilho++;
		arvore_montar(raiz, linha, i, contadorfilho, lenlinha);
	}
	else if (linha[*i] = 'f')
	{
		if (contadorfilho == 0)
		{
			raiz->filho1 = no_criar();
			raiz->filho1->pb = 1;
		}
		else if (contadorfilho == 1)
		{
			raiz->filho2 = no_criar();
			raiz->filho2->pb = 1;
		}
		else if (contadorfilho == 2)
		{
			raiz->filho3 = no_criar();
			raiz->filho3->pb = 1;
		}
		else
		{
			raiz->filho4 = no_criar();
			raiz->filho4->pb = 1;
		}
		(*i)++;
		contadorfilho++;
		arvore_montar(raiz, linha, i, contadorfilho, lenlinha);
	}
	
}

void arvore_interpola(NO* raiz1, NO* raiz2, NO* raiz3)
{
	if (raiz1 == NULL && raiz2 == NULL)
	{
		return;
	}
	else if (raiz1 != NULL && raiz2 == NULL)
	{

		if (raiz1->pb == 0)
		{
			raiz3->pb = 0;

		}
		else if (raiz1->pb == 1)
		{

			raiz3->pb = 1;
		}
		else if (raiz1->pb == 3)
		{
			NO* novo1 = no_criar();
			raiz3->filho1 = novo1;
			NO* novo2 = no_criar();
			raiz3->filho2 = novo2;
			NO* novo3 = no_criar();
			raiz3->filho3 = novo3;
			NO* novo4 = no_criar();
			raiz3->filho4 = novo4;
			raiz3->pb = 3;
		}
		
		arvore_interpola(raiz1->filho1, NULL, raiz3->filho1);
		arvore_interpola(raiz1->filho2, NULL, raiz3->filho2);
		arvore_interpola(raiz1->filho3, NULL, raiz3->filho3);
		arvore_interpola(raiz1->filho4, NULL, raiz3->filho4);
	}
	else if (raiz1 == NULL && raiz2 != NULL)
	{

		if (raiz2->pb == 0)
		{

			raiz3->pb = 0;
		}
		else if (raiz2->pb == 1)
		{

			raiz3->pb = 1;
		}
		else if (raiz2->pb == 3)
		{
			NO* novo1 = no_criar();
			raiz3->filho1 = novo1;
			NO* novo2 = no_criar();
			raiz3->filho2 = novo2;
			NO* novo3 = no_criar();
			raiz3->filho3 = novo3;
			NO* novo4 = no_criar();
			raiz3->filho4 = novo4;
			raiz3->pb = 3;
		}
		arvore_interpola(NULL, raiz2->filho1, raiz3->filho1);
		arvore_interpola(NULL, raiz2->filho2, raiz3->filho2);
		arvore_interpola(NULL, raiz2->filho3, raiz3->filho3);
		arvore_interpola(NULL, raiz2->filho4, raiz3->filho4);
	}
	else if (raiz1 != NULL && raiz2 != NULL)
	{
		if (raiz1->pb == 0 && raiz2->pb == 0)
		{
			raiz3->pb = 0;
		}
		else if (raiz1->pb == 1 || raiz2->pb == 1)
		{
			raiz3->pb = 1;
			return;
		}
		else if (raiz1->pb == 3 || raiz2->pb == 3)
		{
			NO* novo1 = no_criar();
			raiz3->filho1 = novo1;
			NO* novo2 = no_criar();
			raiz3->filho2 = novo2;
			NO* novo3 = no_criar();
			raiz3->filho3 = novo3;
			NO* novo4 = no_criar();
			raiz3->filho4 = novo4;
			raiz3->pb = 3;
		}
		arvore_interpola(raiz1->filho1, raiz2->filho1, raiz3->filho1);
		arvore_interpola(raiz1->filho2, raiz2->filho2, raiz3->filho2);
		arvore_interpola(raiz1->filho3, raiz2->filho3, raiz3->filho3);
		arvore_interpola(raiz1->filho4, raiz2->filho4, raiz3->filho4);
	}
}

void arvore_nump(NO* raiz, int *num, int profundidade)
{
	if (raiz == NULL)
	{
		return;
	}

	if (raiz->pb == 1)
	{
		*num = *num + (((32/pow(2,(profundidade))) * (32/pow(2,(profundidade)))));
	}
	profundidade++;
	arvore_nump(raiz->filho1, num, profundidade);
	arvore_nump(raiz->filho2, num, profundidade);
	arvore_nump(raiz->filho3, num, profundidade);
	arvore_nump(raiz->filho4, num, profundidade);
}

void arvore_remove(NO* raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	arvore_remove(raiz->filho1);
	arvore_remove(raiz->filho2);
	arvore_remove(raiz->filho3);
	arvore_remove(raiz->filho4);
	raiz->pb = 0;
	raiz->filho1 = NULL;
	raiz->filho2 = NULL;
	raiz->filho3 = NULL;
	raiz->filho4 = NULL;
	free(raiz);
}