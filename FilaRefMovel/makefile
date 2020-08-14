execName=filaRefMovel
buildFolder=build/
parametrosCompilacao=-Wall -o3

all: check_build_folder compile

compile: main.o lista.o
	g++ $(buildFolder)main.o $(buildFolder)lista.o $(parametrosCompilacao) -o $(execName)

main.o: main.c
	g++ -c main.c $(parametrosCompilacao) -o $(buildFolder)main.o

lista.o: lista.c lista.h
	g++ -c lista.c $(parametrosCompilacao) -o $(buildFolder)lista.o

clear: remove_build_folder
	rm $(execName)

check_build_folder:
	mkdir -p $(buildFolder)

remove_build_folder:
	rm $(buildFolder)*.o
	rmdir $(buildFolder)
