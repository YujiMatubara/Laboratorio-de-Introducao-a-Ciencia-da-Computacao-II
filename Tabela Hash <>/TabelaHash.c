#include <stdio.h>
#include <stdlib.h>

void inserir(int** tabela, int i)
{
	char palavra[50];
	scanf("%s", palavra);

	int j = 0;
	int aux;
	int hash;
	while (palavra[j] != '\0')
	{
		aux = palavra[j] - 'a';
		hash = ((aux * aux) + j) % 397;
		while (tabela[i][hash] != -1)
		{
			aux += 3;
			hash = ((aux * aux) + j) % 397;
		}
		tabela[i][hash] = 1;
		j++;
	}
	return;
}

void buscar(int** tabela, int k)
{
	char palavra[50];
	scanf("%s", palavra);

	int j = 0;
	int aux;
	int hash;
	int flag = 1;
	int vetor[397];
	for (int i = 0; i < 397; ++i)
	{
		vetor[i] = -1;
	}
	while (palavra[j] != '\0')
	{
		aux = palavra[j] - 'a';
		hash = ((aux * aux) + j) % 397;
		while (vetor[hash] != -1)
		{
			aux += 3;
			hash = ((aux * aux) + j) % 397;
		}
		vetor[hash] = 1;
		j++;
	}
	for (int p = 0; p < k; ++p)
	{
		flag = 1;
		for (int i = 0; i < 397; ++i)
		{
			if (vetor[i] != tabela[p][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

	if (flag == 1)
	{
		printf("encontrado\n");
	}
	else
	{
		printf("nao encontrado\n");
	}
	return;
}

void remover(int** tabela, int k)
{
	char palavra[50];
	scanf("%s", palavra);

	int j = 0;
	int aux;
	int hash;
	int flag = 1;
	int vetor[397];
	for (int i = 0; i < 397; ++i)
	{
		vetor[i] = -1;
	}
	while (palavra[j] != '\0')
	{
		aux = palavra[j] - 'a';
		hash = ((aux * aux) + j) % 397;
		while (vetor[hash] != -1)
		{
			aux += 3;
			hash = ((aux * aux) + j) % 397;
		}
		vetor[hash] = 1;
		j++;
	}

	int q;
	int p;
	for (p = 0; p < 2000; ++p)
	{
		flag = 1;
		for (q = 0; q < 397; ++q)
		{
			if (vetor[q] != tabela[p][q])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

	if (flag == 1)
	{
		for (int i = 0; i < 397; ++i)
		{
			tabela[p][i] = -1;
		}
	}

	return;
}

int main(int argc, char const *argv[])
{
	int** tabela = (int **)malloc(sizeof(int*) * 2000);
	for (int i = 0; i < 2000; ++i)
	{
		tabela[i] = (int*)malloc(sizeof(int) * 397);
		for (int j = 0; j < 397; ++j)
		{
			tabela[i][j] = -1;
		}
	}

	int i = 0;
	char c;
	while(1)
	{
		scanf(" %c", &c);

		if (c == 'f')
		{
			break;
		}
		else if (c == 'i')
		{
			inserir(tabela, i);
			i++;
		}
		else if (c == 'b')
		{
			buscar(tabela, i);
		}
		else
		{
			remover(tabela, i);
		}
	}
	for (int i = 0; i < 2000; ++i)
	{
		free(tabela[i]);
	}
	free(tabela);
	return 0;
}