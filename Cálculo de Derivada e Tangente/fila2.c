#include <stdio.h>
#include <stdlib.h>

typedef struct funcao
{
	long long int coeficiente;
	int expoente;
}FUNCAO;

typedef struct fila
{
	FUNCAO vetor[1000];
	int tamanho;
}FILA;

void shifta_vetores(FILA *fila, int tamanho)
{
	for (int i = 1; i < tamanho; ++i)
	{
		fila->vetor[i - 1] = fila->vetor[i];
	}
}

FILA *FILA_cria_fila()
{
	FILA *filanova = NULL;
	filanova = (FILA *)malloc(sizeof(FILA));

	filanova->tamanho = 0;
	for (int i = 0; i < 1000; ++i)
	{
		filanova->vetor[i].coeficiente = 0;
	}

	return (filanova);
}

void FILA_adiciona_elemento(FILA *fila, int coeficientenovo, int expoentenovo)
{
	fila->vetor[fila->tamanho].coeficiente = coeficientenovo;
	fila->vetor[fila->tamanho].expoente = expoentenovo;
	fila->tamanho++;
}

void FILA_remove_elemento(FILA *fila, long long int *coeficiente, int *expoente)
{
	*coeficiente = fila->vetor[0].coeficiente;
	*expoente = fila->vetor[0].expoente;
	shifta_vetores(fila, fila->tamanho);
	fila->tamanho--;
}

int FILA_pilha_vazia(FILA *fila)
{
	if (fila->tamanho == 0)
	{
		return 1;
	}
	return 0;
}