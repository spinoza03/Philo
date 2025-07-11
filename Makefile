
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo

SRC = src/main.c src/pars.c utils/atoi_ph.c utils/putstr.c src/init.c src/start_sim.c\
		utils/actions.c utils/time.c utils/death.c

OBJ = ${SRC:.c=.o}
HEADER = include/philo.h

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I include -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean