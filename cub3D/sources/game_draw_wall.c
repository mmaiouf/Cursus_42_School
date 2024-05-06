/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:17:13 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:07 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	set_image_data(t_game *game, t_img *temp, t_img *texture)
{
	int			y;
	long int	color;

	y = -1;
	while (++y < game->screen_height)
	{
		if (y < game->line.start)
			temp->addr[y * game->screen_width + game->x] = game->color.ceil;
		else if (y >= game->line.start && y <= game->line.end)
		{
			game->raycast.texture_y = (int)game->raycast.texture_pos
				& (texture->height - 1);
			game->raycast.texture_pos += game->raycast.step;
			color = texture->addr[game->raycast.texture_y
				* texture->height + game->raycast.texture_x];
			temp->addr[y * game->screen_width + game->x] = color;
		}
		else if (y < game->screen_height)
			temp->addr[y * game->screen_width + game->x] = game->color.floor;
	}
}

void	calculate_texture(t_game *game, t_img *texture)
{
	game->raycast.texture_x = (int)(game->raycast.wall_x
			* (double)texture->width);
	if (game->raycast.side == 0 && game->raycast.raydir_x > 0)
		game->raycast.texture_x = texture->width - game->raycast.texture_x - 1;
	if (game->raycast.side == 1 && game->raycast.raydir_y < 0)
		game->raycast.texture_x = texture->width - game->raycast.texture_x - 1;
	game->raycast.step = 1.0 * (double)texture->height
		/ (double)game->line.height;
	game->raycast.texture_pos = (double)(game->line.start - \
			game->screen_height / 2 + game->line.height / 2) * \
		game->raycast.step;
}

void	get_wall_x(t_game *game)
{
	if (game->raycast.side == 0)
		game->raycast.wall_x = game->hero.pos_y + game->raycast.perp_wall_dist
			* game->raycast.raydir_y;
	else
		game->raycast.wall_x = game->hero.pos_x + game->raycast.perp_wall_dist
			* game->raycast.raydir_x;
	game->raycast.wall_x = game->raycast.wall_x - floor(game->raycast.wall_x);
}

void	get_wall_height(t_game *game)
{
	game->line.height = (int)(game->screen_height / \
			game->raycast.perp_wall_dist);
	game->line.start = (-1 * game->line.height / 2) + (game->screen_height / 2);
	if (game->line.start < 0)
		game->line.start = 0;
	game->line.end = (game->line.height) / 2 + (game->screen_height / 2);
	if (game->line.end >= game->screen_height)
		game->line.end = game->screen_height - 1;
}
