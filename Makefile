NAME = pipex
BONUS_NAME = bonus

SRC = $(wildcard src/*.c)
BONUS_SRC = $(wildcard pipex_bonus/*.c)

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL:.c=.o)

CC = cc 

CFLAGS = -Wall -Werror -Wextra -Iinclude -g

RM = rm -rf

all: ${NAME}

bonus: ${BONUS_NAME}

${NAME}: ${OBJS} ${GNL_OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ${GNL_OBJS} ./libft/libft.a -o ${NAME}
	
${BONUS_NAME}: ${BONUS_OBJS} ${GNL_OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${CFLAGS} ${BONUS_OBJS} ${GNL_OBJS} ./libft/libft.a -o ${NAME}

clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS} ${BONUS_OBJS} ${GNL_OBJS}

fclean: clean
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re
