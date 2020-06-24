parametrosCompilacao=-Wall  #-Wshadow

all: html-verify

html-verify: main.o pilha.o
	gcc -o3 -o html_verify main.o pilha.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

pilha.o: pilha.h pilha.c
	gcc -c pilha.c $(parametrosCompilacao)

clean:
	rm *.o html_verify
