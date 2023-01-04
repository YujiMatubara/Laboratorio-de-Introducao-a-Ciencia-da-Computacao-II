#include <stdio.h>
#include <stdlib.h>

typedef struct funcao FUNCAO;

typedef struct fila FILA;

void shifta_vetores(FILA *fila, int tamanho);

FILA *FILA_cria_fila();

void FILA_adiciona_elemento(FILA *fila, int coeficientenovo, int expoentenovo);

void FILA_remove_elemento(FILA *fila, long long int *coeficiente, int *expoente);

void FILA_deleta_fila(FILA *fila);

int FILA_pilha_vazia(FILA *fila);