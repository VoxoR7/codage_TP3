CC=g++
CFLAGS=-O2
LFLAGS=-lpthread

PROG=main

$(PROG): boucle.o agent.o main.o
	$(CC) boucle.o main.o agent.o -o $(PROG) $(LFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

agent.o: agent.cpp agent.h
	$(CC) $(CFLAGS) -c agent.cpp -o agent.o

boucle.o: boucle.c boucle.h
	$(CC) $(CFLAGS) -c boucle.c -o boucle.o

clean:
	rm -f *.o

cleanmake: clean
	clear
	make

make: $(PROG)