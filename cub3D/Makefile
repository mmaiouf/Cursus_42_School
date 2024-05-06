HEADER_DIR = headers/
LIBFT = libft.a
MINILIBX = libmlx.a

NAME = cub3D
SRC_FILES = sources/game_check_map_ceil_floor.c \
			sources/game_check_map_duplicate.c \
			sources/game_check_map_utils.c \
			sources/game_check_map_wall.c \
			sources/game_check_map.c \
			sources/game_draw_wall.c \
			sources/game_exit.c \
			sources/game_free.c \
			sources/game_get_texture.c \
			sources/game_hooks.c \
			sources/game_init_map.c \
			sources/game_init_raycasting.c \
			sources/game_init_struct.c \
			sources/game_init.c \
			sources/game_ray_cast_out.c \
			sources/game_raycasting.c \
			sources/game_read_map.c \
			sources/game_update_hero.c \
			sources/game_utils.c \
			sources/game_utils2.c \
			sources/game_utils3.c \
			sources/main.c \

OBJ_FILES = ${SRC_FILES:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS_OBJ =  -I/usr/include -I/libs/mlx_linux -O3
MLXFLAGS = -L/libs/mlx_linux -L/libs/mlx_linux -L/usr/lib -I/libs/mlx_linux -lXext -lX11 -lm -lz
HEADER = headers/cub3D.h
RM = rm -rf

all: libft $(NAME)

libft:
	make -C libs/Libft

%.o: %.c $(HEADER) Makefile libs/Libft/$(LIBFT)
		$(CC) $(CFLAGS) $(MLXFLAGS_OBJ) -c $< -o $@

$(NAME) : $(OBJ_FILES) libs/Libft/$(LIBFT)
		make -C libs/mlx_linux
		$(CC) $(OBJ_FILES) libs/Libft/$(LIBFT) libs/mlx_linux/$(MINILIBX) $(MLXFLAGS) -o $(NAME)

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