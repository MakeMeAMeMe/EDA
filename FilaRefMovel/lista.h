#pragma once

#include <stddef.h>

typedef struct descritor descritor;
typedef struct nodo nodo;
typedef struct info info;

struct info {
    int x;
};

struct nodo {
    nodo* direita;
    nodo* esquerda;
    info* info;
};

struct descritor {
    size_t pos_atual;
    nodo* ref_movel;
};

int tamanho_da_lista(descritor*);

int busca_na_pos(descritor*, int, info*);

int remove_da_pos(descritor*, int, info*);
