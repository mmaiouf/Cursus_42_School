/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:01:17 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:42 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	perp_wall_dist(t_game *game)
{
	if (game->raycast.side == 0)
	{
		game->raycast.perp_wall_dist = (game->raycast.map_x - game->hero.pos_x
				+ (1 - game->raycast.step_x) / 2) / game->raycast.raydir_x;
	}
	else
	{
		game->raycast.perp_wall_dist = (game->raycast.map_y - game->hero.pos_y
				+ (1 - game->raycast.step_y) / 2) / game->raycast.raydir_y;
	}
}

void	side_dist(t_game *game)
{
	if (game->raycast.raydir_x < 0)
	{
		game->raycast.step_x = -1;
		game->raycast.side_dist_x = (game->hero.pos_x - game->raycast.map_x)
			* game->raycast.delta_dist_x;
	}
	else if (game->raycast.raydir_x >= 0)
	{
		game->raycast.step_x = 1;
		game->raycast.side_dist_x = (game->raycast.map_x + 1.0
				- game->hero.pos_x) * game->raycast.delta_dist_x;
	}
	if (game->raycast.raydir_y < 0)
	{
		game->raycast.step_y = -1;
		game->raycast.side_dist_y = (game->hero.pos_y - game->raycast.map_y)
			* game->raycast.delta_dist_y;
	}
	else if (game->raycast.raydir_y >= 0)
	{
		game->raycast.step_y = 1;
		game->raycast.side_dist_y = (game->raycast.map_y + 1.0
				- game->hero.pos_y) * game->raycast.delta_dist_y;
	}
}

void	delta_dist(t_game *game)
{
	if (game->raycast.raydir_y == 0)
		game->raycast.delta_dist_x = 0;
	else
	{
		if (game->raycast.raydir_x == 0)
			game->raycast.delta_dist_x = 1;
		else
			game->raycast.delta_dist_x = fabs(1 / game->raycast.raydir_x);
	}
	if (game->raycast.raydir_x == 0)
		game->raycast.delta_dist_y = 0;
	else
	{
		if (game->raycast.raydir_y == 0)
			game->raycast.delta_dist_y = 1;
		else
			game->raycast.delta_dist_y = fabs(1 / game->raycast.raydir_y);
	}
}

void	init_raycasting(t_game *game)
{
	game->raycast.camera_x = (2 * game->x / (double)game->screen_width) - 1;
	game->raycast.raydir_x = game->hero.dir.x + game->hero.plane_x * \
		game->raycast.camera_x;
	game->raycast.raydir_y = game->hero.dir.y + game->hero.plane_y * \
		game->raycast.camera_x;
	game->raycast.map_x = (int)game->hero.pos_x;
	game->raycast.map_y = (int)game->hero.pos_y;
}
