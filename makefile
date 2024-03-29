CC = gcc
CFLAGS = -pthread -Wall -g
OBJS = scripts/simplehttpd.o scripts/buffer.o scripts/config.o scripts/statistics.o
PROG = simplehttpd
PATH_simplehttpd.c = scripts/simplehttpd.c
PATH_header.h = includes/header.h
PATH_config.c = scripts/config.c
PATH_config.h = includes/config.h
#PATH_scheduler.c = scripts/scheduler.c
#PATH_scheduler.h = includes/scheduler.h
PATH_buffer.c = scripts/buffer.c
PATH_buffer.h = includes/buffer.h
PATH_statistics.c = scripts/statistics.c
PATH_statistics.h = includes/statistics.h
PATH_semlib.c = includes/semlib.c
PATH_semlib.h = includes/semlib.h

all:			${PROG}
clean:		rm ${OBJS} *~ ${PROG}
${PROG}:	${OBJS}
					${CC} ${CFLAGS} ${OBJS} -o $@
.c.o:			${CC} ${CFLAGS} $< -c -o $@

simplehttpd.o: PATH_simplehttpd.c PATH_header.h
config.o:  PATH_config.c PATH_config.h
buffer.o: PATH_buffer.c PATH_buffer.h
statistics.o: PATH_statistics.c PATH_statistics.h
semlib.o: PATH_semlib.c PATH_semlib.h
