#include <stdio.h>
#include <stdlib.h>

typedef struct fila_
{
	int *vetor;
	int tamanho;
}FILA;

FILA* cria_fila()
{
	FILA *fila = (FILA *)malloc(sizeof(FILA));
	fila->vetor = NULL;
	fila->tamanho = 0;
	return fila;
}

void fila_insere(FILA* fila, int elemento)
{	
	if (fila == NULL)
	{
		fila->tamanho = 0;
	}
	if (fila->tamanho == 0)
	{
		fila->vetor = (int *)malloc(sizeof(int));
		fila->vetor[0] = elemento;
	}
	else
	{
		fila->vetor = (int *)realloc(fila->vetor, sizeof(int) * (fila->tamanho + 1));
		fila->vetor[fila->tamanho] = elemento;
	}
	fila->tamanho++;
}

int fila_vazia(FILA *fila)
{
	if (fila->tamanho == 0)
	{
		return 1;
	}
	return 0;
}
void fila_remove_ultimo(FILA *fila)
{
	if (fila == NULL || fila_vazia(fila))
	{
		return;
	}
	fila->vetor[fila->tamanho] = 0;
	fila->vetor = (int *)realloc(fila->vetor, sizeof(int) * (fila->tamanho));
	fila->tamanho--;
}

void fila_remove_superior(FILA *fila)
{
	if (fila == NULL || fila_vazia(fila))
	{
		return;
	}
	printf("%d ", fila->vetor[0]);
	for (int i = 1; i < fila->tamanho; ++i)
	{
		fila->vetor[i - 1] = fila->vetor [i];
	}
	fila->tamanho--;
	fila->vetor = (int *)realloc(fila->vetor, sizeof(int) * (fila->tamanho));
}

void fila_coloca_primeiro_elemento_aofinal(FILA *fila)
{	
	if (fila == NULL || fila_vazia(fila))
	{
		return;
	}
	int aux = fila->vetor[0];
	for (int i = 1; i < fila->tamanho; ++i)
	{
		fila->vetor[i - 1] = fila->vetor[i];
	}
	fila->vetor[fila->tamanho - 1] = aux;
}

int main(int argc, char const *argv[])
{
	int operacoes;
	scanf("%d", &operacoes);

	int aux;
	for (int i = 0; i < operacoes; ++i)
	{
		FILA *fila = cria_fila();
		aux = 1;
		while (aux != 0)
		{
			scanf("%d", &aux);
			if (aux != 0)
			{
				fila_insere(fila, aux);
			}
		}
		//fila_remove_ultimo(fila);

		int flag = 0;
		printf("Cartas jogadas: ");
		while (fila->tamanho != 1)
		{
			if (flag == 0)
			{
				fila_remove_superior(fila);
				flag = 1;
			}
			else
			{
				fila_coloca_primeiro_elemento_aofinal(fila);
				flag = 0;
			}
			/*
			printf("\nvetor: ");
			for (int i = 0; i < fila->tamanho; ++i)
			{
				printf("%d ", fila->vetor[i]);
			}
			printf("\n");
			*/
		}
		printf("\n");
		printf("Carta restante: %d\n", fila->vetor[0]);
		fila->tamanho = 0;
		free(fila->vetor);
		free(fila);
	}
	return 0;
}