CC = gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = test.o ../EJ4/PORTS.o

tst: test.o ../EJ4/PORTS.o
	${CC} ${OPTIONS} ${OBJS} -o tst

test.o: ../EJ4/PORTS.h
	${CC} ${OPTIONS} -c test.c

clean: 
	rm *.o