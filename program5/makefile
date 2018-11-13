all: vector.o list.o profile.o program5.o
	gcc -g vector.o list.o profile.o program5.o -o program5

vector.o: vector.c
	gcc -c vector.c

list.o: list.c
	gcc -c list.c

profile.o: profile.c
	gcc -c profile.c

program5.o: program5.c
	gcc -c program5.c

run: all
	./program5

clean: 
	rm -rf vector.o program5.o list.o profile.o program5

checkmem: all
	valgrind --leak-check=full --show-leak-kinds=all ./program5
