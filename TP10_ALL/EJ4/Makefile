CC = gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = main.o PORTS.o

ej4: main.o PORTS.o
	${CC} ${OPTIONS} ${OBJS} -o ej4

main.o: main.c PORTS.h const.h 
	${CC} ${OPTIONS} -c main.c

PORTS.o: PORTS.c PORTS.h const.h
	${CC} ${OPTIONS} -c PORTS.c

clean: 
	rm *.o