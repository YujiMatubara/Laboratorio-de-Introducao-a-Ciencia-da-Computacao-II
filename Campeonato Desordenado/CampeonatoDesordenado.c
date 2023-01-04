#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item_
{
	unsigned int numero;
	char nome[50];
	int identificador;
}ITEM;

typedef struct lista_
{
	ITEM item[1000];
	int fim;
}LISTA;

int numeromerge;

int comparacao(char *palavra1, char *palavra2)
{
	int i = 0;
	while(palavra1[i] != '\0' && palavra2[i] != '\0')
	{
		if (palavra1[i] < palavra2[i])
		{
			return -1;
		}
		else if(palavra1[i] > palavra2[i])
		{
			return 1;
		}
		i++;
	}
	while(palavra1[i] != '\0')
	{
		if ((palavra1[i] >= 0x41 && palavra1[i] <= 0x5A) || (palavra1[i] >= 0x61 && palavra1[i] <= 0x7A))
		{
			return 1;
		}
		i++;
	}
	while(palavra2[i] != '\0')
	{
		if ((palavra2[i] >= 0x41 && palavra2[i] <= 0x5A) || (palavra2[i] >= 0x61 && palavra2[i] <= 0x7A))
		{
			return -1;
		}
		i++;
	}
	return 0;
}
void mergesort2 (ITEM* v, int ini, int fim)
{

	if (fim <= ini) return; // caso base (vetor de 1 elemento)

	int centro = (int) ((fim+ini-1)/2.0);

	// 1 - passo recursivo (divisao)
	mergesort2(v, ini, centro);   // divisao lista 1 (primeira metade)
	mergesort2(v, centro+1, fim); // divisao lista 2 (segunda metade)

	// 2 - intercalacao, combinando solucoes parciais (conquista)

	// tamanho do vetor auxiliar:
	// 0, 1, 2, 3, 4, 5, 6, 7
	// 0, 1   aux -> tam = 2     1-0+1 = 2
	// 2, 3   aux -> tam = 2     3-2+1 = 2
	// 4, 5, 6, 7   aux -> 4     7-4+1 = 4

	// vetor auxiliar para copiar a intercalacao
	ITEM* aux = (ITEM*) malloc(sizeof(ITEM) * (fim-ini+1) );
	
	int i = ini;	  // indice da lista 1 (ini ate centro)
	int j = centro+1; // indice da lista 2 (centro+1 ate fim)
 	int k = 0;	  // indice do vetor auxiliar (0 ate fim-ini)

 	if(numeromerge != 0)
 	{
		// comparar elementos das duas listas
		while (i <= centro && j <= fim) {
			if (comparacao(v[i].nome, v[j].nome)<= 0) {
				aux[k] = v[i]; 
				i++; // proximo elemento da lista 1
			} 
			else {
				aux[k] = v[j];
				j++; // proximo elemento da lista 2
			}
			k++; // proximo elemento do aux
		}

		// copia os restantes da l1
		while (i <= centro) {
			aux[k] = v[i];
			i++; k++;
		}	
		// copia os restantes da l2
		while (j <= fim) {
			aux[k] = v[j];
			j++; k++;
		}	

		// copia aux para a posicao correta do vetor original	
		// abaixo 3 formas de fazer isso
		/*
		for (k = 0; k <= fim-ini; k++) {
			v[k+ini] = aux[k];
		}

		for (i = ini; i <= fim; i++) {
			v[i] = aux[i-ini];
		}
		*/

		for (i = ini, k = 0; i <= fim; i++, k++) {
			v[i] = aux[k];
		}
		numeromerge--;
		free(aux); // libera vetor auxiliar
 	}
}
void mergesort1 (ITEM* v, int ini, int fim)
{

	if (fim <= ini) return; // caso base (vetor de 1 elemento)

	int centro = (int) ((fim+ini-1)/2.0);

	// 1 - passo recursivo (divisao)
	mergesort1(v, ini, centro);   // divisao lista 1 (primeira metade)
	mergesort1(v, centro+1, fim); // divisao lista 2 (segunda metade)

	// 2 - intercalacao, combinando solucoes parciais (conquista)

	// tamanho do vetor auxiliar:
	// 0, 1, 2, 3, 4, 5, 6, 7
	// 0, 1   aux -> tam = 2     1-0+1 = 2
	// 2, 3   aux -> tam = 2     3-2+1 = 2
	// 4, 5, 6, 7   aux -> 4     7-4+1 = 4

	// vetor auxiliar para copiar a intercalacao
	ITEM* aux = (ITEM*) malloc(sizeof(ITEM) * (fim-ini+1) );
	
	int i = ini;	  // indice da lista 1 (ini ate centro)
	int j = centro+1; // indice da lista 2 (centro+1 ate fim)
 	int k = 0;	  // indice do vetor auxiliar (0 ate fim-ini)

 	if(numeromerge != 0)
 	{
		// comparar elementos das duas listas
		while (i <= centro && j <= fim) {
			if (v[i].numero <= v[j].numero) {
				aux[k] = v[i]; 
				i++; // proximo elemento da lista 1
			} 
			else {
				aux[k] = v[j];
				j++; // proximo elemento da lista 2
			}
			k++; // proximo elemento do aux
		}

		// copia os restantes da l1
		while (i <= centro) {
			aux[k] = v[i];
			i++; k++;
		}	
		// copia os restantes da l2
		while (j <= fim) {
			aux[k] = v[j];
			j++; k++;
		}	

		// copia aux para a posicao correta do vetor original	
		// abaixo 3 formas de fazer isso
		/*
		for (k = 0; k <= fim-ini; k++) {
			v[k+ini] = aux[k];
		}

		for (i = ini; i <= fim; i++) {
			v[i] = aux[i-ini];
		}
		*/

		for (i = ini, k = 0; i <= fim; i++, k++) {
			v[i] = aux[k];
		}
		numeromerge--;
		free(aux); // libera vetor auxiliar
 	}
}

int main(int argc, char const *argv[])
{
	char federal[7];

	scanf("%s", federal);

	LISTA listafederal;
	char num[4];
	int i = 0;
	int j = 0;
	int flag = 1;
	char aux;
	do
	{
		j = 0;
		scanf("%s ", num);
		if (num[0] == 'C')
		{
			flag = 0;
		}
		else
		{
			listafederal.item[i].numero = atoi(num);
		}
		while(flag == 1 && (aux = getc(stdin))!= '\n')
		{
			listafederal.item[i].nome[j] = aux;
			j++;
		}
		i++;
	}while(flag == 1);
	listafederal.fim = i - 1;

	LISTA listacaaso;
	int i2 = 0;
	int j2 = 0;
	char aux2;
	char num2[4];
	int flag2 = 1;
	do
	{
		j2 = 0;
		scanf("%s ", num2);
		if ((num2[0] == 'I' && num2[1] == 'D') || num2[0] == 'N')
		{
			flag2 = 0;
		}
		else
		{
			listacaaso.item[i2].numero = atoi(num2);
		}
		while(flag2 == 1 && (aux2 = getc(stdin))!= '\n')
		{
			listacaaso.item[i2].nome[j2] = aux2;
			j2++;
		}
		i2++;
	}while(flag2 == 1);
	listacaaso.fim = i2 - 1;

	scanf("%d", &numeromerge);
	LISTA listafinal;
	listafinal.fim = listafederal.fim + listacaaso.fim;
	for (int i2 = 0; i2 < listafederal.fim; ++i2)
	{
		listafinal.item[i2] = listafederal.item[i2];
		listafinal.item[i2].identificador = 2;
	}
	for (int i3 = 0; i3 < listacaaso.fim; ++i3)
	{
		listafinal.item[listafederal.fim + i3] = listacaaso.item[i3];
		listafinal.item[listafederal.fim + i3].identificador = 1;
	}
	if (strcmp(num2, "ID") == 0)
	{
		mergesort1(listafinal.item, 0, listafederal.fim + listacaaso.fim - 1);
	}
	else if (strcmp(num2, "NAME") == 0)
	{
		mergesort2(listafinal.item, 0, listafederal.fim + listacaaso.fim - 1);
	}

	for (int i2 = 0; i2 < listafinal.fim; ++i2)
	{
		if (listafinal.item[i2].identificador == 1)
		{
			printf("CAASO ");
		}
		else
		{
			printf("FEDERAL ");
		}
		printf("%d %s\n", listafinal.item[i2].numero, listafinal.item[i2].nome);
	}

	return 0;
}