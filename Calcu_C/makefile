CC = gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = main.o lectura.o math.o

calc: main.o lectura.o math.o
	${CC} ${OPTIONS} ${OBJS} -o calc

main.o: main.c const.h lectura.h math.h
	${CC} ${OPTIONS} -c main.c

lectura.o: lectura.c lectura.h const.h
	${CC} ${OPTIONS} -c lectura.c

math.o: math.c math.h const.h
	${CC} ${OPTIONS} -c math.c

clean: 
	rm *.o