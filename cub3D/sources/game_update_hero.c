/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_hero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:29:22 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:18 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	exec_rotate(t_game *game, double rotate)
{
	double	temp_hero_x;
	double	temp_direction_x;

	temp_direction_x = game->hero.dir.x;
	temp_hero_x = game->hero.plane_x;
	game->hero.dir.x = temp_direction_x * cos(-rotate) - \
		game->hero.dir.y * sin(-rotate);
	game->hero.dir.y = temp_direction_x * sin(-rotate) + \
		game->hero.dir.y * cos(-rotate);
	game->hero.plane_x = temp_hero_x * cos(-rotate) - \
		game->hero.plane_y * sin(-rotate);
	game->hero.plane_y = temp_hero_x * sin(-rotate) + \
		game->hero.plane_y * cos(-rotate);
}

int	is_wall(t_game *game, int new_map_pos_x, int new_map_pos_y)
{
	if (game->map.array[new_map_pos_x][new_map_pos_y] != '0')
		return (1);
	return (0);
}

int	update_hero_a_d(t_game *game, int x, int y)
{
	double	temp_x;
	double	temp_y;

	temp_x = game->hero.pos_x + x * game->hero.dir.y
		* game->hero.move_velocity;
	temp_y = game->hero.pos_y + y * game->hero.dir.x
		* game->hero.move_velocity;
	if (is_wall(game, (int)(temp_x), (int)(temp_y)))
		return (-1);
	else
	{
		game->hero.pos_x = temp_x;
		game->hero.pos_y = temp_y;
	}
	return (0);
}

int	update_hero_w_s(t_game *game, int x, int y)
{
	double	temp_x;
	double	temp_y;

	temp_x = game->hero.pos_x + x
		* game->hero.dir.x * game->hero.move_velocity;
	temp_y = game->hero.pos_y + y
		* game->hero.dir.y * game->hero.move_velocity;
	if (is_wall(game, (int)(temp_x), (int)(temp_y)))
		return (-1);
	else
	{
		game->hero.pos_x = temp_x;
		game->hero.pos_y = temp_y;
	}
	return (0);
}

void	update_keyboard_input(t_game *game)
{
	if (game->key_state[ID_LEFT])
		exec_rotate(game, -ROTATION_VELOCITY);
	if (game->key_state[ID_RIGHT])
		exec_rotate(game, ROTATION_VELOCITY);
	if (game->key_state[ID_W])
		update_hero_w_s(game, 1, 1);
	if (game->key_state[ID_S])
		update_hero_w_s(game, -1, -1);
	if (game->key_state[ID_A])
		update_hero_a_d(game, -1, 1);
	if (game->key_state[ID_D])
		update_hero_a_d(game, 1, -1);
}
