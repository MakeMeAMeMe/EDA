#include <stdio.h>

#include "fila.h"

int main() {

	descF* p; //n vai um struct aqui? n�o 
	noFila* aux;
	p = cria(sizeof(info));
	info data[] = { {20, "Otavio"}, {21, "Augusto"}, {30, "Rebeca"} };

	// Vamos criar uma fila
	// Adicionar 3 nodos
	for (int i = 0; i < 3; i++) {
		if (insere(&data[i], p) == SUCESSO) {
			printf("inserido na fila: %i %s \n", data[i].idade, data[i].nome);
			printf("tamanho da fila %i\n", tamanhoDaFila(p));
		}
		else {
			printf("\n Erro na insercao \n");
		}
	}

	// Printar
	for (int i = 0; i < 3; i++) {
		printf("Dados 0: %i %s \n", data[i].idade, data[i].nome);
	}

	aux = p->cauda;
	while (aux) {
		printf("Elemento 0: %i %s \n", aux->dados.idade, aux->dados.nome);
		aux = aux->defronte;
	}


	// Inverter
	inverte(p);


	// Printar
	for (int i = 0; i < 3; i++) {
		printf("Dados 0: %i %s \n", data[i].idade, data[i].nome);
	}
	// Elementos devem ser inversos ao printados por dados
	aux = p->cauda;
	while (aux) {
		printf("Elemento 0: %i %s \n", aux->dados.idade, aux->dados.nome);
		aux = aux->defronte;
	}
	// Sair
	// precisa destruir ?
	// � bom
	destroi(p);
	return 0;
}

// Tudo certo?

// sim 

// M�os � obra
// Deixa quieto :shy:

// ele tem um exemplo com nomes e idades 
// N�o precisa, vamos fazer o nosso

// Tenta rodar, � para ter uma seta verde bem em cima
// apareceu alguns avisos 
// Creio que seja como vc criou o projeto, o visual studio � bem chato com rela��o a isso
// Me de 1 min para recriar o projeto desse lado
// me convida dai 
