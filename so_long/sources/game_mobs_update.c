/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mobs_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:17:07 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/02 16:16:59 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	update_mob_image(char key, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_mobs)
	{
		if (key == 'w')
			game->mobs[i].img_mob = game->img_mob_back;
		else if (key == 'a')
			game->mobs[i].img_mob = game->img_mob_left;
		else if (key == 's')
			game->mobs[i].img_mob = game->img_mob_front;
		else if (key == 'd')
			game->mobs[i].img_mob = game->img_mob_right;
		i++;
	}
}

void	update_mob_w(t_game *game, int i)
{
	update_mob_image('w', game);
	if ((game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == '1')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'E')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'C')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'M'))
		game->mobs[i].mob_y = game->mobs[i].mob_y + 1;
	else if (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else
	{
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] = 'M';
		game->map[game->mobs[i].mob_y + 1][game->mobs[i].mob_x] = '0';
	}
	draw_map(game);
	draw_map_mob(game);
}

void	update_mob_a(t_game *game, int i)
{
	update_mob_image('a', game);
	if ((game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == '1')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'E')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'C')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'M'))
		game->mobs[i].mob_x = game->mobs[i].mob_x + 1;
	else if (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else
	{
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] = 'M';
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x + 1] = '0';
	}
	draw_map(game);
	draw_map_mob(game);
}

void	update_mob_s(t_game *game, int i)
{
	update_mob_image('s', game);
	if ((game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == '1')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'E')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'C')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'M'))
		game->mobs[i].mob_y = game->mobs[i].mob_y - 1;
	else if (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else
	{
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] = 'M';
		game->map[game->mobs[i].mob_y - 1][game->mobs[i].mob_x] = '0';
	}
	draw_map(game);
	draw_map_mob(game);
}

void	update_mob_d(t_game *game, int i)
{
	update_mob_image('d', game);
	if ((game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == '1')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'E')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'C')
		|| (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'M'))
		game->mobs[i].mob_x = game->mobs[i].mob_x - 1;
	else if (game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] == 'P')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else
	{
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x] = 'M';
		game->map[game->mobs[i].mob_y][game->mobs[i].mob_x - 1] = '0';
	}
	draw_map(game);
	draw_map_mob(game);
}
