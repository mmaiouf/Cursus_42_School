/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:22:46 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/07/30 15:32:30 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	update_player_image(char key, t_game *game)
{
	if (key == 'w')
		game->img_player = game->img_player_back;
	else if (key == 'a')
		game->img_player = game->img_player_left;
	else if (key == 's')
		game->img_player = game->img_player_front;
	else if (key == 'd')
		game->img_player = game->img_player_right;
}

void	update_player_w(t_game *game)
{
	update_player_image('w', game);
	if (((game->map[game->player_y][game->player_x] == 'E')
		&& (game->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY_MSG, 1);
		game_exit(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1')
		|| (game->map[game->player_y][game->player_x] == 'E'))
		game->player_y = game->player_y + 1;
	else
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->nb_collect = game->nb_collect - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	update_player_a(t_game *game)
{
	update_player_image('a', game);
	if (((game->map[game->player_y][game->player_x] == 'E')
		&& (game->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY_MSG, 1);
		game_exit(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1')
		|| (game->map[game->player_y][game->player_x] == 'E'))
		game->player_x = game->player_x + 1;
	else
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->nb_collect = game->nb_collect - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	update_player_s(t_game *game)
{
	update_player_image('s', game);
	if (((game->map[game->player_y][game->player_x] == 'E')
		&& (game->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY_MSG, 1);
		game_exit(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1')
		|| (game->map[game->player_y][game->player_x] == 'E'))
		game->player_y = game->player_y - 1;
	else
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->nb_collect = game->nb_collect - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	update_player_d(t_game *game)
{
	update_player_image('d', game);
	if (((game->map[game->player_y][game->player_x] == 'E')
		&& (game->nb_collect == 0)))
	{
		ft_putendl_fd(VICTORY_MSG, 1);
		game_exit(game);
	}
	else if (game->map[game->player_y][game->player_x] == 'M')
	{
		ft_putendl_fd(DEFEAT_MSG, 1);
		game_exit(game);
	}
	else if ((game->map[game->player_y][game->player_x] == '1')
		|| (game->map[game->player_y][game->player_x] == 'E'))
		game->player_x = game->player_x - 1;
	else
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->nb_collect = game->nb_collect - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
