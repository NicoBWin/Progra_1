CC = gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = main.o lectura.o ../EJ4/PORTS.o

ej6: main.o lectura.o ../EJ4/PORTS.o
	${CC} ${OPTIONS} ${OBJS} -o ej6

main.o: main.c lectura.h ../EJ4/const.h
	${CC} ${OPTIONS} -c main.c

lectura.o: lectura.c lectura.h ../EJ4/const.h
	${CC} ${OPTIONS} -c lectura.c

clean: 
	rm *.o