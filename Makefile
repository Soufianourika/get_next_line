SRC = get_next_line.c get_next_line_utils.c 

OBJS = ${SRC:.c=.o}
NAME = get_next_line.a
LIBC = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${SRC}
	$(CC) $(CFLAGS) -c $^
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re

