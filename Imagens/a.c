#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorequaternaria.h"

int main(int argc, char const *argv[])
{
	int testes;
	scanf("%d", &testes);

	int j = 1;
	int k;
	char* linha = (char*)malloc(sizeof(char) * 1500);
	char* linha2 = (char*)malloc(sizeof(char) * 1500);
	for (int i = 0; i < testes; ++i)
	{
		k = 0;
		j = 1;
		scanf("%s", linha);
		NO* arvore;
		if (strlen(linha) == 1)
		{
			if (linha[0] == 'f')
			{
				arvore = arvore_criar_simples(1);
			}
			else
			{
				arvore = arvore_criar_simples(0);
			}
		}
		else
		{
			arvore = arvore_criar();
			arvore_montar(arvore, linha, &j, 0, strlen(linha));
		}

		j = 1;
		scanf("%s", linha2);
		NO* arvore2;
		if (strlen(linha2) == 1)
		{
			if (linha2[0] == 'f')
			{
				arvore2 = arvore_criar_simples(1);
			}
			else
			{
				arvore2 = arvore_criar_simples(0);
			}
		}
		else
		{
			arvore2 = arvore_criar();
			arvore_montar(arvore2, linha2, &j, 0, strlen(linha2));
		}

		NO* arvore3 = arvore_criar();
		arvore_interpola(arvore, arvore2, arvore3);
		
		int num = 0;
		arvore_nump(arvore3, &num, k);
		printf("%d %d pixels pretos.\n", i + 1, num);

		arvore_remove(arvore);
		arvore_remove(arvore2);
		arvore_remove(arvore3);
	}
	free(linha);
	free(linha2);
	return 0;
}