#include "fila.h"



/*************** CRIA ***************/
struct descF* cria(int tamInfo)
{
	struct descF* desc = (descF*)malloc(sizeof(descF));
	if (desc != NULL) {
		desc->cauda = NULL;
		desc->frente = NULL;
		desc->tamInfo = tamInfo;
	}
	return desc;
}

/*************** INSERE A PARTIR DA FRENTE ***************/
int insere(info* pInfo, descF* p)
{
	int result;
	noFila* novoNoFila = NULL, * visitado = NULL;
	if ((novoNoFila = (noFila*)malloc(sizeof(noFila))) != NULL)
	{
		memcpy(&(novoNoFila->dados), pInfo, p->tamInfo);
		if (p->frente == NULL && p->cauda == NULL) /*fila vazia*/
		{
			novoNoFila->atras = novoNoFila->defronte = NULL;
			p->frente = p->cauda = novoNoFila;

		}
		else
		{
			visitado = p->frente; /*maior prioridade na frente */
			while (visitado->atras != NULL && (visitado->dados.idade >= novoNoFila->dados.idade))
				visitado = visitado->atras; /* A(idade) <= B(idade) */


			if (visitado->dados.idade < novoNoFila->dados.idade)   /* novo item fica a frente do visitado */
			{
				novoNoFila->atras = visitado;
				if (visitado->defronte != NULL)
				{
					novoNoFila->defronte = visitado->defronte;
					visitado->defronte->atras = novoNoFila;
				}
				else
				{  // novo item é o de maior prioridade de todos na fila, sendo a nova frente
					novoNoFila->defronte = NULL;
					p->frente = novoNoFila;
				}
				visitado->defronte = novoNoFila;

			}
			else
			{// novo item é o de menor prioridade de todos na fila, sendo a nova cauda
				novoNoFila->defronte = visitado;
				novoNoFila->atras = NULL;
				visitado->atras = novoNoFila;
				p->cauda = novoNoFila;
			}


		}
		return SUCESSO;
	}

	return FRACASSO;

}


/*************** REMOVE DA FRENTE ***************/
int remove(info* reg, descF* p)
{
	int ret = FRACASSO;
	noFila* aux = p->cauda;

	if (p->cauda != NULL && p->frente != NULL)
	{
		memcpy(reg, &(p->frente->dados), p->tamInfo);

		if (aux == p->frente)
		{ // caso tenha 1 elemento apenas
			free(p->frente);
			p->frente = p->cauda = NULL;
		}
		else
		{
			p->frente = p->frente->atras;
			free(p->frente->defronte);
			p->frente->defronte = NULL;

		}
		ret = SUCESSO;
	}

	return ret;
}

/*************** BUSCA NA FRENTE ***************/
int buscaNaFrente(info* reg, descF* p)
{
	int ret = FRACASSO;

	if (p->frente != NULL && p->cauda != NULL) {
		memcpy(reg, &(p->frente->dados), p->tamInfo);
		ret = SUCESSO;
	}

	return ret;
}

/*************** BUSCA NA CAUDA ***************/
int buscaNaCauda(info* reg, descF* p)
{
	int ret = FRACASSO;

	if (p->cauda != NULL && p->frente != NULL) {
		memcpy(reg, &(p->cauda->dados), p->tamInfo);
		ret = SUCESSO;
	}

	return ret;
}

/*************** VAZIA? ***************/
int testaVazia(descF* p)
{
	if (p->frente == NULL && p->cauda == NULL) {
		return SIM;
	}

	return NAO;
}

/*************** TAMANHO ***************/
int tamanhoDaFila(descF* p)
{
	int tam = 0;
	noFila* aux = p->cauda;

	while (aux != NULL)
	{
		tam++;
		aux = aux->defronte;

	}

	return tam;
}

/*************** PURGA ***************/
int reinicia(descF* p)
{
	int ret = FRACASSO;
	noFila* aux = NULL;

	if (p->frente != NULL && p->cauda != NULL)
	{
		aux = p->cauda->defronte;
		while (aux != NULL)
		{
			free(p->cauda);
			p->cauda = aux;
			aux = aux->defronte;
		}

		free(p->cauda);
		p->frente = NULL;
		p->cauda = NULL;
		ret = SUCESSO;
	}
	return ret;
}

/*************** DESTROI ***************/
struct descF* destroi(descF* p)
{
	reinicia(p);
	free(p);
	return NULL; // aterra o ponteiro externo, declarado na aplicação
}

/**
* Podemos colocar aqui a implementação da função inverter a fila
*/

/***************inverte***********/
int inverte(descF* p) {
	noFila* aux, * ptr; // ptr = "caminhante" , aux = endereÃƒÂ§o pra fazer troca
	if (p->cauda) { // descritor nÃ£o vazio
		ptr = p->cauda; // caminhante comeÃ§a no final
		while (ptr) { // enquanto ouver nodos 
			aux = ptr->defronte; // auxiliar recebe frente 
			ptr->defronte = ptr->atras; // frente recene atras
			ptr->atras = aux; // atras recebe auxiliar 
			ptr = aux; // caminhate vai pro antigo frente do nodo
		}
		// Atualizar o descritor
		aux = p->cauda;
		p->cauda = p->frente;
		p->frente = aux;
		return SUCESSO;
	}
	return FRACASSO; // se descritor vazio retorna erro
}
