/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:35 by mou3              #+#    #+#             */
/*   Updated: 2024/04/23 00:37:40 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/Libft/libft.h"
# include "../libs/mlx_linux/mlx.h"

# define WRONG_NB_ARG "error\nwrong numbers of argument"
# define OPEN_FAILED "error\nopen() failed"
# define CLOSE_FAILED "error\nclose() failed"
# define FILE_DOESNT_EXIST "error\nfile does not exist"
# define OUT_OF_RANGE "error\nout of range rgb"
# define MISSING_PATH "error\npath does not exit"
# define WRONG_RGB "error\nwrong RGB"
# define MAP_HERO_ERROR "error\nmissing or duplicate hero in your map"
# define MAP_DUPLPICATE_ERROR "error\nduplicate datas"
# define ERROR_CEIL_FLOOR "error\nerror in ceil/floor"
# define ERROR_DIRECTION "error\nerror in direction or in ceil/floor"
# define MALLOC_FAIL "error\na malloc() failed"
# define MLX_INIT_FAILED "error\nmlx_init() failed"
# define MLX_NW_FAILED "error\nmlx_new_window() failed"
# define MLX_FTI_FAILED "error\nmlx_file_to_image() failed"
# define MLX_GDA_FAILED "error\nmlx_get_data_addr() failed"
# define WALL_ERROR "error\nwall error"
# define ERROR_VALUE_CEIL "error\nthere is a non-digit value in your ceil"
# define ERROR_VALUE_FLOOR "error\nthere is a non-digit value in your floor"
# define ERROR_COMMA "error\nerror comma"
# define ERROR_BETWEEN "error\nthere is a space between your digit"
# define EMPTY_MAP "error\nempty map"
# define NEWLINE_IN_MAP "error\na new line in your grid map"
# define NEWLINE_ONLY "error\nnew online only"
# define IS_NOT_CUB "error\nyour file do not have extension .cub"
# define MAP_NO_VALID "error\nyour map is not valid"
# define ERROR_ISLAND "error\nthere is an island !"
# define OUT_OF_MAP_HERO "error\nyour hero is out of the map !"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define MOVE_VELOCITY 0.00002
# define ROTATION_VELOCITY 0.000008

# define PI 3.14159265358979323846
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_PRESS 2
# define KEY_EXIT 17

# define ID_W 0
# define ID_A 1
# define ID_S 2
# define ID_D 3
# define ID_LEFT 4
# define ID_RIGHT 5

typedef struct s_line
{
	int	height;
	int	start;
	int	end;
}	t_line;

typedef struct s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct s_raycasting
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	texture_pos;
	double	step;
	int		map_x;
	int		map_y;
	int		texture_x;
	int		texture_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

}	t_raycasting;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		texture_x;
	int		texture_y;
	int		width;
	int		height;
}	t_img;

typedef struct s_color
{
	int	floor;
	int	ceil;
}	t_color;

typedef struct s_map
{
	int		i;
	int		j;
	int		fd;
	int		x;
	int		nb_lines;
	int		hero_x;
	int		hero_y;
	int		floor_rgb;
	int		ceil_rgb;
	int		value_count;
	int		nb_we;
	int		nb_so;
	int		nb_ea;
	int		nb_no;
	int		nb_f;
	int		nb_c;
	int		start_map;
	int		i_m;
	int		j_m;
	int		i_p;
	int		j_p;
	int		one_end_floor;
	int		one_end_ceil;
	char	*line;
	char	*buffer;
	char	*temp;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	*floor_value;
	char	*ceil_value;
	char	**array;
	char	**array_floor;
	char	**array_ceil;
	char	*temp_floor;
	char	*temp_ceil;
}	t_map;

typedef struct s_hero
{
	t_dir	dir;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	move_velocity;
	double	rotation_velocity;
}	t_hero;

typedef struct s_game
{
	t_hero			hero;
	t_map			map;
	t_color			color;
	t_img			img;
	t_img			array_texture[4];
	t_raycasting	raycast;
	t_line			line;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				screen_width;
	int				screen_height;
	int				key_state[6];
	char			*sub;
	char			*temp;
	char			*final;
	char			*join;
}	t_game;

// init
void			game_struct_init(t_game *game);
int				init_game(t_game *game);
void			init_hero(t_game *hero);
int				init_textures(t_game *game);
int				init_texture_img_data_addr(t_game *game, int i, char *dir_path);
void			set_hero_position(t_game *game);

// utils
int				init_key_state(t_game *game);
int				init_array_texture(t_game *game);
int				init_array_texture_mlx(t_game *game, int i);

// init map
void			map_struct_init(t_map *map);
int				init_map(t_game *game, t_map *map, char *argv);
int				valid_map(t_game *game, char **argv);

// check map
int				check_map_name(char *map_name);
int				check_map_hero(t_game *game, t_map *map);

// check map wall
int				check_map_wall(t_game *game, t_map *map);
int				check_map_duplicate(t_game *game, t_map *map);

// check ceil floor
int				check_map_ceil_floor(t_game *game, t_map *map);

// check map utils
int				is_comma(char *ceil, char *floor);
int				is_range(char **range);
int				is_only_spaces(char *str);
int				is_only_newline_or_empty(char *str);
int				parsing_spaces(t_map *map, int i, int j);

// read map
int				read_map(t_map *map, char *file_map);

// map utils 
int				get_nb_lines_map(t_map *map);
unsigned long	convert_rgb_in_hexa(int red, int green, int blue);
int				is_only_wall(char *str, int i);
int				is_newline_in_map(t_map *map, char *str);
int				get_id_start_newline(char *str, int i);
int				get_index_spaces(t_map *map, int i, int j);
int				get_index_spaces_str(char *str);
int				is_correct_line_map(char *str);
int				get_id_last_newline(char *str);
int				check_map_island(t_map *map, int i, int j);
int				get_id_start_map(t_map *map);
int				is_start_map(char *str);
int				update_one_end(t_game *game, t_map *map);

// raycasting
void			raycasting(t_game *game);
void			init_raycasting(t_game *game);
void			delta_dist(t_game *game);
void			perp_wall_dist(t_game *game);
void			ray_cast_out(t_game *game);
void			side_dist(t_game *game);

// draw wall
void			get_wall_height(t_game *game);
t_img			*get_texture(t_game *game);
void			get_wall_x(t_game *game);
void			calculate_texture(t_game *game, t_img *texture);
void			set_image_data(t_game *game, t_img *temp, t_img *texture);

// player
void			exec_rotate(t_game *game, double rotation);
int				key_press(int keycode, t_game *game);
int				is_wall(t_game *game, int new_map_pos_x, int new_map_pos_y);
int				key_release(int keycode, t_game *game);
int				game_loop(t_game *game);
int				update_hero_a_d(t_game *game, int x, int y);
int				update_hero_w_s(t_game *game, int x, int y);
void			update_keyboard_input(t_game *game);

// free
void			free_double_array(char **str);
void			free_all(t_game *game);
int				game_exit(t_game *game);
void			free_img_data_addr(t_game *game);
void			free_temp_and_array(t_map *map);

#endif