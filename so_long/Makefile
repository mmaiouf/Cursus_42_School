SRC_DIR = sources/
HEADER_DIR = headers/
LIBFT = libft.a
MINILIBX = libmlx.a

NAME = so_long
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = ${SRC_FILES:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS_OBJ =  -I/usr/include -I/libs/mlx_linux -O3
MLXFLAGS = -L/libs/mlx_linux -L/libs/mlx_linux -L/usr/lib -I/libs/mlx_linux -lXext -lX11 -lm -lz
HEADER = $(wildcard $(HEADER_DIR)*.h)
RM = rm -rf

all: libft $(NAME)

libft:
	make -C libs/Libft

%.o: %.c $(HEADER) Makefile libs/Libft/$(LIBFT)
		$(CC) $(CFLAGS) $(MLXFLAGS_OBJ) -c $< -o $@

$(NAME) : $(OBJ_FILES) libs/Libft/$(LIBFT)
		make -C libs/mlx_linux
		$(CC) $(OBJ_FILES) -I $(HEADER) libs/Libft/$(LIBFT) libs/mlx_linux/$(MINILIBX) $(MLXFLAGS) -o $(NAME)

clean :
		make clean -C libs/Libft
		make clean -C libs/mlx_linux
		${RM} ${OBJ_FILES}

fclean : clean
		make fclean -C libs/Libft
		make clean -C libs/mlx_linux
		${RM} $(NAME)
		${RM} $(LIBFT)
		${RM} $(MINILIBX)


re : fclean all


.PHONY : all clean fclean re libft

