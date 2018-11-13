all: tournament.o program4.o
	gcc -g tournament.o program4.o -o program4

program4.o: program4.c
	gcc -c program4.c

tournament.o: tournament.c
	gcc -c tournament.c

run: all
	./program4

clean: program4.o tournament.o program4
	rm program4.o tournament.o program4

checkmem: all
	valgrind ./program4
