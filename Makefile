project: infix.o stack.o listADT.o operations.o
	cc infix.o stack.o listADT.o operations.o -lm -o project
operations.o: operations.c listADT.h operations.h
	cc -c operations.c -Wall
infix.o: infix.c stack.h operations.h
	cc -c infix.c -Wall
stack.o: stack.c stack.h
	cc -c stack.c -Wall
listADT.o: listADT.c listADT.h
	cc -c listADT.c -Wall