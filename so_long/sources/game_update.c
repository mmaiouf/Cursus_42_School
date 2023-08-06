/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:29:33 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/01 02:15:02 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	game_events_player(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->player_y = game->player_y - 1;
		update_player_w(game);
	}
	else if (keycode == KEY_A)
	{
		game->player_x = game->player_x - 1;
		update_player_a(game);
	}
	else if (keycode == KEY_S)
	{
		game->player_y = game->player_y + 1;
		update_player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->player_x = game->player_x + 1;
		update_player_d(game);
	}
	else if (keycode == KEY_Q)
		game_exit(game);
}

static void	game_events_mob(int keycode, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_mobs)
	{
		if (keycode == KEY_W)
		{
			game->mobs[i].mob_y = game->mobs[i].mob_y - 1;
			update_mob_w(game, i);
		}
		else if (keycode == KEY_S)
		{
			game->mobs[i].mob_y = game->mobs[i].mob_y + 1;
			update_mob_s(game, i);
		}
		i++;
	}
}

static void	game_events_mob2(int keycode, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nb_mobs)
	{
		if (keycode == KEY_A)
		{
			game->mobs[i].mob_x = game->mobs[i].mob_x - 1;
			update_mob_a(game, i);
		}
		else if (keycode == KEY_D)
		{
			game->mobs[i].mob_x = game->mobs[i].mob_x + 1;
			update_mob_d(game, i);
		}
		i++;
	}
}

static int	key_press(int keycode, t_game *game)
{
	game_events_player(keycode, game);
	if (check_is_mob(game->map))
	{
		game_events_mob(keycode, game);
		game_events_mob2(keycode, game);
	}
	update_movements(game);
	return (0);
}

void	game_update(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, game_exit, game);
}
