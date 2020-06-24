// Includes Globais
#include <stdio.h>
// Includes Locais
#include "contador.h"

void count_linhas_colunas(descritor* matriz) {
    unsigned int qtd_linhas, qtd_colunas;
    nodo* aux;

    if (matriz->inicio == NULL) {
        printf("A matriz tem 0 linhas\n");
        printf("A matriz tem 0 colunas\n");
        return;
    }

    qtd_linhas = 1;
    qtd_colunas = 1;
    aux = matriz->inicio;

    while (aux->abaixo != NULL) {
        aux = aux->abaixo;
        qtd_linhas++;
    }
    while (aux->direita != NULL) {
        aux = aux->direita;
        qtd_colunas++;
    }
    
    printf("A matriz tem %d linhas\n", qtd_linhas);
    printf("A matriz tem %d colunas\n", qtd_colunas);
}
