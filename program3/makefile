all: defuseTheBomb checkmem clean

defuseTheBomb: defuseMe.o bomb.o
	gcc -g bomb.o defuseMe.o hidden.o -o defuseTheBomb

defuseMe.o: defuseMe.c
	gcc -c defuseMe.c

bomb.o: bomb.c
	gcc -c bomb.c

checkmem: program3B.c
	gcc program3B.c -o program3B
	valgrind ./program3B

clean: trash.sh
	chmod 777 trash.sh
	./trash.sh defuseMe.o bomb.o defuseTheBomb program3B
