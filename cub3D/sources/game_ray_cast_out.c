/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ray_cast_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:55:10 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:03 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	ray_cast_out(t_game *game)
{
	game->raycast.hit = 0;
	while (game->raycast.hit == 0)
	{
		if (game->raycast.side_dist_x < game->raycast.side_dist_y)
		{
			game->raycast.side_dist_x += game->raycast.delta_dist_x;
			game->raycast.map_x = game->raycast.map_x + game->raycast.step_x;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.side_dist_y += game->raycast.delta_dist_y;
			game->raycast.map_y = game->raycast.map_y + game->raycast.step_y;
			game->raycast.side = 1;
		}
		if (game->map.array[game->raycast.map_x][game->raycast.map_y] == '1')
			game->raycast.hit = 1;
	}
}
