/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:00:25 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/01 02:15:35 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_img(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

static void	draw_player(t_game *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	draw_img(game, image, x, y);
}

static void	draw_exit(t_game *game, int x, int y)
{
	if (game->nb_collect == 0)
		game->img_exit = game->img_exit_open;
	draw_img(game, game->img_exit, x, y);
}

static void	draw_letter(t_game *game, int x, int y)
{
	if ((game->moves % 2) == 0)
		game->img_collect = game->img_collect_left;
	else
		game->img_collect = game->img_collect_right;
	draw_img(game, game->img_collect, x, y);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				draw_img(game, game->img_grass, x, y);
			else if (game->map[y][x] == '1')
				draw_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				draw_letter(game, x, y);
			else if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
		}
	}
	return (0);
}
