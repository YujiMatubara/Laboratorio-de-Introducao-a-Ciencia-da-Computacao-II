#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila2.h"

int main(int argc, char const *argv[])
{
	int ponto;
	scanf("%d", &ponto);

	long long int a;
	int b;
	FILA* equacao = FILA_cria_fila();
	int contador = 0;
	long long int y = 0;
	while(scanf("%lld %d", &a, &b) != EOF)
	{
		FILA_adiciona_elemento(equacao, a, b);
		y += a * (pow(ponto, b));
		contador++;
	}
	FILA* derivada = FILA_cria_fila();
	long long int coeficiente;
	int expoente;
	for (int i = 0; i < contador; ++i)
	{
		FILA_remove_elemento(equacao, &coeficiente, &expoente);
		if(expoente >= 1){
			FILA_adiciona_elemento(derivada, coeficiente * expoente, expoente - 1);
		}
		
	}
	printf("f'(x) = ");
	int contador2 = contador;
	contador2--;
	long long int m = 0;
	long long int numero = 0;
	expoente = 1000;
	int control = 1;
	while(!FILA_pilha_vazia(derivada))
	{
		FILA_remove_elemento(derivada, &coeficiente, &expoente);
		if(expoente >= 0){
			m = m + (coeficiente * pow(ponto, expoente));
		}
		if (coeficiente >= 0 && control == 0)
		{
			printf(" + %lld",coeficiente);
			
		}else if(coeficiente < 0){
			printf(" - %lld", coeficiente * -1);
		}else{
			printf("%lld",coeficiente);
		}
		if (expoente == 0)
		{
		}
		else if(expoente == 1){
			printf("x");
		}
		else{

			printf("x^%d", expoente);
		}
		contador2--;
		control = 0;
	}
	printf("\n");
	numero = y - (m * ponto);
	if (numero > 0)
	{
		printf("g(x) = %lldx + %lld\n", m, numero);
	}
	else
	{
		numero *= -1;
		printf("g(x) = %lldx - %lld\n", m, numero);
	}

	return 0;
}