#ifndef _pilha_h
#define _pilha_h

typedef struct nodo nodo;
typedef struct descritor descritor;

struct nodo
{
    nodo *abaixo;
    char tag[20];
};

struct descritor
{
    nodo* topo;
};

#endif
