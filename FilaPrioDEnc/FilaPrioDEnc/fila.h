#define LIVRE 0
#define OCUPADA 1
#define FRACASSO 0
#define SUCESSO 1
#define FALSO 0
#define VERDADEIRO 1
#define NAO 0
#define SIM 1
#define MAIOR 1
#define IGUAL 0
#define MENOR -1
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define debugging  1

// Vou alterar umas definições aqui para o código ficar um pouco melhor

typedef struct info info;
typedef struct noFila noFila;
typedef struct descF descF;

struct info {
	int idade;
	char nome[30];
};

struct noFila {
	info dados;
	noFila* atras;
	noFila* defronte;
};

struct descF {
	noFila* frente;
	noFila* cauda;
	int tamInfo;
};


//======================APLICACAO=====================


//======================FILA=====================
struct descF* cria(int tamInfo); // Vamos usar
int insere(info* novo, descF* p);
int tamanhoDaFila(descF* p);
int reinicia(descF* p);
struct descF* destroi(descF* p);
int buscaNaCauda(info* reg, descF* p);
int buscaNaFrente(info* reg, descF* p);
int remove(info* reg, descF* p);
int testaVazia(descF* p);
int inverte(descF* p);
