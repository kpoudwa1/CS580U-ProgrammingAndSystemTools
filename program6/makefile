all: bst.o program6.o
	gcc -g bst.o program6.o -o program6

bst.o: bst.c
	gcc -c bst.c

program6.o: program6.c
	gcc -c program6.c

run: all
	./program6

clean: 
	rm -rf bst.o program6.o program6

checkmem: all
	valgrind --leak-check=full --show-leak-kinds=all ./program6
