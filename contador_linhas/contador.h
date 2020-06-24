#ifndef _contador_h
#define _contador_h

typedef struct info info;
typedef struct nodo nodo;
typedef struct descritor descritor;

struct info {
    char value;
};

struct nodo {
    nodo* acima;
    nodo* abaixo;
    nodo* esquerda;
    nodo* direita;
    info info;
};

struct descritor {
    nodo* inicio;
};

void count_linhas_colunas(descritor* matriz);

#endif