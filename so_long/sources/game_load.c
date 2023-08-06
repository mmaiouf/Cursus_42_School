/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:50 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/02 16:17:03 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	init_img(t_game *game)
{
	game->img_grass = mlx_xpm_file_to_image
		(game->mlx, "assets/images/grass.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/images/wall.xpm", &game->img_w, &game->img_h);
	game->img_player_front = mlx_xpm_file_to_image
		(game->mlx, "assets/images/postman1.xpm", &game->img_w, &game->img_h);
	game->img_player_back = mlx_xpm_file_to_image
		(game->mlx, "assets/images/postman2.xpm", &game->img_w, &game->img_h);
	game->img_player_right = mlx_xpm_file_to_image
		(game->mlx, "assets/images/postman3.xpm", &game->img_w, &game->img_h);
	game->img_player_left = mlx_xpm_file_to_image
		(game->mlx, "assets/images/postman4.xpm", &game->img_w, &game->img_h);
	game->img_collect_right = mlx_xpm_file_to_image
		(game->mlx, "assets/images/envelope_right.xpm",
			&game->img_w, &game->img_h);
	game->img_collect_left = mlx_xpm_file_to_image
		(game->mlx, "assets/images/envelope_left.xpm",
			&game->img_w, &game->img_h);
	game->img_exit_close = mlx_xpm_file_to_image
		(game->mlx, "assets/images/boxletter.xpm", &game->img_w, &game->img_h);
	game->img_exit_open = mlx_xpm_file_to_image
		(game->mlx, "assets/images/boxletter_open.xpm",
			&game->img_w, &game->img_h);
	return (0);
}

static int	init_img_mobs(t_game *game)
{
	int	i;

	i = -1;
	game->img_mob_front = mlx_xpm_file_to_image
		(game->mlx, "assets/images/BryceFront.xpm", &game->img_w, &game->img_h);
	game->img_mob_back = mlx_xpm_file_to_image
		(game->mlx, "assets/images/BryceBack.xpm", &game->img_w, &game->img_h);
	game->img_mob_right = mlx_xpm_file_to_image
		(game->mlx, "assets/images/BryceRight.xpm", &game->img_w, &game->img_h);
	game->img_mob_left = mlx_xpm_file_to_image
		(game->mlx, "assets/images/BryceLeft.xpm", &game->img_w, &game->img_h);
	game->nb_mobs = check_nb_mob(game);
	if (game->nb_mobs > 0)
	{
		game->mobs = malloc(sizeof(t_mob) * game->nb_mobs);
		if (game->mobs == NULL)
			return (-1);
		while (++i < game->nb_mobs)
			game->mobs[i].img_mob = game->img_mob_front;
	}
	return (0);
}

static int	load_img(t_game *game)
{
	init_img(game);
	if (init_img_mobs(game) == -1)
		return (-1);
	return (0);
}

static void	set_win_size(t_game *game)
{
	int	nb_columns;
	int	nb_lines;

	nb_lines = 0;
	nb_columns = ft_strlen(game->map[0]);
	game->map_w = nb_columns * 64;
	while (game->map[nb_lines])
		nb_lines++;
	game->map_h = nb_lines * 64;
}

int	game_load(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	set_win_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	if (!game->win)
		return (mlx_destroy_display(game->mlx), 1);
	game->moves = 0;
	if (load_img(game) == -1)
		return (-1);
	game->img_player = game->img_player_front;
	game->img_exit = game->img_exit_close;
	game->img_collect = game->img_collect_left;
	draw_map(game);
	draw_map_mob(game);
	return (0);
}
