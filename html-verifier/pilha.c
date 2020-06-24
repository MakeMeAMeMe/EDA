#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void cria_pilha(descritor** pilha){
    *pilha = (descritor*) malloc(sizeof(descritor));
    (*pilha)->topo = NULL;
}

void destroi_pilha(descritor** pilha){
    nodo* aux;
    while ((*pilha)->topo != NULL)
    {
        aux = (*pilha)->topo->abaixo;
        free((*pilha)->topo);
        (*pilha)->topo = aux;
    }
    free(*pilha);
}

void adiciona_topo(descritor* pilha, char info[TAMANHO_MAX_TAG]){
    nodo* container_info = (nodo*) malloc(sizeof(nodo));
    container_info->abaixo = pilha->topo;
    strcpy(container_info->tag, info);
    pilha->topo = container_info;
}

void remove_topo(descritor* pilha, nodo** info_removida){
    if(pilha->topo == NULL){
        *info_removida = NULL;
        return;
    }
    nodo* aux = pilha->topo->abaixo;
    memcpy(*info_removida, pilha->topo, sizeof(nodo));
    free(pilha->topo);
    pilha->topo = aux;
}
