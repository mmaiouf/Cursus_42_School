NAME = philo
SRC_FILES = sources/dinner.c \
			sources/init.c \
			sources/main.c \
			sources/utils.c \
			sources/ft_usleep.c 
OBJ_FILES = ${SRC_FILES:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread
HEADER = headers/philo.h
RM = rm -rf

%.o: %.c $(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME) : $(OBJ_FILES)
		$(CC) $(CFLAGS) $(OBJ_FILES) -lpthread -I $(HEADER) -o $(NAME)

clean :
		${RM} ${OBJ_FILES}

fclean : clean
		${RM} $(NAME)


re : fclean all


.PHONY : all clean fclean re