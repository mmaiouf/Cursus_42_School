/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:44:41 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:12 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	destroy_img(t_game *game)
{
	if (game->array_texture[0].img)
		mlx_destroy_image(game->mlx, game->array_texture[0].img);
	if (game->array_texture[1].img)
		mlx_destroy_image(game->mlx, game->array_texture[1].img);
	if (game->array_texture[2].img)
		mlx_destroy_image(game->mlx, game->array_texture[2].img);
	if (game->array_texture[3].img)
		mlx_destroy_image(game->mlx, game->array_texture[3].img);
	return (0);
}

int	game_exit(t_game *game)
{
	destroy_img(game);
	free_all(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
