#include <stdlib.h>
#include <string.h>
#include "lista.h"

int tamanho_da_lista(descritor* lista) {
    // Pode ser feito sem mover a ref movel, utilizando um nodo* aux para percorrer a lista, e salvando numa variavel tamanho
    /**
     * if(lista->pos_atual == -1){ 
     * // se pos_atual == -1, a lista está vazia, posso retornar 0 aqui => sim 
     * // zero ja é o primeiro elemento => sim, então -1 indica que o nodo 0 não está presente
     * // não é preciso na implementação com a var tamanho
     *   return 0;
     * }
     * int tamanho;
     * nodo* aux;
     * tamanho = lista->pos_atual + 1; aqui tamanho ja recebe quantos tem antes né => isso
     * aux = lista->ref_movel;
     * 
     * // aux caminha para a direita, incrementando tamanho a cada iteração 
     * while(aux){
     *  aux = aux->direita;
     *  tamanho++;
     * }
     * return tamanho;
     */
    if (lista->pos_atual == -1) {
        return 0;
    }
    while (lista->ref_movel->direita) {
        lista->ref_movel = lista->ref_movel->direita;
        lista->pos_atual++;
    }
    return lista->pos_atual + 1;
}

int busca_na_pos(descritor* lista, int pos_alvo, info* reg) {
    if (lista->pos_atual == -1 || pos_alvo < 0) {
        return 0;
    }
    // Se vc entender bem essa série de if`s e while`s, vc vai entender a primeira metade da função de remover junto, é a mesma coisa, só muda o final
    // Toda a ideia é fazer a ref apontar para o nodo posAlvo = sim 
    // a ref aponta para algo a direita da posAlvo
    if (lista->pos_atual > pos_alvo) {
        // caminha para a esquerda até posAlvo
        while (lista->pos_atual != pos_alvo) { 
            lista->ref_movel = lista->ref_movel->esquerda;
            lista->pos_atual--;
        }
    // a ref aponta para algo a esquerda da posAlvo
    } else if (lista->pos_atual < pos_alvo) {
        // caminha para a direita até posAlvo
        while (lista->pos_atual != pos_alvo) {
            // se não houver mais items à direita, retorna falha 
            if (lista->ref_movel->direita == NULL) {
                return 0;
            }
            lista->ref_movel = lista->ref_movel->direita;
            lista->pos_atual++;
        }
    }

    memcpy(reg, lista->ref_movel->info, sizeof(info));

    return 1;
}

int remove_da_pos(descritor* lista, int pos_alvo, info* reg) {
    // Qualquer duvida, digita no texto.md = beleza 
    if (lista->pos_atual == -1 || pos_alvo < 0) {
        return 0;
    }
    if (lista->pos_atual > pos_alvo) {
        while (lista->pos_atual != pos_alvo) {
            lista->ref_movel = lista->ref_movel->esquerda;
            lista->pos_atual--;
        }
    } else if (lista->pos_atual < pos_alvo) {
        while (lista->pos_atual != pos_alvo) {
            if (lista->ref_movel->direita == NULL) {
                return 0;
            }
            lista->ref_movel = lista->ref_movel->direita;
            lista->pos_atual++;
        }
    }
    // Tudo para cima é só para fazer a ref apontar para o nodo pos_alvo, igual a busca
    nodo* aux;
    aux = lista->ref_movel;
    memcpy(reg, lista->ref_movel->info, sizeof(info));
    // if's para reencadeear e ajustar o descritor
    if (lista->ref_movel->esquerda != NULL) {
        lista->ref_movel->esquerda->direita = lista->ref_movel->direita;
    }
    if (lista->ref_movel->direita != NULL) {
        lista->ref_movel->direita->esquerda = lista->ref_movel->esquerda;
        lista->ref_movel = lista->ref_movel->direita;
    } else {
        lista->ref_movel = lista->ref_movel->esquerda;
        lista->pos_atual--;
    }
    // liberar a memoria ocupada pelo nodo removido 
    free(aux);

    return 1;
}