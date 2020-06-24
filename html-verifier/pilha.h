#ifndef _pilha_h
#define _pilha_h

#define TAMANHO_MAX_TAG 20

typedef struct nodo nodo;
typedef struct descritor descritor;

struct nodo {
    nodo* abaixo;
    char tag[TAMANHO_MAX_TAG];
};

struct descritor {
    nodo* topo;
};

void cria_pilha(descritor**);
void destroi_pilha(descritor**);
void adiciona_topo(descritor*, char[TAMANHO_MAX_TAG]);
void remove_topo(descritor*, nodo**);

#endif
