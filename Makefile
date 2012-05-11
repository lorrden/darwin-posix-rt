CC=clang
AR=ar
RANLIB=ranlib

CFLAGS=-O2

FILES=clock_gettime.c
OBJECTS=$(FILES:.c=.o)

all: libdarwinprt.a

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

libdarwinprt.a: ${OBJECTS}
	${AR} -r $@ ${OBJECTS}
	${RANLIB} $@
clean:
	rm -f *.o
	rm -f libdarwinprt.a
