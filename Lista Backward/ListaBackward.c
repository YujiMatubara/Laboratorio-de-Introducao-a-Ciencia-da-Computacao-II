#include <stdio.h>
#include <stdlib.h>

typedef struct no_ NO;
struct no_
{
	unsigned int n;
	unsigned int t;
	NO *proximo;
	NO *anterior;
};

typedef struct lista_
{
	NO *inicio;
	NO *fim;
	unsigned int tamanho;
}LISTA;

LISTA *cria_lista()
{
	LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tamanho = 0;
	return lista;
}

void insere_elemento(LISTA *lista, unsigned int auxn,unsigned int auxt, unsigned int contador)
{
	if (lista->inicio == NULL && lista->fim == NULL)
	{
		NO *no = (NO *)malloc(sizeof(NO));
		lista->inicio = no;
		lista->fim = no;
		lista->tamanho++;
		lista->fim->n = auxn;
		lista->fim->t = contador;

		NO *aux = lista->inicio;
		if (auxt == 0)
		{
			lista->inicio->anterior = NULL;
		}
		else
		{
			if (lista->tamanho - auxt - 1 >= 0)
			{
				for (int i = 0; i < lista->tamanho - auxt - 1; ++i)
				{
					aux = aux->proximo;
				}
				lista->fim->anterior = aux;
			}
		}
		lista->fim->proximo = NULL;
	}
	else
	{
		NO *no = (NO *)malloc(sizeof(NO));
		lista->tamanho++;
		lista->fim->proximo = no;
		lista->fim = no;
		lista->fim->n = auxn;
		lista->fim->t = contador;
		
		NO *aux = lista->inicio;
		if (auxt == 0)
		{
			lista->inicio->anterior = NULL;
		}
		else
		{
			if ((int)(lista->tamanho - auxt - 1) >= 0)
			{
				for (int i = 0; i < lista->tamanho - auxt - 1; ++i)
				{
					aux = aux->proximo;
				}
				lista->fim->anterior = aux;
			}
		}
		lista->fim->proximo = NULL;
	}
}

void remove_elemento(LISTA *lista, unsigned int auxn)
{
	if (lista == NULL)
	{
		return;
	}
	int flag = 0;
	NO *remover = lista->inicio;
	NO *anteriorremover = NULL;
	NO *aux;
	for (int i = 0; i < lista->tamanho; ++i)
	{
		if (remover->n == auxn)
		{
			flag = 1;
			if (remover != lista->inicio)
			{
				anteriorremover->proximo = remover->proximo;
				remover->anterior = NULL;
				aux = lista->inicio;
				for (int i = 0; i < lista->tamanho - 1; ++i)
				{
					if (aux->anterior == remover)
					{
						aux->anterior = NULL;
					}
					aux = aux->proximo;
				}
			}
			else if(remover == lista->inicio)
			{
				remover->anterior = NULL;
				aux = lista->inicio;
				for (int i = 0; i < lista->tamanho - 1; ++i)
				{
					if (aux->anterior == remover)
					{
						aux->anterior = NULL;
					}
					aux = aux->proximo;
				}
				lista->inicio = remover->proximo;
			}
		}
		anteriorremover = remover;
		remover = remover->proximo;
	}
	if (flag)
	{
		lista->tamanho--;
	}
	return;
}

int main(int argc, char const *argv[])
{
	char operacao;
	unsigned int auxn;
	unsigned int auxt;
	unsigned int contador = -1;
	LISTA *lista = cria_lista();

	while(scanf(" %c", &operacao) != EOF)
	{
		if (operacao == 'i')
		{
			contador++;
			scanf("%d %d", &auxn, &auxt);
			insere_elemento(lista, auxn, auxt, contador);
		}
		else if (operacao == 'r')
		{
			contador++;
			scanf("%d", &auxn);
			remove_elemento(lista, auxn);
		}
		else
		{
			break;
		}
	}

	NO *aux = lista->inicio;
	unsigned int contador2;
	for (int i = 0; i < lista->tamanho; ++i)
	{
		printf("[%d,%d", aux->n, aux->t);
		if (aux->anterior != NULL)
		{
			contador2 = 0;
			NO *contadort = lista->inicio;
			for (int i = 0; i < lista->tamanho; ++i)
			{
				if (contadort == aux->anterior && aux->anterior != NULL)
				{
					printf(",%d", contador2);
				}
				contadort = contadort->proximo;
				contador2++;
			}
		}
		printf("] ");
		aux = aux->proximo;
	}
	if (lista->tamanho == 0)
	{
		printf("-1");
	}
	printf("\n");
	return 0;
}