/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:11:16 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/01 02:16:03 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx_linux/mlx.h"
# include "../libs/Libft/libft.h"
# include <fcntl.h>

# define IS_NOT_RECTANGLE "Error\nYour map is not rectangle."
# define IS_NOT_WALLED "Error\nYour map is not walled."
# define IS_NOT_CEP "Error\nYour map contain missing or duplicate datas."
# define IS_NOT_VALID "Error\nYour map must contain only 0, 1, C, E, M and P."
# define IS_NOT_BER "Error\nYour map do not have extension .ber."
# define IS_NOT_SOLVABLE "Error\nYour map is unsolvable."
# define VICTORY_MSG "You won !"
# define DEFEAT_MSG "You lost !"

# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_mob
{
	int		mob_x;
	int		mob_y;
	void	*img_mob;
}	t_mob;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;

	void	*img_grass;
	void	*img_wall;

	void	*img_player;
	void	*img_player_front;
	void	*img_player_back;
	void	*img_player_right;
	void	*img_player_left;

	void	*img_mob_front;
	void	*img_mob_back;
	void	*img_mob_right;
	void	*img_mob_left;

	void	*img_exit;
	void	*img_exit_close;
	void	*img_exit_open;

	void	*img_collect;
	void	*img_collect_left;
	void	*img_collect_right;

	int		map_w;
	int		map_h;

	int		img_w;
	int		img_h;

	int		player_x;
	int		player_y;

	int		nb_collect;
	int		nb_player;
	int		nb_exit;

	int		moves;
	int		nb_mobs;
	t_mob	*mobs;
}	t_game;

int		check_is_map(t_game *game);
int		check_is_solvable(char *file);
int		check_is_mob(char **map);
int		check_nb_mob(t_game *game);
int		update_movements(t_game *game);
int		game_load(t_game *game);
int		game_exit(t_game *game);
int		draw_map(t_game *game);
int		draw_map_mob(t_game *game);
void	draw_img(t_game *game, void *image, int x, int y);
char	**read_map(char *file_map);
void	update_player_w(t_game *game);
void	update_player_a(t_game *game);
void	update_player_s(t_game *game);
void	update_player_d(t_game *game);
void	update_mob_w(t_game *game, int i);
void	update_mob_a(t_game *game, int i);
void	update_mob_s(t_game *game, int i);
void	update_mob_d(t_game *game, int i);
void	game_update(t_game *game);
void	free_map(char **map);
void	draw_mob(t_game *game, int x, int y, int mob_index);

#endif