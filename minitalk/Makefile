SRC_DIR = sources/
LIBFT = libft.a

NAME_CLIENT = client
NAME_SERVER = server
SRC_FILES_CLIENT = my_client.c
SRC_FILES_SERVER = my_server.c
SRC_CLIENT = $(addprefix $(SRC_DIR), $(SRC_FILES_CLIENT))
SRC_SERVER = $(addprefix $(SRC_DIR), $(SRC_FILES_SERVER))
OBJ_FILES_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_FILES_SERVER = ${SRC_SERVER:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = -I headers
RM = rm -rf


all:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_FILES_CLIENT)
		@make -C Libft
		$(CC) $(CFLAGS) $(OBJ_FILES_CLIENT) $(HEADER) Libft/$(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_FILES_SERVER)
		@make -C Libft
		$(CC) $(CFLAGS) $(OBJ_FILES_SERVER) $(HEADER) Libft/$(LIBFT) -o $(NAME_SERVER)


clean :
		@make clean -C Libft
		${RM} ${OBJ_FILES_CLIENT}
		${RM} ${OBJ_FILES_SERVER}

fclean : clean
		@make fclean -C Libft
		${RM} $(NAME_CLIENT)
		${RM} $(NAME_SERVER)
		${RM} $(LIBFT)


re : fclean all


.PHONY : all server client clean fclean re
