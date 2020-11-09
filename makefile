all:  PROJET EXECUTION

main.o: main.c header.h
	gcc -c main.c -g

affichage.o: affichage.c
	gcc -c affichage.c -g

fonction.o: fonction.c
	gcc -c fonction.c -g

PROJET:  main.o affichage.o fonction.o
	gcc -o PROJET main.o affichage.o fonction.o -lncursesw -g -Wall

DEBUG:
	gdb ./PROJET

EXECUTION:
	./PROJET
