#include <stdio.h>
#include <math.h>
	
typedef struct Posicao
{
	float x;
	float y;
}posicao;

//retorna 1 se o coelho ta vivo e 0 se ele foi comido
int quemchegaprimeiro(posicao coelho, posicao raposa, posicao buraco)
{
	float distanciacoelhoburaco = sqrt(((coelho.x - buraco.x)*(coelho.x - buraco.x)) + ((coelho.y - buraco.y)*(coelho.y - buraco.y)));
	float distanciaraposaburaco = sqrt(((raposa.x - buraco.x)*(raposa.x - buraco.x)) + ((raposa.y - buraco.y)*(raposa.y - buraco.y)));
	if (distanciacoelhoburaco < 0)
	{
		distanciacoelhoburaco *= -1;
	}
	if (distanciaraposaburaco < 0)
	{
		distanciaraposaburaco *= -1;
	}

	if (2*distanciacoelhoburaco < distanciaraposaburaco)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{

	int numeroburacos;
	posicao coelho, raposa;
	scanf("%d %f %f %f %f", &numeroburacos, &coelho.x, &coelho.y, &raposa.x, &raposa.y);

	posicao buracos[1000];
	posicao buracomaisperto;
	int flag = 0;

	for (int i = 0; i < numeroburacos; ++i)
	{
		scanf("%f %f", &buracos[i].x, &buracos[i].y);
	}

	for (int i = 0; i < numeroburacos; ++i)
	{
		if (flag != 1 && quemchegaprimeiro(coelho, raposa, buracos[i]) == 1)
		{
			flag = 1;
			buracomaisperto.x = buracos[i].x;
			buracomaisperto.y = buracos[i].y;
		}
	}

	if (flag == 1)
	{
		printf("O coelho pode escapar pelo buraco (%0.3f,%0.3f).\n", buracomaisperto.x, buracomaisperto.y);
	}
	else
	{
		printf("O coelho nao pode escapar.\n");
	}
	return 0;
}