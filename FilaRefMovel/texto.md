Pode digitar aqui :)

beleza

o arquivo lista.h tem apenas a definição das structs e das funções que o trabalho pede.
o arquivo lista.c tem a implementação das funções

quer começar pela função que retorna o tamanho da lista?

pode ser 


int tamanho_da_lista(descritor* lista);

é uma função que recebe apenas o endereço para a lista
a ideia é não mover mais do que o necessário o ponteiro de referncia da lista
na descrição do trabalho, o professor disse que a lista cresce da esquerda para a direita, ou seja
1) a<->b<->c, lista inicial
2) a<->b<->c<->d, após a inserção de d na lista

portanto para determinar a tamanho da lista, podemos pensar em duas maneiras
1) Mover a referencia para o final(direita) da lista, assim lista->pos_atual + 1 vai ser igual ao numero de items na lista
2) ter uma varivel tamanho e o nodo auxiliar, tamanho terá o valor da pos_atual da referencia da lista, e o nodo aux irá caminnhar para a direita na lista, começando na posição da referencia, assim, para cada vez que o auxiliar caminhar para a direita, tamanho deve ser incrementado em 1
2.1) A implementação do 2 está comentado na função

tudo certo?

sim, ele mencionou que queria o minimo de movimentação certo ? 
a ideia do minimo movimento se dá por não passar pelo mesmo nodo 2 vezes quando vc está caminhando
no item 1, seria pelo fato de vc usar o fato do descritor poder estar no meio da lista, então vc só caminha para a direita, no item 2 é basicamente a mesma coisa, vc sé está abstraindo variaveis adicionais
o problema apareceria se vc fosse primeiro para o começo da lista, para então ir para a direita

certo?

sim 

a ideia de como a função funciona é tranquilo?
tipo

descritor {ref: c, posAtual: 2}
lista: a<->b<->c<->d<->e

assumindo um estado inicial igual a esse ^

se eu movo a ref para o final

descritor {ref: d, posAtual: 3}
lista: a<->b<->c<->d<->e

descritor {ref: e, posAtual: 4}
lista: a<->b<->c<->d<->e

pos de a = 0 foi como eu implementei
no final, retornando posAtual + 1 vai ser igual ao tamanho da lista

ele funciona se for tipo uma quantidade par 
sim
pode fazer o teste, copia e cola a estrutura acima, e altera como vc quiser

toda iteração, move a ref 1 item para a direita, e incrementa posAtual em 1, até o final (ref->direita == NULL)

descritor {ref: b, posAtual: 1}
a<->b<->c<->d

descritor {ref: c, posAtual: 2}
a<->b<->c<->d

descritor {ref: d, posAtual: 3}
a<->b<->c<->d

3+1=4, perfeito

entendi, pq pode ser o d minha ref, mais o posatual ja meio q diz quantos tem atraz dele
perfeito

só pensando n tinha percebido 

a mesma ideia é usada no item 2 dessa função, a var tamanho recebe posAtual no começo, pq isso me diz quantos items existem a esquerda, portanto eu só preciso contar os items à direita

certo?
sim

de uma olhada na função em si, e veja se não tem alguma dúvida, qualquer coisa

ta

tudo certo com a função de busca? sim, vou ver as outras 

da um toque quando quiser que eu explique o reencadeamento da remoção

o professor colocou q O documento de entrega terá que estar digitalizado, manuscrito e de
autoria individual. manuscrito quer dizer q tenho q copiar em uma folha, escaniar e mandar pra ele ? isso
tem um teste de mesa pra fazer ainda => tem, da para fazer parecido com o que fizemos acima, só precisa tem alguns casos especiais: lista vazia, ref a direita do alvo, ref a esquerda do alvo, pos alvo fora da lista (pos alvo > tamanho da lista)

certo, ali no tamanho da lista vamos fazer a opção em verde certo ?
pode ser
é que eu entendi bem hehe, muito bom
aque parte embaixo sai dai né  
qual parte? entendi, pode ser as duas, a de baixo pode ser melhor para o professor, mas as duas funcionam. E as duas funcionam do mesmo jeito, só muda o estado final da lista
 
se funciona igual então pode deixar a outra. tudo bem

ficaria assim ? isso

int tamanho_da_lista(descritor* lista) {
tamanho_lista(lista){
    if (lista->pos_atual == -1) { // lista vazia
        return 0;
    }
    // move ref para o fim da lista
    while (lista->ref_movel->direita) {
        lista->ref_movel = lista->ref_movel->direita;
        lista->pos_atual++;
    }
    return lista->pos_atual + 1;
}

ja volto, vou tomar um cafe rapidinho , blz
