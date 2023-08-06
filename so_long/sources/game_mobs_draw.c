/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mobs_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:10:36 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/01 02:15:26 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_mob(t_game *game, int x, int y, int mob_index)
{
	game->mobs[mob_index].mob_x = x;
	game->mobs[mob_index].mob_y = y;
}

int	draw_map_mob(t_game *game)
{
	int	x;
	int	y;
	int	m;

	y = 0;
	m = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'M')
			{
				draw_mob(game, x, y, m);
				draw_img(game, game->mobs[m].img_mob, x, y);
				m++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
