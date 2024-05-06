/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:28:03 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:08 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static void	exec_raycasting(t_game *game, t_img *temp)
{
	t_img	*texture;

	update_keyboard_input(game);
	init_raycasting(game);
	delta_dist(game);
	side_dist(game);
	ray_cast_out(game);
	perp_wall_dist(game);
	get_wall_height(game);
	texture = get_texture(game);
	get_wall_x(game);
	calculate_texture(game, texture);
	set_image_data(game, temp, texture);
}

void	raycasting(t_game *game)
{
	t_img	temp;

	temp.endian = 0;
	temp.line_length = 0;
	temp.bits_per_pixel = 0;
	game->x = 0;
	temp.img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	temp.addr = (int *)mlx_get_data_addr(temp.img, &temp.bits_per_pixel,
			&temp.line_length, &temp.endian);
	while (game->x < game->screen_width)
	{
		exec_raycasting(game, &temp);
		game->x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, temp.img, 0, 0);
	mlx_destroy_image(game->mlx, temp.img);
}

int	game_loop(t_game *game)
{
	raycasting(game);
	return (0);
}
