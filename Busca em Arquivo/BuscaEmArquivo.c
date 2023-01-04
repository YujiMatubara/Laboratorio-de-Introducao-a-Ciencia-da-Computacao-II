#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO -1000

//retorna 0 se as palavras forem iguais, 1 se a palavra 1 for antes da palavra 2, e -1 se a palavra 2 vier antes da 1
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

//fazer a busca de uma palavra num vetor ordenado alfabeticamente
int busca_binaria(char **matrizpalavrastexto, char *chave, int inicio, int fim)
{
	int centro = (int)((inicio + fim)/2.0);
	if(inicio > fim)
		return ERRO;
	int comp = comparacao(chave, matrizpalavrastexto[centro]);
	if (comp == 0)
	{
		return centro;
	}
	else if (comp < 0)
	{
		return busca_binaria(matrizpalavrastexto, chave, inicio, centro - 1);
	}
	else if(comp > 0)
	{
		return busca_binaria(matrizpalavrastexto, chave, centro + 1, fim);
	}
	return ERRO;
}

//uma funcao tolower
void palavra_minuscula(char *palavra)
{
	int i = 0;
	while(palavra[i] != '\0')
	{
		if (palavra[i] >= 0x41 && palavra[i] <= 0x5A)
        {
        	palavra[i] = palavra[i] + 32;
        }
        i++;
	}
}

//funcao que ordena as palavras em ordem alfabetica
void insertion_sort(char** matrizpalavrastexto, int tamanho)
{
	for (int i = 1; i < tamanho; ++i)
	{
		char *chave = matrizpalavrastexto[i];
		int j = i - 1;
		while(j >= 0 && strcmp(chave, matrizpalavrastexto[j]) < 0)
		{
			matrizpalavrastexto[j + 1] = matrizpalavrastexto[j];
			j--;
		}
		matrizpalavrastexto[j + 1] = chave;
	}
}

//insere todas as palavras do texto num vetor de palavras
char** le_texto(FILE* arquivo, int* numpalavras)
{
	char **matrizpalavrastexto = (char **)malloc(sizeof(char*));
	int contador = 0;
	char aux[50];
	while((fscanf(arquivo, "%s", aux)) != EOF)
	{
		contador++;
		matrizpalavrastexto = (char **)realloc(matrizpalavrastexto, sizeof(char*) * contador);
		matrizpalavrastexto[contador - 1] = (char *)malloc(sizeof(char) * 50);
		strcpy(matrizpalavrastexto[contador - 1], aux);
		palavra_minuscula(matrizpalavrastexto[contador - 1]);
	}

	*numpalavras = contador;
	return(matrizpalavrastexto);
}

int main(int argc, char const *argv[])
{
	char nomearquivotxt[50];
	int quantidadebusca;
	//lendo o arquivotxt, ex: "historia.txt" e inserindo na string
	scanf("%s %d", nomearquivotxt, &quantidadebusca);


	//inserindo as palavras de busca em um vetor estatico
	//vetor:	|palavra1|	|palavra2|	|palavra3|	etc...
	//a maior palavra da lingua portuguesa tem 46 letras, entao 50 letras e mais que o suficiente
	char vetorpalavras[quantidadebusca][50];
	//lendo as palavras de busca
	for (int  i = 0; i < quantidadebusca ; ++i)
	{
		scanf("%s", vetorpalavras[i]);
	}
	//abrindo o arquivo txt para ler as palavras
	FILE* arquivo;
	arquivo = fopen(nomearquivotxt, "r");

	int numpalavras;
	//matriz que guarda as palavras a serem lidas
	char** matrizpalavrastexto = le_texto(arquivo, &numpalavras);
	//ordena as palavras da matriz em ordem alfabetica
	insertion_sort(matrizpalavrastexto, numpalavras);
	int posicao = 0;
	for (int i = 0; i < quantidadebusca; ++i)
	{
		int cont = 0;
		//busca a posicao da palavra no vetor de palavras
		posicao = busca_binaria(matrizpalavrastexto, vetorpalavras[i], 0, numpalavras -1);
		//caso a busca binaria tenha dado certo, continue...
		if(posicao != ERRO)
		{
			//contador que soma 1 se a palavra existir no texto
			cont++;
			while (posicao >= 0 && comparacao(matrizpalavrastexto[posicao], matrizpalavrastexto[posicao - 1]) == 0)
			{
				posicao--;
			}
			
			while( (posicao + 1) < numpalavras && comparacao(matrizpalavrastexto[posicao], matrizpalavrastexto[posicao + 1]) == 0)
			{
				//soma 1 toda vez que a palavra se repetir
				cont++;
				posicao++;
			}
		}
		else
		{
			//se a palavra nao existir devemos encontrar sua ordem alfabetica, onde ela estaria no texto caso existisse
			posicao = 0;
			while(posicao < numpalavras && strcmp(vetorpalavras[i], matrizpalavrastexto[posicao]) > 0)
			{
				posicao++;
			}
			posicao--;

		}

		//printando a resposta
		printf("%s %d", vetorpalavras[i], cont);
		if((posicao + 1) < numpalavras)
		{
			printf(" %s", matrizpalavrastexto[posicao + 1]);
			if((posicao + 2) < numpalavras)
			{
				printf(" %s", matrizpalavrastexto[posicao + 2]);	
				if((posicao + 3) < numpalavras)
				{
					printf(" %s", matrizpalavrastexto[posicao + 3]);
				}
			}
		}
		printf("\n" );
	}

	//liberando a heap e fechando o arquivo txt aberto
	for (int i = 0; i < numpalavras; ++i)
	{
		free(matrizpalavrastexto[i]);
	}
	free(matrizpalavrastexto);
	fclose(arquivo);
	
	return 0;
}
