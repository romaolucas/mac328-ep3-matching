CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c99 -g

match: main.c digraph.o algs.o stack.o
	$(CC) $^ -o $@ $(CFLAGS)

algs.o: algs.c algs.h stack.h digraph.h
	$(CC) $(CFLAGS) -c algs.c

stack.o: stack.c stack.h digraph.h
	$(CC) $(CFLAGS) -c union_find.c 

digraph.o: digraph.c digraph.h
	$(CC) $(CFLAGS) -c digraph.c
