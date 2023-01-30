_NC=`tput sgr0`
_RED=\033[0;31m
_GREEN=\033[0;32m
_YELLOW=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;95m
_CYAN=\033[0;36m
_WHITE=\033[0;37m

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
	@${CC} $(DIR_INC) ${OBJS} -o ${NAME} -L -pthread -fsanitize=thread

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(_BLUE)Generating Philosophers obj... %-33.33s\r$(_NC)" $(notdir $@)
	@$(CC) $(CFLAGS) $(DIR_INC) -o $@ -c $< -MMD -g 

clean:
	@printf "$(_RED)Supressing Philosophers obj... %-33.33s\r$(_NC)" $(notdir $@)
	@rm -rf ${DIR_OBJ}

fclean: clean
	@printf "$(_RED)Supressing Philosophers obj... %-33.33s\r$(_NC)" $(notdir $@)
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re