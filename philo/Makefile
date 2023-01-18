CC = gcc

CFLAGS = -Wall -Wextra -Werror 

NAME =	philo

DIR_INC = -I ./includes/

SRCS =		main.c \
			parsing.c \
			init.c \
			philo.c \
			utils.c \
			display.c \
		
SRCS_DIR = ./srcs

DIR_OBJ = 	obj

OBJS = $(addprefix $(DIR_OBJ)/, ${SRCS:.c=.o})

DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all:	${NAME}

${NAME}: ${OBJS}
		${CC} $(DIR_INC) ${OBJS} -o ${NAME} -L -pthread -fsanitize=thread

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DIR_INC) -o $@ -c $< -MMD -g

clean:
		rm -rf ${DIR_OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re