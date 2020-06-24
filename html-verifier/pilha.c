#include "pilha.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void cria_pilha(descritor** pilha) {
    *pilha = (descritor*)malloc(sizeof(descritor));
    (*pilha)->topo = NULL;
}

void reinicia_pilha(descritor* pilha){
    nodo* aux;
    while (pilha->topo != NULL) {
        aux = pilha->topo->abaixo;
        free(pilha->topo);
        pilha->topo = aux;
    }
}

void destroi_pilha(descritor* pilha) {
    reinicia_pilha(pilha);
    free(pilha);
}

void adiciona_topo(descritor* pilha, char *info) {
    nodo* container_info = (nodo*)malloc(sizeof(nodo));
    container_info->abaixo = pilha->topo;
    strncpy(container_info->tag, info, TAMANHO_MAX_TAG);
    pilha->topo = container_info;
}

void remove_topo(descritor* pilha) {
    if (pilha->topo == NULL) {
        return;
    }
    nodo* aux = pilha->topo->abaixo;
    free(pilha->topo);
    pilha->topo = aux;
}

void print_pilha(descritor* pilha){
    nodo* aux; 
    aux = pilha->topo;
    printf("pilha");
    while(aux != NULL ){
        printf("->%s", aux->tag);
        aux = aux->abaixo;
    }
    printf("\n");
}
