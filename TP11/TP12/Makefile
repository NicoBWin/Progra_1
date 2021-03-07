CC = gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = main.o lectura.o PORTS.o nonblock.o hardware.o

main: main.o lectura.o PORTS.o nonblock.o hardware.o
	${CC} ${OPTIONS} ${OBJS} -o main 

main.o: main.c PORTS.h lectura.h nonblock.h const.h
	${CC} ${OPTIONS} -c main.c 

lectura.o: lectura.c lectura.h const.h
	${CC} ${OPTIONS} -c lectura.c

PORTS.o: PORTS.c PORTS.h const.h
	${CC} ${OPTIONS} -c PORTS.c

nonblock.o: nonblock.c nonblock.h
	${CC} ${OPTIONS} -c nonblock.c

hardware.o: hardware.c hardware.h const.h PORTS.h
	${CC} ${OPTIONS} -c hardware.c

clean: 
	rm *.o

