SRC_DIR = sources/
HEADER_DIR = headers/
LIBFT = libft.a

NAME = push_swap
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = ${SRC_FILES:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = $(wildcard $(HEADER_DIR)*.h)
RM = rm -rf

%.o: %.c $(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME) : $(OBJ_FILES)
		@make -C Libft
		$(CC) $(CFLAGS) $(OBJ_FILES) -I $(HEADER) Libft/$(LIBFT) -o $(NAME)


clean :
		@make clean -C Libft
		${RM} ${OBJ_FILES}

fclean : clean
		@make fclean -C Libft
		${RM} $(NAME)
		${RM} $(LIBFT)


re : fclean all


.PHONY : all clean fclean re