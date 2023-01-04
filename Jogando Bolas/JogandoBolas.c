#include <stdio.h>
#include <stdlib.h>

#include "Arvore.h"

int main()
{
	int d;
	int i;
	int resposta;
	
	scanf("%d %d", &d, &i);
	NO* arvore;
	arvore = arvore_criar_profundidade(d, 1);
	
	int iterator;
	for (iterator = 0; iterator < i; iterator++)
	{
		resposta = resolve(arvore);
	}
	printf("%d\n", resposta);
	return 0;
}
