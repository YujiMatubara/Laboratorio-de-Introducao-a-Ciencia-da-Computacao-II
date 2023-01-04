#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO 999999999

typedef struct eficiencia_
{
	int c;
	int m;
}EFICIENCIA;

EFICIENCIA eficiencia[5];

void insertionsort(int *v, int n)
{
	eficiencia[0].c = 0;
	eficiencia[0].m = 0;
	int i = 1; 
	while (i < n)
	{
		int j = i - 1;
		int chave = v[i];
		while (1)
		{
			if (j < 0)
			{
				break;
			}
			eficiencia[0].c = eficiencia[0].c + 1;
			if (chave >= v[j])
			{
				break;
			}
			eficiencia[0].m = eficiencia[0].m + 1;
			v[j+1] = v[j];
			j--;
		}
		i++;
		v[j + 1] = chave;
		eficiencia[0].m = eficiencia[0].m + 1;
	}
	return;
}

void mergesort (int *v, int ini, int fim)
{	
	
	if (fim <= ini)
	{
		return;
	}

	int centro = (int) ((fim + ini)/2.0);

	mergesort(v, ini, centro);
	mergesort(v, centro + 1, fim);

	int* aux = (int*) malloc(sizeof(int) * (fim - ini + 1));
	int i = ini;
	int j = centro + 1;
 	int k = 0;

	while (i <= centro && j <= fim)
	{
		eficiencia[1].c++;
		if (v[i] <= v[j])
		{
			aux[k] = v[i]; 
			i++;
		} 
		else
		{
			aux[k] = v[j];
			j++;
		}
		k++;
	}


	while (i <= centro)
	{
		aux[k] = v[i];
		i++;
		k++;
	}	

	while (j <= fim)
	{
		aux[k] = v[j];
		j++;
		k++;
	}	

	for (i = ini; k = 0, i <= fim; i++, k++)
	{
		eficiencia[1].m++;
		v[i] = aux[k];
	}
	free(aux);
}

void quicksort (int *v, int ini, int fim)
{
	if (ini >= fim)
	{
		return;
	}

	int p = (int)((ini + fim) / 2);

	eficiencia[2].m++;
	int tmp = v[p];
	v[p] = v[ini];
	v[ini] = tmp; 
	p = ini;

	int i = ini + 1;
	int j = fim;

	while (i < j)
	{
		while (1)
		{
			if (i > fim)
			{
				break;
			}
			eficiencia[2].c++;
			if (v[i] > v[p])
			{
				break;
			}
			i++;
		}
		while (1)
		{
			if (j <= ini)
			{
				break;
			}
			eficiencia[2].c++;
			if (v[j] <= v[p])
			{
				break;
			}
			j--;
		}

		if (j > i)
		{
			eficiencia[2].m++;
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
	p = j;
	eficiencia[2].m++;
	tmp = v[p];
	v[p] = v[ini];
	v[ini] = tmp; 

	quicksort(v, ini, p - 1);
	quicksort(v, p + 1, fim);
}

void bubblesort(int *v, int n)
{
	eficiencia[3].c = 0;
	eficiencia[3].m = 0;
	int i = 0;
	int j = 0;
	int aux;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			eficiencia[3].c++;
			if (v[i] > v[j])
			{
				eficiencia[3].m++;
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;	
			}
		}
	}
}

void criaheap(int *vet, int i, int f)
{
	//essa funcao arruma so 1 elemento
	int aux = vet[i];
	int j = (i * 2) + 1;

	while (j <= f)
	{
		if (j < f)
		{
			if (vet[j] < vet[j + 1])
			{
				eficiencia[4].c++;
				j = j + 1;
			}
		}
		if (aux < vet[j])
		{
			eficiencia[4].c++;
			eficiencia[4].m++;
			vet[i] = vet[j];
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			j = f + 1;
		}
	}
	vet[i] = aux;
}

void heapsort(int *vet, int N)
{
	eficiencia[4].c = 0;
	eficiencia[4].m = 0;

	int aux;
	for (int i = (N - 1) / 2; i >= 0; --i)
	{
		criaheap(vet, i, N - 1);
	}

	for (int i = N - 1; i >= 1; --i)
	{
		eficiencia[4].m++;
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		criaheap(vet, 0, i - 1);
	}
}

int main(int argc, char const *argv[])
{
	unsigned int o;
	unsigned int n;
	scanf("%d %d", &o, &n);

	int vetor[n];
	int flaginsertionsort = 0;
	int flagbubblesort = 0;
	int flagmergesort = 0;
	int flagheapsort = 0;
	int flagquicksort = 0;
	char nomealgoritmo[13];

	for (int i = 0; i < 5; ++i)
	{
		eficiencia[i].c = 999999999;
		eficiencia[i].m = 999999999;
	}

	for (int i = 0; i < o; ++i)
	{
		scanf("%s", nomealgoritmo);

		if (strcmp(nomealgoritmo, "INSERTIONSORT") == 0)
		{
			flaginsertionsort = 1;
		}
		else if(strcmp(nomealgoritmo, "MERGESORT") == 0)
		{
			flagmergesort = 1;
			eficiencia[1].c = 0;
			eficiencia[1].m = 0;
		}
		else if(strcmp(nomealgoritmo, "QUICKSORT") == 0)
		{
			flagquicksort = 1;
			eficiencia[2].c = 0;
			eficiencia[2].m = 0;
		}
		else if(strcmp(nomealgoritmo, "BUBBLESORT") == 0)
		{
			flagbubblesort = 1;
		}
		else if(strcmp(nomealgoritmo, "HEAPSORT") == 0)
		{
			flagheapsort = 1;
			eficiencia[4].c = 0;
			eficiencia[4].m = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &vetor[i]);
	}

	int vetoraux[n];
	if (flaginsertionsort)
	{
		for (int i = 0; i < n; ++i)
		{
			vetoraux[i] = vetor[i];
		}
		insertionsort(vetoraux, n);
	}
	else
	{
		eficiencia[0].c = ERRO;
		eficiencia[0].m = ERRO;
	}
	if (flagmergesort)
	{
		for (int i = 0; i < n; ++i)
		{
			vetoraux[i] = vetor[i];
		}
		mergesort(vetoraux, 0 , n);
	}
	else
	{
		eficiencia[1].c = ERRO;
		eficiencia[1].m = ERRO;
	}
	if (flagquicksort)
	{
		for (int i = 0; i < n; ++i)
		{
			vetoraux[i] = vetor[i];
		}
		quicksort(vetoraux, 0 , n);
	}
	else
	{
		eficiencia[2].c = ERRO;
		eficiencia[2].m = ERRO;
	}
	if (flagbubblesort)
	{
		for (int i = 0; i < n; ++i)
		{
			vetoraux[i] = vetor[i];
		}
		bubblesort(vetoraux, n);
	}
	else
	{
		eficiencia[3].c = ERRO;
		eficiencia[3].m = ERRO;
	}
	if (flagheapsort)
	{
		for (int i = 0; i < n; ++i)
		{
			vetoraux[i] = vetor[i];
		}
		heapsort(vetoraux, n);
	}
	else
	{
		eficiencia[4].c = ERRO;
		eficiencia[4].m = ERRO;
	}
	//printf("insertion: c-%d m-%d\n", eficiencia[0].c, eficiencia[0].m);
	//printf("merge: c-%d m-%d\n", eficiencia[1].c, eficiencia[1].m);
	//printf("quick: c-%d m-%d\n", eficiencia[2].c, eficiencia[2].m);
	//printf("bubble: c-%d m-%d\n", eficiencia[3].c, eficiencia[3].m);
	//printf("heap: c-%d m-%d\n", eficiencia[4].c, eficiencia[4].m);

	int menorc;
	int maiorc;
	int menorm;
	int maiorm;
	if (eficiencia[0].c != ERRO)
	{
		menorc = 0;
		maiorc = 0;
	}
	else
	{
		menorc = 1;
		maiorc = 1;
	}
	if (eficiencia[0].m != ERRO)
	{
		menorm = 0;
		maiorm = 0;
	}
	else
	{
		menorm = 1;
		maiorm = 1;
	}
	for (int i = 1; i < 5; ++i)
	{
		if ((eficiencia[menorc].c > eficiencia[i].c) && eficiencia[i].c != ERRO)
		{
			menorc = i;
		}
		if ((eficiencia[maiorc].c < eficiencia[i].c) && eficiencia[i].c != ERRO)
		{
			maiorc = i;
		}
		if ((eficiencia[menorm].m > eficiencia[i].m) && eficiencia[i].m != ERRO)
		{
			menorm = i;
		}
		if ((eficiencia[maiorm].m < eficiencia[i].m) && eficiencia[i].m != ERRO)
		{
			maiorm = i;
		}
	}

	if (menorc == 0)
	{
		printf("Menor C: INSERTIONSORT\n");
	}
	else if (menorc == 1)
	{
		printf("Menor C: MERGESORT\n");
	}
	else if (menorc == 2)
	{
		printf("Menor C: QUICKSORT\n");
	}
	else if (menorc == 3)
	{
		printf("Menor C: BUBBLESORT\n");
	}
	else if (menorc == 4)
	{
		printf("Menor C: HEAPSORT\n");
	}
	//------------------------------------------------------------
	if (maiorc == 0)
	{
		printf("Maior C: INSERTIONSORT\n");
	}
	else if (maiorc == 1)
	{
		printf("Maior C: MERGESORT\n");
	}
	else if (maiorc == 2)
	{
		printf("Maior C: QUICKSORT\n");
	}
	else if (maiorc == 3)
	{
		printf("Maior C: BUBBLESORT\n");
	}
	else if (maiorc == 4)
	{
		printf("Maior C: HEAPSORT\n");
	}
	//------------------------------------------------------------
	if (menorm == 0)
	{
		printf("Menor M: INSERTIONSORT\n");
	}
	else if (menorm == 1)
	{
		printf("Menor M: MERGESORT\n");
	}
	else if (menorm == 2)
	{
		printf("Menor M: QUICKSORT\n");
	}
	else if (menorm == 3)
	{
		printf("Menor M: BUBBLESORT\n");
	}
	else if (menorm == 4)
	{
		printf("Menor M: HEAPSORT\n");
	}
	//------------------------------------------------------------
	if (maiorm == 0)
	{
		printf("Maior M: INSERTIONSORT\n");
	}
	else if (maiorm == 1)
	{
		printf("Maior M: MERGESORT\n");
	}
	else if (maiorm == 2)
	{
		printf("Maior M: QUICKSORT\n");
	}
	else if (maiorm == 3)
	{
		printf("Maior M: BUBBLESORT\n");
	}
	else if (maiorm == 4)
	{
		printf("Maior M: HEAPSORT\n");
	}
	return 0;
}